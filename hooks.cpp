#include "hooks.h"

namespace Hooks
{
    tLowerSanity_t oLowerSanity;

    void HookLowerSanity(void *cls, void *EDX, float fAmount, bool bUseEffect)
    {
        fAmount = 0.0f;
        bUseEffect = false;
        return oLowerSanity(cls, fAmount, bUseEffect);
    }
}