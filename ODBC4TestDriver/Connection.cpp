#include "Globals.h"

SQLRETURN  SQL_API SQLConnect(SQLHDBC ConnectionHandle,
    _In_reads_(NameLength1) SQLCHAR *ServerName, SQLSMALLINT NameLength1,
    _In_reads_(NameLength2) SQLCHAR *UserName, SQLSMALLINT NameLength2,
    _In_reads_(NameLength3) SQLCHAR *Authentication, SQLSMALLINT NameLength3)
{
    TestTrace(TEXT("SQLConnect not implemented."));
    return SQL_ERROR;
}

SQLRETURN SQL_API SQLBrowseConnect(
    SQLHDBC            hdbc,
    _In_reads_(cchConnStrIn)
    SQLCHAR           *szConnStrIn,
    SQLSMALLINT        cchConnStrIn,
    _Out_writes_opt_(cchConnStrOutMax)
    SQLCHAR           *szConnStrOut,
    SQLSMALLINT        cchConnStrOutMax,
    _Out_opt_
    SQLSMALLINT       *pcchConnStrOut)
{
    TestTrace(TEXT("SQLBrowseConnect not implemented"));
    return SQL_ERROR;
}

SQLRETURN  SQL_API SQLDisconnect(SQLHDBC ConnectionHandle)
{
    return SQL_SUCCESS;
}

SQLRETURN SQL_API SQLDriverConnect(
    SQLHDBC            hdbc,
    SQLHWND            hwnd,
    _In_reads_(cchConnStrIn)
    SQLCHAR           *szConnStrIn,
    SQLSMALLINT        cchConnStrIn,
    _Out_writes_opt_(cchConnStrOutMax)
    SQLCHAR           *szConnStrOut,
    SQLSMALLINT        cchConnStrOutMax,
    _Out_opt_
    SQLSMALLINT       *pcchConnStrOut,
    SQLUSMALLINT       fDriverCompletion)
{
    try
    {
        DbcStruct *dbc = (DbcStruct *)hdbc;
        dbc->conf = new DocumentDBConfiguration(MakeWide("https://localhost:8081/")->c_str(),
            MakeWide("C2y6yDjf5/R+ob0N8A7Cgv30VRDJIWEHLM+4QDU5DE2nQ9nDuVTqobD4b8mGGyPMbIZnqyMsEcaGQy67XIw/Jw==")->c_str());
        dbc->client = new DocumentClient(*(dbc->conf));

        // Currently hard-coded to connect to from Data Base "test1" and Collection "collection1"

        // Get the Database
        wstring resourceId {};
        auto databases = dbc->client->ListDatabases();
        
        for (auto db : databases)
        {
            if (db->id() == *MakeWide("test1"))
            {
                resourceId = db->resource_id();
                break;
            }
        }
        if (resourceId.length() == 0)
        {
            return SQL_ERROR;
        }
        dbc->database = dbc->client->GetDatabase(resourceId);

        // Get the Collection
        auto collections = dbc->database->ListCollections();
        resourceId = wstring();
        for (auto col : collections)
        {
            if (col->id() == *MakeWide("collection1"))
            {
                resourceId = col->resource_id();
                break;
            }
        }
        if (resourceId.length() == 0)
        {
            return SQL_ERROR;
        }
        dbc->collection = dbc->database->GetCollection(resourceId);
    }
    catch (DocumentDBRuntimeException e)
    {
        return SQL_ERROR;
    }

    fDriverCompletion = SQL_DRIVER_COMPLETE;
    if (szConnStrOut && cchConnStrOutMax > 0 && pcchConnStrOut)
    {
        _tcscpy_s((_TCHAR *)szConnStrOut, cchConnStrOutMax, (_TCHAR *)szConnStrIn);
        *pcchConnStrOut = (SQLSMALLINT)_tcsnlen((_TCHAR *)szConnStrOut, cchConnStrOutMax);
    }

    return SQL_SUCCESS;
}

SQLRETURN  SQL_API SQLFreeConnect(SQLHDBC ConnectionHandle)
{
    TestTrace(TEXT("SQLFreeConnect not implemented"));
    return SQL_ERROR;
}

SQLRETURN  SQL_API SQLGetConnectAttr(SQLHDBC ConnectionHandle,
    SQLINTEGER Attribute, _Out_writes_opt_(_Inexpressible_(BufferLength)) SQLPOINTER Value,
    SQLINTEGER BufferLength, _Out_opt_ SQLINTEGER *StringLengthPtr)
{
    TestTrace(TEXT("SQLGetConnectAttr not implemented"));
    return SQL_ERROR;
}

_Success_(return == SQL_SUCCESS)
SQLRETURN  SQL_API SQLGetInfo(SQLHDBC ConnectionHandle,
    SQLUSMALLINT InfoType, _Out_writes_bytes_opt_(BufferLength) SQLPOINTER InfoValue,
    SQLSMALLINT BufferLength, _Out_opt_ SQLSMALLINT *StringLengthPtr)
{
    switch (InfoType)
    {
    case SQL_DRIVER_ODBC_VER:
        _tcscpy_s((TCHAR*)InfoValue, BufferLength / sizeof(TCHAR), TEXT(SQL_SPEC_STRING));
        *StringLengthPtr = (sizeof(InfoValue) + 1) * sizeof(TCHAR);
        break;
    case SQL_ASYNC_DBC_FUNCTIONS:
        *(SQLINTEGER*)InfoValue = 0;
        break;
    case SQL_ASYNC_NOTIFICATION:
        *(SQLINTEGER*)InfoValue = SQL_ASYNC_NOTIFICATION_NOT_CAPABLE;
        break;
    case SQL_GETDATA_EXTENSIONS:
        *(SQLINTEGER*)InfoValue = SQL_GD_ANY_COLUMN & SQL_GD_ANY_ORDER;
        break;
    case SQL_CURSOR_COMMIT_BEHAVIOR:
    case SQL_CURSOR_ROLLBACK_BEHAVIOR:
        return SQL_ERROR;
    default:
        TestTrace(TEXT("SQLGetInfo not implemented for this case"));
        return SQL_ERROR;
    }
    return SQL_SUCCESS;
}

SQLRETURN SQL_API SQLNativeSql
(
    SQLHDBC            hdbc,
    _In_reads_(cchSqlStrIn) SQLCHAR* szSqlStrIn,
    SQLINTEGER  cchSqlStrIn,
    _Out_writes_opt_(cchSqlStrMax) SQLCHAR* szSqlStr,
    SQLINTEGER         cchSqlStrMax,
    SQLINTEGER        *pcbSqlStr
)
{
    TestTrace(TEXT("SQLNativeSql not implemented"));
    return SQL_ERROR;
}

SQLRETURN  SQL_API SQLSetConnectAttr(SQLHDBC ConnectionHandle,
    SQLINTEGER Attribute, _In_reads_bytes_opt_(StringLength) SQLPOINTER Value,
    SQLINTEGER StringLength)
{
    switch (Attribute)
    {
    case SQL_ATTR_ANSI_APP:
        ((DbcStruct*)ConnectionHandle)->ansiApp = (SQLINTEGER)Value;
        return SQL_SUCCESS;
    default:
        TestTrace(TEXT("SQLSetConnectAttr not implemented"));
        return SQL_ERROR;
    }
}

SQLRETURN  SQL_API SQLTransact(SQLHENV EnvironmentHandle,
    SQLHDBC ConnectionHandle, SQLUSMALLINT CompletionType)
{
    TestTrace(TEXT("SQLTransact not implemented"));
    return SQL_ERROR;
}