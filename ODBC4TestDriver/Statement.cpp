#include "Globals.h"

SQLRETURN  SQL_API SQLBindCol(SQLHSTMT StatementHandle,
    SQLUSMALLINT ColumnNumber, SQLSMALLINT TargetType,
    _Inout_updates_opt_(_Inexpressible_(BufferLength)) SQLPOINTER TargetValue,
    SQLLEN BufferLength, _Inout_opt_ SQLLEN *StrLen_or_Ind)
{
    if (TargetType != SQL_C_CHAR)
    {
        TestTrace("SQLBindCol only implemented for strings.");
        return SQL_ERROR;
    }
    IRDStruct *ird = ((StmtStruct*)StatementHandle)->ird;
    if (ird->columns.size() <= ColumnNumber || ird->currentColumn <= ColumnNumber)
    {
        return SQL_ERROR;
    }
    CellStruct &cell = ird->columns[ColumnNumber];

    if (TargetValue == NULL)
    {
        cell.bound = false;
        cell.binding = NULL;
        return SQL_SUCCESS;
    }
    if (cell.type != TargetType)
    {
        return SQL_ERROR;
    }
    cell.bound = true;
    cell.binding = (char*)TargetValue;
    cell.bindingLength = BufferLength;
    cell.StrLen_or_Ind = StrLen_or_Ind;
    return SQL_SUCCESS;
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
    IRDStruct *ird = ((StmtStruct*)StatementHandle)->ird;
    if (ColumnNumber == 0 || // Bookmark column
        ird == NULL ||
        ColumnNumber >= ird->columns.size() ||
        ird->currentColumn <= ColumnNumber) // Hasn't been fetched or SQLNextColumn-ed yet
    {
        return SQL_ERROR;
    }
    else
    {
        CellStruct &cell = ird->columns[ColumnNumber];

        if (ColumnName)
        {

            strcpy_s((char*)ColumnName, min(cell.name.size() + 1, (SQLUSMALLINT)BufferLength), cell.name.c_str());
            ((char*)ColumnName)[min((SQLUSMALLINT)(BufferLength - 1), cell.name.size())] = 0; // Set null terminator if string truncated
        }
        if (NameLength)
        {
            *NameLength = (SQLUSMALLINT)cell.name.size() + 1; // Add one for numm terminator
        }

        if (DataType)
        {
            *DataType = cell.type;
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
        stmt->ird->resetRow();
        stmt->ird->rowIter = stmt->dbc->collection->QueryDocuments(*(stmt->statement));
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
    IRDStruct *ird = ((StmtStruct*)StatementHandle)->ird;

    if (!ird->rowIter || // There must be rows available from Execute or something similar
        ird->incompleteFetch) // Previous fetch must complete before new one - call SQLNextColumn
    {
        return SQL_ERROR; // HY010 Function Sequence Error
    }

    if (ird->rowIter->HasMore())
    {
        ird->resetRow();
        ird->doc = ird->rowIter->Next();
        auto v = ird->doc->payload().as_object();

        for (auto it = v.begin(); it != v.end(); ++it)
        {
            bool found = false;
            for (size_t i = 0; i < ird->columns.size(); ++i)
            {
                if (*MakeMB(it->first) == ird->columns[i].name) // Not currently checking type, just title
                {
                    if (ird->columns[i].bound)
                    { 
                        strcpy_s(ird->columns[i].binding, ird->columns[i].bindingLength, MakeMB(it->second.as_string())->c_str());
                        // TODO: Add SQL_DATA_AT_FETCH code here for long buffers
                    }
                    found = true;
                    ird->columns[i].notInThisRow = false;
                    break;
                }
            }
            if (!found)
            {
                ird->unprocessedColumns.push_back(CellStruct(*MakeMB(it->first), SQL_C_CHAR, false, *(MakeMB(it->second.to_string()))));
                ird->currentColumn = (SQLUSMALLINT)ird->columns.size();
                ird->incompleteFetch = true;
            }
        }

        if (ird->incompleteFetch && ((StmtStruct*)StatementHandle)->supportsDynamicColumns)
        {
            return SQL_DATA_AVAILABLE;
        }
        else
        {
            ird->incompleteFetch = false;
            ird->unprocessedColumns.clear();
            return SQL_SUCCESS;
        }
    }
    else
    {
        ird->resetRow();
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

    IRDStruct *ird = ((StmtStruct*)StatementHandle)->ird;

    if (!ird)
    {
        return SQL_ERROR; // invalid handle
    }
    if (ird->incompleteFetch && ird->currentColumn <= ColumnNumber)
    {
        return SQL_ERROR; // This column has not been processed by SQLNextColumn yet
    }
    if (ird->columns.size() <= ColumnNumber)
    {
        return SQL_ERROR; // Out of bounds
    }

    CellStruct &cell = ird->columns[ColumnNumber];

    if (cell.notInThisRow)
    {
        if (StrLen_or_IndPtr)
        {
            *StrLen_or_IndPtr = SQL_DATA_UNAVAILABLE;
        }
        return SQL_ERROR;
    }
    else
    {
        strcpy_s((char*)TargetValue, min(cell.value.size() + 1, (SQLULEN)BufferLength), cell.value.c_str());
        ((char*)TargetValue)[min((SQLULEN)BufferLength - 1, cell.value.size())] = 0;
        if (StrLen_or_IndPtr)
        {
            *StrLen_or_IndPtr = min((SQLUINTEGER)BufferLength, cell.value.size() + 1);
        }

        if (*((char*)TargetValue) == 0)
        {
            return SQL_NO_DATA_FOUND;
        }
        else
        {
            return SQL_SUCCESS;
        }

    }
}

SQLRETURN  SQL_API SQLGetStmtAttr(SQLHSTMT StatementHandle,
    SQLINTEGER Attribute, _Out_writes_opt_(_Inexpressible_(BufferLength)) SQLPOINTER Value,
    SQLINTEGER BufferLength, _Out_opt_ SQLINTEGER *StringLength)
{
    switch (Attribute)
    {
    case SQL_ATTR_APP_ROW_DESC:
        if (Value)
        {
            *((ARDStruct**)Value) = ((StmtStruct*)StatementHandle)->ard;
        }
        break;
    case SQL_ATTR_APP_PARAM_DESC:
        if (Value)
        {
            *((APDStruct**)Value) = ((StmtStruct*)StatementHandle)->apd;
        }
        break;
    case SQL_ATTR_IMP_ROW_DESC:
        if (Value)
        {
            *((IRDStruct**)Value) = ((StmtStruct*)StatementHandle)->ird;
        }
        break;
    case SQL_ATTR_IMP_PARAM_DESC:
        if (Value)
        {
            *((IPDStruct**)Value) = ((StmtStruct*)StatementHandle)->ipd;
        }
        break;
    case SQL_ATTR_DYNAMIC_COLUMNS:
        // Currently hard-coded to support dynamic columns
        if (Value)
        {
            *((SQLINTEGER*)Value) = ((StmtStruct*)StatementHandle)->supportsDynamicColumns;
        }
        if (StringLength)
        {
            *StringLength = sizeof(SQLINTEGER);
        }
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
    if (!StatementHandle || !((StmtStruct*)StatementHandle)->ird)
    {
        return SQL_INVALID_HANDLE;
    }

    IRDStruct *ird = ((StmtStruct*)StatementHandle)->ird;
    if (!ird->incompleteFetch)
    {
        return SQL_ERROR; // HY010
    }

    if (ird->currentColumn < ird->columns.size()) // This is a variable length column
    {
        return SQL_ERROR; // How did this happen? It's not implemented yet.
    }
    else // This is a new dynamic column
    {
        if (ird->unprocessedColumns.empty())
        {
            return SQL_ERROR; // How did this happen?
        }
        *ColumnCount = ird->currentColumn++;
        ird->columns.push_back(ird->unprocessedColumns.front());
        ird->unprocessedColumns.erase(ird->unprocessedColumns.begin());
        if (ird->unprocessedColumns.empty())
        {
            ird->incompleteFetch = false;
            return SQL_SUCCESS;
        }
        else
        {
            return SQL_DATA_AVAILABLE;
        }
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
    if (!StatementHandle || !((StmtStruct*)StatementHandle)->ird)
    {
        return SQL_INVALID_HANDLE;
    }

    if (ColumnCount)
    {
        *ColumnCount = (SQLSMALLINT)(((StmtStruct*)StatementHandle)->ird->columns.size() - 1); // Subtract 1 for bookmark col
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
    switch (Attribute)
    {
    case SQL_ATTR_DYNAMIC_COLUMNS:
        ((StmtStruct*)StatementHandle)->supportsDynamicColumns = (SQLINTEGER)Value;
    }
    return SQL_SUCCESS;
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