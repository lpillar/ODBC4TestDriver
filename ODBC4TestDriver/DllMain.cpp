#include "Globals.h"

BOOL WINAPI DLLMain(HINSTANCE dll, DWORD reason, LPVOID reserved)
{
    if (reason == DLL_PROCESS_ATTACH)
    {
        TestTrace(TEXT("Loading the ODBC4TestDriver."));
    }
    else if (reason == DLL_PROCESS_DETACH)
    {
        TestTrace(TEXT("Unloading the ODBC4TestDriver."));
    }

    return TRUE;
}