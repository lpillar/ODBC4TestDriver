#include "Globals.h"

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
        *pcchConnStrOut = _tcsnlen((_TCHAR *)szConnStrOut, cchConnStrOutMax);
    }

    return SQL_SUCCESS;
}

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