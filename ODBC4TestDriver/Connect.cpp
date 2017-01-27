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
    //HandleDbc *newHandle = (HandleDbc*)hdbc;
    //newHandle->conf = new DocumentDBConfiguration(TEXT("https://localhost:8081"), TEXT("C2y6yDjf5/R+ob0N8A7Cgv30VRDJIWEHLM+4QDU5DE2nQ9nDuVTqobD4b8mGGyPMbIZnqyMsEcaGQy67XIw/Jw=="));
    //newHandle->client =  new DocumentClient(*((HandleDbc*)hdbc)->conf);
    //fDriverCompletion = SQL_DRIVER_COMPLETE;

    if (szConnStrOut && pcchConnStrOut > 0)
    {
        _tcscpy_s((SQLTCHAR *)szConnStrOut, cchConnStrIn, (SQLTCHAR *)szConnStrIn);
        if (pcchConnStrOut)
        {
            *pcchConnStrOut = cchConnStrIn;
        }
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