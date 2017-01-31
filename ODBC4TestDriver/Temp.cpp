#include "Globals.h"

SQLRETURN  SQL_API SQLBindCol(SQLHSTMT StatementHandle,
    SQLUSMALLINT ColumnNumber, SQLSMALLINT TargetType,
    _Inout_updates_opt_(_Inexpressible_(BufferLength)) SQLPOINTER TargetValue,
    SQLLEN BufferLength, _Inout_opt_ SQLLEN *StrLen_or_Ind)
{
    MessageBox(GetDesktopWindow(), TEXT("Not Implemented"), NULL, MB_OK);
    return SQL_ERROR;
}

SQLRETURN  SQL_API SQLCancel(SQLHSTMT StatementHandle)
{
    MessageBox(GetDesktopWindow(), TEXT("Not Implemented"), NULL, MB_OK);
    return SQL_ERROR;
}

SQLRETURN  SQL_API SQLDescribeCol(SQLHSTMT StatementHandle,
    SQLUSMALLINT ColumnNumber, _Out_writes_opt_(BufferLength) SQLCHAR *ColumnName,
    SQLSMALLINT BufferLength, _Out_opt_ SQLSMALLINT *NameLength,
    _Out_opt_ SQLSMALLINT *DataType, _Out_opt_ SQLULEN *ColumnSize,
    _Out_opt_ SQLSMALLINT *DecimalDigits, _Out_opt_ SQLSMALLINT *Nullable)
{
    MessageBox(GetDesktopWindow(), TEXT("Not Implemented"), NULL, MB_OK);
    return SQL_ERROR;
}

SQLRETURN  SQL_API SQLDisconnect(SQLHDBC ConnectionHandle)
{
    return SQL_SUCCESS;
}

SQLRETURN  SQL_API SQLError(SQLHENV EnvironmentHandle,
    SQLHDBC ConnectionHandle, SQLHSTMT StatementHandle,
    _Out_writes_(6) SQLCHAR *Sqlstate, _Out_opt_ SQLINTEGER *NativeError,
    _Out_writes_opt_(BufferLength) SQLCHAR *MessageText, SQLSMALLINT BufferLength,
    _Out_opt_ SQLSMALLINT *TextLength)
{
    MessageBox(GetDesktopWindow(), TEXT("Not Implemented"), NULL, MB_OK);
    return SQL_ERROR;
}

SQLRETURN  SQL_API SQLFetch(SQLHSTMT StatementHandle)
{
    MessageBox(GetDesktopWindow(), TEXT("Not Implemented"), NULL, MB_OK);
    return SQL_ERROR;
}

SQLRETURN  SQL_API SQLFreeConnect(SQLHDBC ConnectionHandle)
{
    MessageBox(GetDesktopWindow(), TEXT("Not Implemented"), NULL, MB_OK);
    return SQL_ERROR;
}

SQLRETURN  SQL_API SQLFreeEnv(SQLHENV EnvironmentHandle)
{
    MessageBox(GetDesktopWindow(), TEXT("Not Implemented"), NULL, MB_OK);
    return SQL_ERROR;
}

SQLRETURN  SQL_API SQLCancelHandle(SQLSMALLINT HandleType, SQLHANDLE InputHandle)
{
    MessageBox(GetDesktopWindow(), TEXT("Not Implemented"), NULL, MB_OK);
    return SQL_ERROR;
}

SQLRETURN  SQL_API SQLCloseCursor(SQLHSTMT StatementHandle)
{
    MessageBox(GetDesktopWindow(), TEXT("Not Implemented"), NULL, MB_OK);
    return SQL_ERROR;
}

SQLRETURN  SQL_API SQLColAttribute(SQLHSTMT StatementHandle,
    SQLUSMALLINT ColumnNumber, SQLUSMALLINT FieldIdentifier,
    _Out_writes_bytes_opt_(BufferLength) SQLPOINTER CharacterAttribute, SQLSMALLINT BufferLength,
    _Out_opt_ SQLSMALLINT *StringLength, _Out_opt_ SQLPOINTER NumericAttribute)
{
    MessageBox(GetDesktopWindow(), TEXT("Not Implemented"), NULL, MB_OK);
    return SQL_ERROR;
}

SQLRETURN  SQL_API SQLColumns(SQLHSTMT StatementHandle,
    _In_reads_opt_(NameLength1) SQLCHAR *CatalogName, SQLSMALLINT NameLength1,
    _In_reads_opt_(NameLength2) SQLCHAR *SchemaName, SQLSMALLINT NameLength2,
    _In_reads_opt_(NameLength3) SQLCHAR *TableName, SQLSMALLINT NameLength3,
    _In_reads_opt_(NameLength4) SQLCHAR *ColumnName, SQLSMALLINT NameLength4)
{
    MessageBox(GetDesktopWindow(), TEXT("Not Implemented"), NULL, MB_OK);
    return SQL_ERROR;
}

SQLRETURN SQL_API SQLCompleteAsync(SQLSMALLINT    HandleType,
    SQLHANDLE      Handle,
    _Out_ RETCODE* AsyncRetCodePtr)
{
    MessageBox(GetDesktopWindow(), TEXT("Not Implemented"), NULL, MB_OK);
    return SQL_ERROR;
}

SQLRETURN  SQL_API SQLCopyDesc(SQLHDESC SourceDescHandle,
    SQLHDESC TargetDescHandle)
{
    MessageBox(GetDesktopWindow(), TEXT("Not Implemented"), NULL, MB_OK);
    return SQL_ERROR;
}

SQLRETURN  SQL_API SQLDataSources(SQLHENV EnvironmentHandle,
    SQLUSMALLINT Direction, _Out_writes_opt_(BufferLength1) SQLCHAR *ServerName,
    SQLSMALLINT BufferLength1, _Out_opt_ SQLSMALLINT *NameLength1Ptr,
    _Out_writes_opt_(BufferLength2) SQLCHAR *Description, SQLSMALLINT BufferLength2,
    _Out_opt_ SQLSMALLINT *NameLength2Ptr)
{
    MessageBox(GetDesktopWindow(), TEXT("Not Implemented"), NULL, MB_OK);
    return SQL_ERROR;
}


SQLRETURN  SQL_API SQLEndTran(SQLSMALLINT HandleType, SQLHANDLE Handle,
    SQLSMALLINT CompletionType)
{
    MessageBox(GetDesktopWindow(), TEXT("Not Implemented"), NULL, MB_OK);
    return SQL_ERROR;
}

SQLRETURN  SQL_API SQLFetchScroll(SQLHSTMT StatementHandle,
    SQLSMALLINT FetchOrientation, SQLLEN FetchOffset)
{
    MessageBox(GetDesktopWindow(), TEXT("Not Implemented"), NULL, MB_OK);
    return SQL_ERROR;
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
    default:
        MessageBox(GetDesktopWindow(), TEXT("Not Implemented"), NULL, MB_OK);
        return SQL_ERROR;
    }
}

SQLRETURN  SQL_API SQLFreeStmt(SQLHSTMT StatementHandle,
    SQLUSMALLINT Option)
{
    MessageBox(GetDesktopWindow(), TEXT("Not Implemented"), NULL, MB_OK);
    return SQL_ERROR;
}

SQLRETURN  SQL_API SQLGetConnectAttr(SQLHDBC ConnectionHandle,
    SQLINTEGER Attribute, _Out_writes_opt_(_Inexpressible_(BufferLength)) SQLPOINTER Value,
    SQLINTEGER BufferLength, _Out_opt_ SQLINTEGER *StringLengthPtr)
{
    MessageBox(GetDesktopWindow(), TEXT("Not Implemented"), NULL, MB_OK);
    return SQL_ERROR;
}

SQLRETURN  SQL_API SQLGetCursorName
(
    SQLHSTMT StatementHandle,
    _Out_writes_opt_(BufferLength) SQLCHAR *CursorName,
    SQLSMALLINT BufferLength,
    _Out_opt_
    SQLSMALLINT *NameLengthPtr
)
{
    MessageBox(GetDesktopWindow(), TEXT("Not Implemented"), NULL, MB_OK);
    return SQL_ERROR;
}

SQLRETURN  SQL_API SQLGetData(SQLHSTMT StatementHandle,
    SQLUSMALLINT ColumnNumber, SQLSMALLINT TargetType,
    _Out_writes_opt_(_Inexpressible_(BufferLength)) SQLPOINTER TargetValue, SQLLEN BufferLength,
    _Out_opt_ SQLLEN *StrLen_or_IndPtr)
{
    MessageBox(GetDesktopWindow(), TEXT("Not Implemented"), NULL, MB_OK);
    return SQL_ERROR;
}

SQLRETURN  SQL_API SQLGetDescField(SQLHDESC DescriptorHandle,
    SQLSMALLINT RecNumber, SQLSMALLINT FieldIdentifier,
    _Out_writes_opt_(_Inexpressible_(BufferLength)) SQLPOINTER Value, SQLINTEGER BufferLength,
    _Out_opt_ SQLINTEGER *StringLength)
{
    MessageBox(GetDesktopWindow(), TEXT("Not Implemented"), NULL, MB_OK);
    return SQL_ERROR;
}

SQLRETURN  SQL_API SQLGetDescRec(SQLHDESC DescriptorHandle,
    SQLSMALLINT RecNumber, _Out_writes_opt_(BufferLength) SQLCHAR *Name,
    SQLSMALLINT BufferLength, _Out_opt_ SQLSMALLINT *StringLengthPtr,
    _Out_opt_ SQLSMALLINT *TypePtr, _Out_opt_ SQLSMALLINT *SubTypePtr,
    _Out_opt_ SQLLEN     *LengthPtr, _Out_opt_ SQLSMALLINT *PrecisionPtr,
    _Out_opt_ SQLSMALLINT *ScalePtr, _Out_opt_ SQLSMALLINT *NullablePtr)
{
    MessageBox(GetDesktopWindow(), TEXT("Not Implemented"), NULL, MB_OK);
    return SQL_ERROR;
}

SQLRETURN  SQL_API SQLGetDiagField(SQLSMALLINT HandleType, SQLHANDLE Handle,
    SQLSMALLINT RecNumber, SQLSMALLINT DiagIdentifier,
    _Out_writes_opt_(_Inexpressible_(BufferLength)) SQLPOINTER DiagInfo, SQLSMALLINT BufferLength,
    _Out_opt_ SQLSMALLINT *StringLength)
{
    MessageBox(GetDesktopWindow(), TEXT("Not Implemented"), NULL, MB_OK);
    return SQL_ERROR;
}

SQLRETURN  SQL_API SQLGetDiagRec
(
    SQLSMALLINT HandleType,
    SQLHANDLE Handle,
    SQLSMALLINT RecNumber,
    _Out_writes_opt_(6) SQLCHAR *Sqlstate,
    SQLINTEGER *NativeError,
    _Out_writes_opt_(BufferLength) SQLCHAR* MessageText,
    SQLSMALLINT BufferLength,
    _Out_opt_
    SQLSMALLINT *TextLength
)
{
    MessageBox(GetDesktopWindow(), TEXT("Not Implemented"), NULL, MB_OK);
    return SQL_ERROR;
}

SQLRETURN  SQL_API SQLGetEnvAttr(SQLHENV EnvironmentHandle,
    SQLINTEGER Attribute, _Out_writes_(_Inexpressible_(BufferLength)) SQLPOINTER Value,
    SQLINTEGER BufferLength, _Out_opt_ SQLINTEGER *StringLength)
{
    MessageBox(GetDesktopWindow(), TEXT("Not Implemented"), NULL, MB_OK);
    return SQL_ERROR;
}

SQLRETURN  SQL_API SQLGetFunctions(SQLHDBC ConnectionHandle,
    SQLUSMALLINT FunctionId,
    _Out_writes_opt_(_Inexpressible_("Buffer length pfExists points to depends on fFunction value."))
    SQLUSMALLINT *Supported)
{
    return SQL_SUCCESS;
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
        return SQL_SUCCESS;
    case SQL_ASYNC_DBC_FUNCTIONS:
        *(SQLINTEGER*)InfoValue = 0;
        return SQL_SUCCESS;
    case SQL_ASYNC_NOTIFICATION:
        *(SQLINTEGER*)InfoValue = SQL_ASYNC_NOTIFICATION_NOT_CAPABLE;
        return SQL_SUCCESS;
    default:
        MessageBox(GetDesktopWindow(), TEXT("Not Implemented"), NULL, MB_OK);
        return SQL_ERROR;
    }
}

SQLRETURN  SQL_API SQLGetStmtAttr(SQLHSTMT StatementHandle,
    SQLINTEGER Attribute, _Out_writes_opt_(_Inexpressible_(BufferLength)) SQLPOINTER Value,
    SQLINTEGER BufferLength, _Out_opt_ SQLINTEGER *StringLength)
{
    MessageBox(GetDesktopWindow(), TEXT("Not Implemented"), NULL, MB_OK);
    return SQL_ERROR;
}

SQLRETURN  SQL_API SQLGetTypeInfo(SQLHSTMT StatementHandle,
    SQLSMALLINT DataType)
{
    MessageBox(GetDesktopWindow(), TEXT("Not Implemented"), NULL, MB_OK);
    return SQL_ERROR;
}

SQLRETURN  SQL_API SQLNumResultCols(SQLHSTMT StatementHandle,
    _Out_ SQLSMALLINT *ColumnCount)
{
    MessageBox(GetDesktopWindow(), TEXT("Not Implemented"), NULL, MB_OK);
    return SQL_ERROR;
}

SQLRETURN  SQL_API SQLParamData(SQLHSTMT StatementHandle,
    _Out_opt_ SQLPOINTER *Value)
{
    MessageBox(GetDesktopWindow(), TEXT("Not Implemented"), NULL, MB_OK);
    return SQL_ERROR;
}

SQLRETURN  SQL_API SQLPrepare
(
    SQLHSTMT StatementHandle,
    _In_reads_(TextLength) SQLCHAR* StatementText,
    SQLINTEGER TextLength
)
{
    MessageBox(GetDesktopWindow(), TEXT("Not Implemented"), NULL, MB_OK);
    return SQL_ERROR;
}

SQLRETURN  SQL_API SQLPutData(SQLHSTMT StatementHandle,
    _In_reads_(_Inexpressible_(StrLen_or_Ind)) SQLPOINTER Data, SQLLEN StrLen_or_Ind)
{
    MessageBox(GetDesktopWindow(), TEXT("Not Implemented"), NULL, MB_OK);
    return SQL_ERROR;
}

SQLRETURN  SQL_API SQLRowCount(_In_ SQLHSTMT StatementHandle,
    _Out_ SQLLEN* RowCount)
{
    MessageBox(GetDesktopWindow(), TEXT("Not Implemented"), NULL, MB_OK);
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
        MessageBox(GetDesktopWindow(), TEXT("Not Implemented"), NULL, MB_OK);
        return SQL_ERROR;
    }
}

SQLRETURN  SQL_API SQLSetCursorName
(
    SQLHSTMT StatementHandle,
    _In_reads_(NameLength) SQLCHAR* CursorName,
    SQLSMALLINT NameLength
)
{
    MessageBox(GetDesktopWindow(), TEXT("Not Implemented"), NULL, MB_OK);
    return SQL_ERROR;
}

SQLRETURN  SQL_API SQLSetDescField(SQLHDESC DescriptorHandle,
    SQLSMALLINT RecNumber, SQLSMALLINT FieldIdentifier,
    _In_reads_(_Inexpressible_(BufferLength)) SQLPOINTER Value, SQLINTEGER BufferLength)
{
    MessageBox(GetDesktopWindow(), TEXT("Not Implemented"), NULL, MB_OK);
    return SQL_ERROR;
}

SQLRETURN  SQL_API SQLSetDescRec(SQLHDESC DescriptorHandle,
    SQLSMALLINT RecNumber, SQLSMALLINT Type,
    SQLSMALLINT SubType, SQLLEN Length,
    SQLSMALLINT Precision, SQLSMALLINT Scale,
    _Inout_updates_bytes_opt_(Length) SQLPOINTER Data, _Inout_opt_ SQLLEN *StringLength,
    _Inout_opt_ SQLLEN *Indicator)
{
    MessageBox(GetDesktopWindow(), TEXT("Not Implemented"), NULL, MB_OK);
    return SQL_ERROR;
}

SQLRETURN  SQL_API SQLSetEnvAttr(SQLHENV EnvironmentHandle,
    SQLINTEGER Attribute, _In_reads_bytes_opt_(StringLength) SQLPOINTER Value,
    SQLINTEGER StringLength)
{
    return SQL_SUCCESS;
}

SQLRETURN  SQL_API SQLSetStmtAttr(SQLHSTMT StatementHandle,
    SQLINTEGER Attribute, _In_reads_(_Inexpressible_(StringLength)) SQLPOINTER Value,
    SQLINTEGER StringLength)
{
    MessageBox(GetDesktopWindow(), TEXT("Not Implemented"), NULL, MB_OK);
    return SQL_ERROR;
}

SQLRETURN  SQL_API SQLSpecialColumns(SQLHSTMT StatementHandle,
    SQLUSMALLINT IdentifierType,
    _In_reads_opt_(NameLength1) SQLCHAR *CatalogName, SQLSMALLINT NameLength1,
    _In_reads_opt_(NameLength2) SQLCHAR *SchemaName, SQLSMALLINT NameLength2,
    _In_reads_opt_(NameLength3) SQLCHAR *TableName, SQLSMALLINT NameLength3,
    SQLUSMALLINT Scope, SQLUSMALLINT Nullable)
{
    MessageBox(GetDesktopWindow(), TEXT("Not Implemented"), NULL, MB_OK);
    return SQL_ERROR;
}

SQLRETURN  SQL_API SQLStatistics(SQLHSTMT StatementHandle,
    _In_reads_opt_(NameLength1) SQLCHAR *CatalogName, SQLSMALLINT NameLength1,
    _In_reads_opt_(NameLength2) SQLCHAR *SchemaName, SQLSMALLINT NameLength2,
    _In_reads_opt_(NameLength3) SQLCHAR *TableName, SQLSMALLINT NameLength3,
    SQLUSMALLINT Unique, SQLUSMALLINT Reserved)
{
    MessageBox(GetDesktopWindow(), TEXT("Not Implemented"), NULL, MB_OK);
    return SQL_ERROR;
}

SQLRETURN  SQL_API SQLTables(SQLHSTMT StatementHandle,
    _In_reads_opt_(NameLength1) SQLCHAR *CatalogName, SQLSMALLINT NameLength1,
    _In_reads_opt_(NameLength2) SQLCHAR *SchemaName, SQLSMALLINT NameLength2,
    _In_reads_opt_(NameLength3) SQLCHAR *TableName, SQLSMALLINT NameLength3,
    _In_reads_opt_(NameLength4) SQLCHAR *TableType, SQLSMALLINT NameLength4)
{
    MessageBox(GetDesktopWindow(), TEXT("Not Implemented"), NULL, MB_OK);
    return SQL_ERROR;
}

SQLRETURN  SQL_API SQLTransact(SQLHENV EnvironmentHandle,
    SQLHDBC ConnectionHandle, SQLUSMALLINT CompletionType)
{
    MessageBox(GetDesktopWindow(), TEXT("Not Implemented"), NULL, MB_OK);
    return SQL_ERROR;
}

SQLRETURN   SQL_API SQLBulkOperations(
    SQLHSTMT            StatementHandle,
    SQLSMALLINT         Operation)
{
    MessageBox(GetDesktopWindow(), TEXT("Not Implemented"), NULL, MB_OK);
    return SQL_ERROR;
}

SQLRETURN SQL_API SQLColAttributes(
    SQLHSTMT           hstmt,
    SQLUSMALLINT       icol,
    SQLUSMALLINT       fDescType,
    SQLPOINTER         rgbDesc,
    SQLSMALLINT        cbDescMax,
    SQLSMALLINT       *pcbDesc,
    SQLLEN            * pfDesc)
{
    MessageBox(GetDesktopWindow(), TEXT("Not Implemented"), NULL, MB_OK);
    return SQL_ERROR;
}

SQLRETURN SQL_API SQLColumnPrivileges(
    SQLHSTMT           hstmt,
    _In_reads_opt_(cchCatalogName)
    SQLCHAR           *szCatalogName,
    SQLSMALLINT        cchCatalogName,
    _In_reads_opt_(cchSchemaName)
    SQLCHAR           *szSchemaName,
    SQLSMALLINT        cchSchemaName,
    _In_reads_opt_(cchTableName)
    SQLCHAR           *szTableName,
    SQLSMALLINT        cchTableName,
    _In_reads_opt_(cchColumnName)
    SQLCHAR           *szColumnName,
    SQLSMALLINT        cchColumnName)
{
    MessageBox(GetDesktopWindow(), TEXT("Not Implemented"), NULL, MB_OK);
    return SQL_ERROR;
}

SQLRETURN SQL_API SQLDescribeParam(
    SQLHSTMT           hstmt,
    SQLUSMALLINT       ipar,
    _Out_opt_
    SQLSMALLINT       *pfSqlType,
    _Out_opt_
    SQLULEN           *pcbParamDef,
    _Out_opt_
    SQLSMALLINT       *pibScale,
    _Out_opt_
    SQLSMALLINT       *pfNullable)
{
    MessageBox(GetDesktopWindow(), TEXT("Not Implemented"), NULL, MB_OK);
    return SQL_ERROR;
}

SQLRETURN SQL_API SQLExtendedFetch(
    SQLHSTMT           hstmt,
    SQLUSMALLINT       fFetchType,
    SQLLEN             irow,
    _Out_opt_
    SQLULEN           *pcrow,
    _Out_opt_
    SQLUSMALLINT      *rgfRowStatus)
{
    MessageBox(GetDesktopWindow(), TEXT("Not Implemented"), NULL, MB_OK);
    return SQL_ERROR;
}

SQLRETURN SQL_API SQLForeignKeys(
    SQLHSTMT           hstmt,
    _In_reads_opt_(cchPkCatalogName)
    SQLCHAR           *szPkCatalogName,
    SQLSMALLINT        cchPkCatalogName,
    _In_reads_opt_(cchPkSchemaName)
    SQLCHAR           *szPkSchemaName,
    SQLSMALLINT        cchPkSchemaName,
    _In_reads_opt_(cchPkTableName)
    SQLCHAR           *szPkTableName,
    SQLSMALLINT        cchPkTableName,
    _In_reads_opt_(cchFkCatalogName)
    SQLCHAR           *szFkCatalogName,
    SQLSMALLINT        cchFkCatalogName,
    _In_reads_opt_(cchFkSchemaName)
    SQLCHAR           *szFkSchemaName,
    SQLSMALLINT        cchFkSchemaName,
    _In_reads_opt_(cchFkTableName)
    SQLCHAR           *szFkTableName,
    SQLSMALLINT        cchFkTableName)
{
    MessageBox(GetDesktopWindow(), TEXT("Not Implemented"), NULL, MB_OK);
    return SQL_ERROR;
}

SQLRETURN SQL_API SQLMoreResults(
    SQLHSTMT           hstmt)
{
    MessageBox(GetDesktopWindow(), TEXT("Not Implemented"), NULL, MB_OK);
    return SQL_ERROR;
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
    MessageBox(GetDesktopWindow(), TEXT("Not Implemented"), NULL, MB_OK);
    return SQL_ERROR;
}

SQLRETURN SQL_API SQLNumParams(
    SQLHSTMT           hstmt,
    _Out_opt_
    SQLSMALLINT       *pcpar)
{
    MessageBox(GetDesktopWindow(), TEXT("Not Implemented"), NULL, MB_OK);
    return SQL_ERROR;
}

SQLRETURN SQL_API SQLParamOptions(
    SQLHSTMT           hstmt,
    SQLULEN            crow,
    SQLULEN            *pirow)
{
    MessageBox(GetDesktopWindow(), TEXT("Not Implemented"), NULL, MB_OK);
    return SQL_ERROR;
}

SQLRETURN SQL_API SQLPrimaryKeys(
    SQLHSTMT           hstmt,
    _In_reads_opt_(cchCatalogName)
    SQLCHAR           *szCatalogName,
    SQLSMALLINT        cchCatalogName,
    _In_reads_opt_(cchSchemaName)
    SQLCHAR           *szSchemaName,
    SQLSMALLINT        cchSchemaName,
    _In_reads_opt_(cchTableName)
    SQLCHAR           *szTableName,
    SQLSMALLINT        cchTableName)
{
    MessageBox(GetDesktopWindow(), TEXT("Not Implemented"), NULL, MB_OK);
    return SQL_ERROR;
}

SQLRETURN SQL_API SQLProcedureColumns(
    SQLHSTMT           hstmt,
    _In_reads_opt_(cchCatalogName)
    SQLCHAR           *szCatalogName,
    SQLSMALLINT        cchCatalogName,
    _In_reads_opt_(cchSchemaName)
    SQLCHAR           *szSchemaName,
    SQLSMALLINT        cchSchemaName,
    _In_reads_opt_(cchProcName)
    SQLCHAR           *szProcName,
    SQLSMALLINT        cchProcName,
    _In_reads_opt_(cchColumnName)
    SQLCHAR           *szColumnName,
    SQLSMALLINT        cchColumnName)
{
    MessageBox(GetDesktopWindow(), TEXT("Not Implemented"), NULL, MB_OK);
    return SQL_ERROR;
}

SQLRETURN SQL_API SQLProcedures(
    SQLHSTMT           hstmt,
    _In_reads_opt_(cchCatalogName)
    SQLCHAR           *szCatalogName,
    SQLSMALLINT        cchCatalogName,
    _In_reads_opt_(cchSchemaName)
    SQLCHAR           *szSchemaName,
    SQLSMALLINT        cchSchemaName,
    _In_reads_opt_(cchProcName)
    SQLCHAR           *szProcName,
    SQLSMALLINT        cchProcName)
{
    MessageBox(GetDesktopWindow(), TEXT("Not Implemented"), NULL, MB_OK);
    return SQL_ERROR;
}

SQLRETURN SQL_API SQLSetPos(
    SQLHSTMT           hstmt,
    SQLSETPOSIROW      irow,
    SQLUSMALLINT       fOption,
    SQLUSMALLINT       fLock)
{
    MessageBox(GetDesktopWindow(), TEXT("Not Implemented"), NULL, MB_OK);
    return SQL_ERROR;
}

SQLRETURN SQL_API SQLTablePrivileges(
    SQLHSTMT           hstmt,
    _In_reads_opt_(cchCatalogName)
    SQLCHAR           *szCatalogName,
    SQLSMALLINT        cchCatalogName,
    _In_reads_opt_(cchSchemaName)
    SQLCHAR           *szSchemaName,
    SQLSMALLINT        cchSchemaName,
    _In_reads_opt_(cchTableName)
    SQLCHAR           *szTableName,
    SQLSMALLINT        cchTableName)
{
    MessageBox(GetDesktopWindow(), TEXT("Not Implemented"), NULL, MB_OK);
    return SQL_ERROR;
}

SQLRETURN SQL_API SQLDrivers(
    SQLHENV            henv,
    SQLUSMALLINT       fDirection,
    _Out_writes_opt_(cchDriverDescMax)
    SQLCHAR           *szDriverDesc,
    SQLSMALLINT        cchDriverDescMax,
    _Out_opt_
    SQLSMALLINT       *pcchDriverDesc,
    _Out_writes_opt_(cchDrvrAttrMax)
    SQLCHAR           *szDriverAttributes,
    SQLSMALLINT        cchDrvrAttrMax,
    _Out_opt_
    SQLSMALLINT       *pcchDrvrAttr)
{
    MessageBox(GetDesktopWindow(), TEXT("Not Implemented"), NULL, MB_OK);
    return SQL_ERROR;
}

SQLRETURN SQL_API SQLBindParameter(
    SQLHSTMT           hstmt,
    SQLUSMALLINT       ipar,
    SQLSMALLINT        fParamType,
    SQLSMALLINT        fCType,
    SQLSMALLINT        fSqlType,
    SQLULEN            cbColDef,
    SQLSMALLINT        ibScale,
    SQLPOINTER         rgbValue,
    SQLLEN             cbValueMax,
    SQLLEN             *pcbValue)
{
    MessageBox(GetDesktopWindow(), TEXT("Not Implemented"), NULL, MB_OK);
    return SQL_ERROR;
}