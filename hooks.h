#include <windows.h>

#ifndef HOOKS_H
#define HOOKS_H

typedef void(__thiscall *tLowerSanity_t)(void *, float, bool);

namespace Hooks
{
    extern tLowerSanity_t oLowerSanity;
    void __fastcall HookLowerSanity(void *cls, void *EDX, float fAmount, bool bUseEffect);
}

#endif