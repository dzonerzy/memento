#ifndef MACRO_H
#define MACRO_H
#include <windows.h>

#define Thread(x) CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)x, NULL, 0, NULL)

#endif
