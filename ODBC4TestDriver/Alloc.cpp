#include "windows.h"
#include "sqlext.h"

SQLRETURN  SQL_API SQLAllocEnv(_Out_ SQLHENV *EnvironmentHandle)
{
    MessageBox(GetDesktopWindow(), TEXT("Not Implemented"), NULL, MB_OK);
    return SQL_ERROR;
}

SQLRETURN  SQL_API SQLAllocStmt(SQLHDBC ConnectionHandle,
    _Out_ SQLHSTMT *StatementHandle)
{
    MessageBox(GetDesktopWindow(), TEXT("Not Implemented"), NULL, MB_OK);
    return SQL_ERROR;
}

SQLRETURN  SQL_API SQLAllocHandle(SQLSMALLINT HandleType,
    SQLHANDLE InputHandle, _Out_ SQLHANDLE *OutputHandle)
{
    MessageBox(GetDesktopWindow(), TEXT("Not Implemented"), NULL, MB_OK);
    return SQL_ERROR;
}