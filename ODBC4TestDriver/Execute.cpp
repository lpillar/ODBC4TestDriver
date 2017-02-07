#include "Globals.h"

SQLRETURN  SQL_API SQLExecDirect
(
    SQLHSTMT StatementHandle,
    _In_reads_opt_(TextLength) SQLCHAR* StatementText,
    SQLINTEGER TextLength
)
{
    StmtStruct *stmt = (StmtStruct*)StatementHandle;
    stmt->statement = MakeWide((char*)StatementText);
    try
    {
        stmt->iter = stmt->dbc->collection->QueryDocuments(*(stmt->statement));
    }
    catch (DocumentDBRuntimeException e)
    {
        return SQL_ERROR;
    }
    return SQL_SUCCESS;
}

SQLRETURN  SQL_API SQLExecute(SQLHSTMT StatementHandle)
{
    TestTrace(TEXT("SQLExecute not implemented"));
    return SQL_ERROR;
}