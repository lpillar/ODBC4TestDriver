#include "windows.h"
//#include "sqlext.h"
#include "odbcinst.h"

BOOL WINAPI DLLMain(HINSTANCE dll, DWORD reason, LPVOID reserved)
{
    MessageBox(GetDesktopWindow(), TEXT("Not Implemented"), NULL, MB_OK);
    return TRUE;
}