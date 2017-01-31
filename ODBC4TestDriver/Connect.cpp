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
    /*DbcStruct *dbc = (DbcStruct *)hdbc;
    dbc->conf = new DocumentDBConfiguration(TEXT("https://localhost:8081"), TEXT("C2y6yDjf5/R+ob0N8A7Cgv30VRDJIWEHLM+4QDU5DE2nQ9nDuVTqobD4b8mGGyPMbIZnqyMsEcaGQy67XIw/Jw=="));
    dbc->client =  new DocumentClient(*((DbcStruct*)dbc)->conf);
    fDriverCompletion = SQL_DRIVER_COMPLETE;*/

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
    MessageBox(GetDesktopWindow(), TEXT("Not Implemented"), NULL, MB_OK);
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
    MessageBox(GetDesktopWindow(), TEXT("Not Implemented"), NULL, MB_OK);
    return SQL_ERROR;
}