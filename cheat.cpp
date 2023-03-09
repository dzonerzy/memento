#include "cheat.h"

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
    MessageBoxA(NULL, "Hooked!", "Hooked!", MB_OK);
    return TRUE;
}

void CCheatManager::Exit()
{
    if (!m_bIsInitialized)
        return;

    m_bIsRunning = false;
    m_bIsInitialized = false;
}