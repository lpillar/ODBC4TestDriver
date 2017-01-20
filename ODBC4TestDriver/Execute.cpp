#include "windows.h"
#include "sqlext.h"

SQLRETURN  SQL_API SQLExecDirect
(
    SQLHSTMT StatementHandle,
    _In_reads_opt_(TextLength) SQLCHAR* StatementText,
    SQLINTEGER TextLength
)
{
    MessageBox(GetDesktopWindow(), TEXT("Not Implemented"), NULL, MB_OK);
    return SQL_ERROR;
}

SQLRETURN  SQL_API SQLExecute(SQLHSTMT StatementHandle)
{
    MessageBox(GetDesktopWindow(), TEXT("Not Implemented"), NULL, MB_OK);
    return SQL_ERROR;
}