#include "Globals.h"

SQLRETURN  SQL_API SQLAllocEnv(_Out_ SQLHENV *EnvironmentHandle)
{
    return SQLAllocHandle(SQL_HANDLE_ENV, NULL, EnvironmentHandle);
}

SQLRETURN  SQL_API SQLAllocStmt(SQLHDBC ConnectionHandle,
    _Out_ SQLHSTMT *StatementHandle)
{
    return SQLAllocHandle(SQL_HANDLE_STMT, ConnectionHandle, StatementHandle);
}

SQLRETURN  SQL_API SQLAllocHandle(SQLSMALLINT HandleType,
    SQLHANDLE InputHandle, _Out_ SQLHANDLE *OutputHandle)
{
    switch (HandleType)
    {
    case SQL_HANDLE_DBC:
        *OutputHandle = new DbcStruct;
        return SQL_SUCCESS;
    case SQL_HANDLE_ENV:
        *OutputHandle = new EnvStruct;
        return SQL_SUCCESS;
    default:
        MessageBox(GetDesktopWindow(), TEXT("Not Implemented"), NULL, MB_OK);
        return SQL_ERROR;
    }
}