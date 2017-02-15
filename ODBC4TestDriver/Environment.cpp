#include "Globals.h"

SQLRETURN  SQL_API SQLDataSources(SQLHENV EnvironmentHandle,
    SQLUSMALLINT Direction, _Out_writes_opt_(BufferLength1) SQLCHAR *ServerName,
    SQLSMALLINT BufferLength1, _Out_opt_ SQLSMALLINT *NameLength1Ptr,
    _Out_writes_opt_(BufferLength2) SQLCHAR *Description, SQLSMALLINT BufferLength2,
    _Out_opt_ SQLSMALLINT *NameLength2Ptr)
{
    TestTrace(TEXT("SQLDataSources not implemented"));
    return SQL_ERROR;
}

SQLRETURN  SQL_API SQLFreeEnv(SQLHENV EnvironmentHandle)
{
    TestTrace(TEXT("SQLFreeEnv not implemented"));
    return SQL_ERROR;
}

SQLRETURN  SQL_API SQLGetEnvAttr(SQLHENV EnvironmentHandle,
    SQLINTEGER Attribute, _Out_writes_(_Inexpressible_(BufferLength)) SQLPOINTER Value,
    SQLINTEGER BufferLength, _Out_opt_ SQLINTEGER *StringLength)
{
    TestTrace(TEXT("SQLGetEnvAttr not implemented"));
    return SQL_ERROR;
}

SQLRETURN  SQL_API SQLSetEnvAttr(SQLHENV EnvironmentHandle,
    SQLINTEGER Attribute, _In_reads_bytes_opt_(StringLength) SQLPOINTER Value,
    SQLINTEGER StringLength)
{
    return SQL_SUCCESS;
}