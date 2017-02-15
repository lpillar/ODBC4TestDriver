#include "Globals.h"

SQLRETURN  SQL_API SQLCopyDesc(SQLHDESC SourceDescHandle,
    SQLHDESC TargetDescHandle)
{
    TestTrace(TEXT("SQLCopyDesc not implemented"));
    return SQL_ERROR;
}

SQLRETURN  SQL_API SQLGetDescField(SQLHDESC DescriptorHandle,
    SQLSMALLINT RecNumber, SQLSMALLINT FieldIdentifier,
    _Out_writes_opt_(_Inexpressible_(BufferLength)) SQLPOINTER Value, SQLINTEGER BufferLength,
    _Out_opt_ SQLINTEGER *StringLength)
{
    DescStruct *desc = (DescStruct*)DescriptorHandle;

    switch (FieldIdentifier)
    {
    case SQL_DESC_ARRAY_SIZE:
        return  desc->GetArraySize((SQLULEN*)Value);
    case SQL_DESC_ARRAY_STATUS_PTR:
        return desc->GetArrayStatusPtr((SQLUSMALLINT**)Value);
    case SQL_DESC_BIND_OFFSET_PTR:
        return desc->GetBindOffsetPtr((SQLINTEGER**)Value);
    case SQL_DESC_BIND_TYPE:
        return desc->GetBindType((SQLINTEGER*)Value);
    case SQL_DESC_COUNT:
        return desc->GetCount((SQLSMALLINT*)Value);
    case SQL_DESC_ALLOC_TYPE:
        return desc->GetAllocType((SQLSMALLINT*)Value);
    case SQL_DESC_ROWS_PROCESSED_PTR:
        if (Value)
        {
            *(SQLINTEGER*)Value = 0; // Temporary hack
        }
        return SQL_SUCCESS;
    default:
        TestTrace(TEXT("SQLGetDescField not implemented for this value"));
        return SQL_ERROR;
    }
}

SQLRETURN  SQL_API SQLGetDescRec(SQLHDESC DescriptorHandle,
    SQLSMALLINT RecNumber, _Out_writes_opt_(BufferLength) SQLCHAR *Name,
    SQLSMALLINT BufferLength, _Out_opt_ SQLSMALLINT *StringLengthPtr,
    _Out_opt_ SQLSMALLINT *TypePtr, _Out_opt_ SQLSMALLINT *SubTypePtr,
    _Out_opt_ SQLLEN     *LengthPtr, _Out_opt_ SQLSMALLINT *PrecisionPtr,
    _Out_opt_ SQLSMALLINT *ScalePtr, _Out_opt_ SQLSMALLINT *NullablePtr)
{
    TestTrace(TEXT("SQLGetDescRec not implemented"));
    return SQL_ERROR;
}

SQLRETURN  SQL_API SQLSetDescField(SQLHDESC DescriptorHandle,
    SQLSMALLINT RecNumber, SQLSMALLINT FieldIdentifier,
    _In_reads_(_Inexpressible_(BufferLength)) SQLPOINTER Value, SQLINTEGER BufferLength)
{
    TestTrace(TEXT("SQLSetDescField not implemented"));
    return SQL_ERROR;
}

SQLRETURN  SQL_API SQLSetDescRec(SQLHDESC DescriptorHandle,
    SQLSMALLINT RecNumber, SQLSMALLINT Type,
    SQLSMALLINT SubType, SQLLEN Length,
    SQLSMALLINT Precision, SQLSMALLINT Scale,
    _Inout_updates_bytes_opt_(Length) SQLPOINTER Data, _Inout_opt_ SQLLEN *StringLength,
    _Inout_opt_ SQLLEN *Indicator)
{
    TestTrace(TEXT("SQLSetDescRec not implemented"));
    return SQL_ERROR;
}