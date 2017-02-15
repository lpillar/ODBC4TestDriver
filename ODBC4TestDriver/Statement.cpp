#include "Globals.h"

SQLRETURN  SQL_API SQLBindCol(SQLHSTMT StatementHandle,
    SQLUSMALLINT ColumnNumber, SQLSMALLINT TargetType,
    _Inout_updates_opt_(_Inexpressible_(BufferLength)) SQLPOINTER TargetValue,
    SQLLEN BufferLength, _Inout_opt_ SQLLEN *StrLen_or_Ind)
{
    TestTrace("SQLBindCol not implemented");
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
    TestTrace(TEXT("SQLBindParameter not implemented"));
    return SQL_ERROR;
}

SQLRETURN   SQL_API SQLBulkOperations(
    SQLHSTMT            StatementHandle,
    SQLSMALLINT         Operation)
{
    TestTrace(TEXT("SQLBulkOperations not implemented"));
    return SQL_ERROR;
}

SQLRETURN  SQL_API SQLCancel(SQLHSTMT StatementHandle)
{
    return SQL_SUCCESS;
}

SQLRETURN  SQL_API SQLCancelHandle(SQLSMALLINT HandleType, SQLHANDLE InputHandle)
{
    TestTrace(TEXT("SQLCancelHandle not implemented"));
    return SQL_ERROR;
}

SQLRETURN  SQL_API SQLCloseCursor(SQLHSTMT StatementHandle)
{
    TestTrace(TEXT("SQLCloseCursor not implemented"));
    return SQL_ERROR;
}

SQLRETURN  SQL_API SQLColAttribute(SQLHSTMT StatementHandle,
    SQLUSMALLINT ColumnNumber, SQLUSMALLINT FieldIdentifier,
    _Out_writes_bytes_opt_(BufferLength) SQLPOINTER CharacterAttribute, SQLSMALLINT BufferLength,
    _Out_opt_ SQLSMALLINT *StringLength, _Out_opt_ SQLPOINTER NumericAttribute)
{
    TestTrace(TEXT("SQLColAttribute not implemented"));
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
    TestTrace(TEXT("SQLColAttributes not implemented"));
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
    TestTrace(TEXT("SQLColumnPrivileges not implemented"));
    return SQL_ERROR;
}

SQLRETURN  SQL_API SQLColumns(SQLHSTMT StatementHandle,
    _In_reads_opt_(NameLength1) SQLCHAR *CatalogName, SQLSMALLINT NameLength1,
    _In_reads_opt_(NameLength2) SQLCHAR *SchemaName, SQLSMALLINT NameLength2,
    _In_reads_opt_(NameLength3) SQLCHAR *TableName, SQLSMALLINT NameLength3,
    _In_reads_opt_(NameLength4) SQLCHAR *ColumnName, SQLSMALLINT NameLength4)
{
    TestTrace(TEXT("SQLColumns not implemented"));
    return SQL_ERROR;
}

SQLRETURN SQL_API SQLCompleteAsync(SQLSMALLINT    HandleType,
    SQLHANDLE      Handle,
    _Out_ RETCODE* AsyncRetCodePtr)
{
    TestTrace(TEXT("SQLCompleteAsync not implemented"));
    return SQL_ERROR;
}

SQLRETURN  SQL_API SQLDescribeCol(SQLHSTMT StatementHandle,
    SQLUSMALLINT ColumnNumber, _Out_writes_opt_(BufferLength) SQLCHAR *ColumnName,
    SQLSMALLINT BufferLength, _Out_opt_ SQLSMALLINT *NameLength,
    _Out_opt_ SQLSMALLINT *DataType, _Out_opt_ SQLULEN *ColumnSize,
    _Out_opt_ SQLSMALLINT *DecimalDigits, _Out_opt_ SQLSMALLINT *Nullable)
{
    StmtStruct *stmt = (StmtStruct*)StatementHandle;
    if (ColumnNumber == 0 || // Bookmark column
        stmt->ird == NULL ||
        ColumnNumber >= stmt->ird->columns->size() ||
        stmt->ird->firstNewColumn <= ColumnNumber) // Hasn't been grabbed by SQLNextColumn yet
    {
        return SQL_ERROR;
    }
    else
    {
        string &s = get<1>(stmt->ird->columns->at(ColumnNumber));
        if (ColumnName)
        {

            strcpy_s((char*)ColumnName, min(s.size() + 1, BufferLength), s.c_str());
            ((char*)ColumnName)[min(BufferLength - 1, s.size())] = 0;
        }
        if (NameLength)
        {
            *NameLength = strlen(s.c_str());
        }

        if (DataType)
        {
            *DataType = SQL_C_CHAR;
        }
        return SQL_SUCCESS;
    }
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
    TestTrace(TEXT("SQLDescribeParam not implemented"));
    return SQL_ERROR;
}

SQLRETURN  SQL_API SQLEndTran(SQLSMALLINT HandleType, SQLHANDLE Handle,
    SQLSMALLINT CompletionType)
{
    TestTrace(TEXT("SQLEndTran not implemented"));
    return SQL_ERROR;
}

SQLRETURN  SQL_API SQLError(SQLHENV EnvironmentHandle,
    SQLHDBC ConnectionHandle, SQLHSTMT StatementHandle,
    _Out_writes_(6) SQLCHAR *Sqlstate, _Out_opt_ SQLINTEGER *NativeError,
    _Out_writes_opt_(BufferLength) SQLCHAR *MessageText, SQLSMALLINT BufferLength,
    _Out_opt_ SQLSMALLINT *TextLength)
{
    TestTrace(TEXT("SQLError not implemented"));
    return SQL_ERROR;
}

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

SQLRETURN SQL_API SQLExtendedFetch(
    SQLHSTMT           hstmt,
    SQLUSMALLINT       fFetchType,
    SQLLEN             irow,
    _Out_opt_
    SQLULEN           *pcrow,
    _Out_opt_
    SQLUSMALLINT      *rgfRowStatus)
{
    TestTrace(TEXT("SQLExtendedFetch not implemented"));
    return SQL_ERROR;
}

SQLRETURN  SQL_API SQLFetch(SQLHSTMT StatementHandle)
{
    StmtStruct *stmt = (StmtStruct*)StatementHandle;

    if (!stmt->iter)
    {
        if (stmt->doc)
        {
            stmt->doc.reset();
        }
        return SQL_ERROR;
    }

    if (stmt->iter->HasMore())
    {
        stmt->doc = stmt->iter->Next();
        auto v = stmt->doc->payload().as_object();
        stmt->ird->firstNewColumn = stmt->ird->columns->size();

        for (auto it2 = stmt->ird->columns->begin(); it2 != stmt->ird->columns->end(); ++it2)
        {
            get<2>(*it2) = "";
        }

        for (auto it = v.begin(); it != v.end(); ++it)
        {
            bool found = false;
            for (auto it2 = stmt->ird->columns->begin(); it2 != stmt->ird->columns->end(); ++it2)
            {
                if (*MakeMB(it->first) == get<1>(*it2)) // Not currently checking type, just title
                {
                    get<2>(*it2) = *(MakeMB(it->second.to_string()));
                    found = true;
                    break;
                }
            }
            if (!found)
            {
                stmt->ird->columns->push_back(
                    tuple<ColumnType, string, string>(str, *MakeMB(it->first), *MakeMB(it->second.to_string())));
            }
        }

        if (stmt->ird->firstNewColumn < stmt->ird->columns->size())
        {
            return SQL_DATA_AVAILABLE;
        }
        else
        {
            return SQL_SUCCESS;
        }
    }
    else
    {
        if (stmt->doc)
        {
            stmt->doc.reset();
        }
        stmt->iter.reset();
        stmt->ird->columns.reset();
        return SQL_NO_DATA;
    }
}

SQLRETURN  SQL_API SQLFetchScroll(SQLHSTMT StatementHandle,
    SQLSMALLINT FetchOrientation, SQLLEN FetchOffset)
{
    TestTrace(TEXT("SQLFetchScroll not implemented"));
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
    TestTrace(TEXT("SQLForeignKeys not implemented"));
    return SQL_ERROR;
}

SQLRETURN  SQL_API SQLFreeStmt(SQLHSTMT StatementHandle,
    SQLUSMALLINT Option)
{
    TestTrace(TEXT("SQLFreeStmt not implemented"));
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
    TestTrace(TEXT("SQLGetCursorName not implemented"));
    return SQL_ERROR;
}

SQLRETURN  SQL_API SQLGetData(SQLHSTMT StatementHandle,
    SQLUSMALLINT ColumnNumber, SQLSMALLINT TargetType,
    _Out_writes_opt_(_Inexpressible_(BufferLength)) SQLPOINTER TargetValue, SQLLEN BufferLength,
    _Out_opt_ SQLLEN *StrLen_or_IndPtr)
{
    if (TargetType != SQL_C_CHAR)
    {
        TestTrace(TEXT("SQLGetData only implemented for SQL_C_CHAR"));
        return SQL_ERROR;
    }

    StmtStruct *stmt = (StmtStruct*)StatementHandle;

    if (stmt->ird->firstNewColumn <= ColumnNumber)
    {
        return SQL_ERROR;
    }

    if (stmt->ird && stmt->ird->columns)
    {
        if (stmt->ird->columns->size() >= ColumnNumber)
        {
            string &s = get<2>(stmt->ird->columns->at(ColumnNumber));
            strcpy_s((char*)TargetValue, min(s.size() + 1, BufferLength), s.c_str());
            ((char*)TargetValue)[min(BufferLength - 1, s.size())] = 0;

            if (*((char*)TargetValue) == 0)
            {
                return SQL_NO_DATA_FOUND;
            }

            if (StrLen_or_IndPtr)
            {
                *StrLen_or_IndPtr = min(BufferLength, s.size() + 1);
            }
            return SQL_SUCCESS;
        }
    }

    return SQL_ERROR;
}

SQLRETURN  SQL_API SQLGetStmtAttr(SQLHSTMT StatementHandle,
    SQLINTEGER Attribute, _Out_writes_opt_(_Inexpressible_(BufferLength)) SQLPOINTER Value,
    SQLINTEGER BufferLength, _Out_opt_ SQLINTEGER *StringLength)
{
    switch (Attribute)
    {
    case SQL_ATTR_APP_ROW_DESC:
        *((ARDStruct**)Value) = ((StmtStruct*)StatementHandle)->ard;
        break;
    case SQL_ATTR_APP_PARAM_DESC:
        *((APDStruct**)Value) = ((StmtStruct*)StatementHandle)->apd;
        break;
    case SQL_ATTR_IMP_ROW_DESC:
        *((IRDStruct**)Value) = ((StmtStruct*)StatementHandle)->ird;
        break;
    case SQL_ATTR_IMP_PARAM_DESC:
        *((IPDStruct**)Value) = ((StmtStruct*)StatementHandle)->ipd;
        break;
    case SQL_ATTR_DYNAMIC_COLUMNS:
        *((SQLINTEGER*)Value) = ((StmtStruct*)StatementHandle)->ird->dynamicColumns;
        break;
    default:
        TestTrace(TEXT("SQLGetStmtAttr not implemented for this attribute"));
        return SQL_ERROR;
    }

    return SQL_SUCCESS;
}

SQLRETURN  SQL_API SQLGetTypeInfo(SQLHSTMT StatementHandle,
    SQLSMALLINT DataType)
{
    TestTrace(TEXT("SQLGetTypeInfo not implemented"));
    return SQL_ERROR;
}

SQLRETURN SQL_API SQLMoreResults(
    SQLHSTMT           hstmt)
{
    TestTrace(TEXT("SQLMoreResults not implemented"));
    return SQL_ERROR;
}

SQLRETURN SQL_API SQLNextColumn(SQLHSTMT StatementHandle,
    _Out_ SQLUSMALLINT *ColumnCount)
{
    StmtStruct *stmt = (StmtStruct*)StatementHandle;
    if (stmt->ird->firstNewColumn < stmt->ird->columns->size())
    {
        *ColumnCount = stmt->ird->firstNewColumn++;
        if (stmt->ird->firstNewColumn == stmt->ird->columns->size())
        {
            return SQL_SUCCESS;
        }
        else
        {
            return SQL_DATA_AVAILABLE;
        }
    }
    else
    {
        return SQL_ERROR;
    }
}

SQLRETURN SQL_API SQLNumParams(
    SQLHSTMT           hstmt,
    _Out_opt_
    SQLSMALLINT       *pcpar)
{
    TestTrace(TEXT("SQLNumParams not implemented"));
    return SQL_ERROR;
}

SQLRETURN  SQL_API SQLNumResultCols(SQLHSTMT StatementHandle,
    _Out_ SQLSMALLINT *ColumnCount)
{
    if (!StatementHandle)
    {
        return SQL_INVALID_HANDLE;
    }

    if (ColumnCount && ((StmtStruct*)StatementHandle)->ird && ((StmtStruct*)StatementHandle)->ird->columns)
    {
        *ColumnCount = ((StmtStruct*)StatementHandle)->ird->columns->size() - 1; // Subtract 1 for bookmark col
        return SQL_SUCCESS;
    }
    else
    {
        return SQL_ERROR;
    }
}

SQLRETURN  SQL_API SQLParamData(SQLHSTMT StatementHandle,
    _Out_opt_ SQLPOINTER *Value)
{
    TestTrace(TEXT("SQLParamData not implemented"));
    return SQL_ERROR;
}

SQLRETURN SQL_API SQLParamOptions(
    SQLHSTMT           hstmt,
    SQLULEN            crow,
    SQLULEN            *pirow)
{
    TestTrace(TEXT("SQLParamOptions not implemented"));
    return SQL_ERROR;
}

SQLRETURN  SQL_API SQLPrepare
(
    SQLHSTMT StatementHandle,
    _In_reads_(TextLength) SQLCHAR* StatementText,
    SQLINTEGER TextLength
)
{
    TestTrace(TEXT("SQLPrepare not implemented"));
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
    TestTrace(TEXT("SQLPrimaryKeys not implemented"));
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
    TestTrace(TEXT("SQLProcedureColumns not implemented"));
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
    TestTrace(TEXT("SQLProcedures not implemented"));
    return SQL_ERROR;
}

SQLRETURN  SQL_API SQLPutData(SQLHSTMT StatementHandle,
    _In_reads_(_Inexpressible_(StrLen_or_Ind)) SQLPOINTER Data, SQLLEN StrLen_or_Ind)
{
    TestTrace(TEXT("SQLPutData not implemented"));
    return SQL_ERROR;
}

SQLRETURN  SQL_API SQLRowCount(_In_ SQLHSTMT StatementHandle,
    _Out_ SQLLEN* RowCount)
{
    TestTrace(TEXT("SQLRowCount not implemented"));
    return SQL_ERROR;
}

SQLRETURN  SQL_API SQLSetCursorName
(
    SQLHSTMT StatementHandle,
    _In_reads_(NameLength) SQLCHAR* CursorName,
    SQLSMALLINT NameLength
)
{
    TestTrace(TEXT("SQLSetCursorName not implemented"));
    return SQL_ERROR;
}

SQLRETURN SQL_API SQLSetPos(
    SQLHSTMT           hstmt,
    SQLSETPOSIROW      irow,
    SQLUSMALLINT       fOption,
    SQLUSMALLINT       fLock)
{
    TestTrace(TEXT("SQLSetPos not implemented"));
    return SQL_ERROR;
}

SQLRETURN  SQL_API SQLSetStmtAttr(SQLHSTMT StatementHandle,
    SQLINTEGER Attribute, _In_reads_(_Inexpressible_(StringLength)) SQLPOINTER Value,
    SQLINTEGER StringLength)
{
    TestTrace(TEXT("SQLSetStmtAttr not implemented"));
    return SQL_ERROR;
}

SQLRETURN  SQL_API SQLSpecialColumns(SQLHSTMT StatementHandle,
    SQLUSMALLINT IdentifierType,
    _In_reads_opt_(NameLength1) SQLCHAR *CatalogName, SQLSMALLINT NameLength1,
    _In_reads_opt_(NameLength2) SQLCHAR *SchemaName, SQLSMALLINT NameLength2,
    _In_reads_opt_(NameLength3) SQLCHAR *TableName, SQLSMALLINT NameLength3,
    SQLUSMALLINT Scope, SQLUSMALLINT Nullable)
{
    TestTrace(TEXT("SQLSpecialColumns not implemented"));
    return SQL_ERROR;
}

SQLRETURN  SQL_API SQLStatistics(SQLHSTMT StatementHandle,
    _In_reads_opt_(NameLength1) SQLCHAR *CatalogName, SQLSMALLINT NameLength1,
    _In_reads_opt_(NameLength2) SQLCHAR *SchemaName, SQLSMALLINT NameLength2,
    _In_reads_opt_(NameLength3) SQLCHAR *TableName, SQLSMALLINT NameLength3,
    SQLUSMALLINT Unique, SQLUSMALLINT Reserved)
{
    TestTrace(TEXT("SQLStatistics not implemented"));
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
    TestTrace(TEXT("SQLTablePrivileges not implemented"));
    return SQL_ERROR;
}

SQLRETURN  SQL_API SQLTables(SQLHSTMT StatementHandle,
    _In_reads_opt_(NameLength1) SQLCHAR *CatalogName, SQLSMALLINT NameLength1,
    _In_reads_opt_(NameLength2) SQLCHAR *SchemaName, SQLSMALLINT NameLength2,
    _In_reads_opt_(NameLength3) SQLCHAR *TableName, SQLSMALLINT NameLength3,
    _In_reads_opt_(NameLength4) SQLCHAR *TableType, SQLSMALLINT NameLength4)
{
    TestTrace(TEXT("SQLTables not implemented"));
    return SQL_ERROR;
}