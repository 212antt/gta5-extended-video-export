// dllmain.cpp : Defines the entry point for the DLL application.

#pragma comment(lib, "lib\\ScriptHookV.lib")
#include "inc\main.h"
#include "script.h"
#include "logger.h"

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
					 )
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
		LOG("Starting up...");
		scriptRegister(hModule, ScriptMain);
		break;
	case DLL_PROCESS_DETACH:
		unhookAllVirtual();
		scriptUnregister(hModule);
		break;
	}
	return TRUE;
}

