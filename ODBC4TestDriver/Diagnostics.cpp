#include "Globals.h"

SQLRETURN  SQL_API SQLGetDiagField(SQLSMALLINT HandleType, SQLHANDLE Handle,
    SQLSMALLINT RecNumber, SQLSMALLINT DiagIdentifier,
    _Out_writes_opt_(_Inexpressible_(BufferLength)) SQLPOINTER DiagInfo, SQLSMALLINT BufferLength,
    _Out_opt_ SQLSMALLINT *StringLength)
{
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
    return SQL_NO_DATA;
}

void TestTrace(LPCTSTR s)
{
    MessageBox(GetDesktopWindow(), s, NULL, MB_OK);
}