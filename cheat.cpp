#include "cheat.h"
#include "hooks.h"
#include <stdio.h>

CCheatManager *g_CheatManager = NULL;

void InitCheat()
{
    g_CheatManager = new CCheatManager();
    if (g_CheatManager->Init())
    {
        g_CheatManager->Run();
    }
    else
    {
        MessageBoxA(NULL, "Unable to initilize the cheat", "Error", MB_OK | MB_ICONERROR);
    }
}

CCheatManager::CCheatManager()
{
    m_bIsRunning = false;
    m_bIsInitialized = false;
    moduleHandle = (DWORD)GetModuleHandle(NULL);
}

CCheatManager::~CCheatManager()
{
    Exit();
}

BOOL CCheatManager::Init()
{
    if (m_bIsInitialized)
        return FALSE;

    if (!HookGame())
        return FALSE;

    m_bIsInitialized = true;

    return TRUE;
}

void CCheatManager::Run()
{
}

BOOL CCheatManager::HookGame()
{

    if (MH_Initialize() != MH_OK)
        return FALSE;

    MH_STATUS create = MH_CreateHook((void *)(moduleHandle + 0xb1130), (void *)Hooks::HookLowerSanity, (void **)&Hooks::oLowerSanity);
    MH_STATUS enable = MH_EnableHook((void *)(moduleHandle + 0xb1130));

    if (create != MH_OK || enable != MH_OK)
        return FALSE;

    return TRUE;
}

void CCheatManager::Exit()
{
    if (!m_bIsInitialized)
        return;

    m_bIsRunning = false;
    m_bIsInitialized = false;
}