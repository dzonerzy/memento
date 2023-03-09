#include "macro.h"
#include "cheat.h"

#include "Windows.h"
#include "stdio.h"

BOOL APIENTRY DllMain(HANDLE hModule,
                      DWORD ul_reason_for_call,
                      LPVOID lpReserved)
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        DisableThreadLibraryCalls((HMODULE)hModule);
        Thread(InitCheat);
        break;
    }
    return TRUE;
}
