#ifndef CHEAT_H
#define CHEAT_H

#include <windows.h>
#include "MinHook.h"

extern void InitCheat();

class CCheatManager
{
public:
    CCheatManager();
    ~CCheatManager();

    BOOL Init();
    void Run();
    void Exit();

private:
    BOOL HookGame();

    DWORD moduleHandle;
    bool m_bIsRunning;
    bool m_bIsInitialized;
};

extern CCheatManager *g_CheatManager;

#endif