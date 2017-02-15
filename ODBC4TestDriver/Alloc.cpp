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
    case SQL_HANDLE_STMT:
        *OutputHandle = new StmtStruct;
        ((StmtStruct*)(*OutputHandle))->dbc = (DbcStruct*)InputHandle;
        ((StmtStruct*)(*OutputHandle))->ard = new ARDStruct;
        ((StmtStruct*)(*OutputHandle))->apd = new APDStruct;
        ((StmtStruct*)(*OutputHandle))->ird = new IRDStruct;
        ((StmtStruct*)(*OutputHandle))->ird->columns.reset(new vector<tuple<ColumnType, string, string>>);
        ((StmtStruct*)(*OutputHandle))->ird->columns->push_back(make_tuple<ColumnType, string, string>(str, "Bookmark", "Bookmark"));
        ((StmtStruct*)(*OutputHandle))->ird->firstNewColumn = 1;
        ((StmtStruct*)(*OutputHandle))->ipd = new IPDStruct;
        return SQL_SUCCESS;
    default:
        MessageBox(GetDesktopWindow(), TEXT("Not Implemented"), NULL, MB_OK);
        return SQL_ERROR;
    }
}

SQLRETURN  SQL_API SQLFreeHandle(SQLSMALLINT HandleType, SQLHANDLE Handle)
{
    switch (HandleType)
    {
    case SQL_HANDLE_DBC:
        delete (DbcStruct *)Handle;
        return SQL_SUCCESS;
    case SQL_HANDLE_ENV:
        delete (EnvStruct *)Handle;
        return SQL_SUCCESS;
    case SQL_HANDLE_STMT:
        delete (StmtStruct *)Handle;
        return SQL_SUCCESS;
    default:
        TestTrace(TEXT("SQLFreeHandle not implemented"));
        return SQL_ERROR;
    }
}