#include <Windows.h>
#include <DbgEng.h>
#include "ext.h"
#include "callbacks.h"

HRESULT DebugExtensionInitialize(
	_Out_  PULONG Version,
	_Out_  PULONG Flags)
{
	*Version = DEBUG_EXTENSION_VERSION(1, 0);
	*Flags = 0;
	return S_OK;
}

void CALLBACK DebugExtensionUninitialize(void)
{
	return;
}

void CALLBACK DebugExtensionNotify(
	_In_  ULONG Notify,
	_In_  ULONG64 Argument)
{
	return;
}

HRESULT CALLBACK pyscript(
	_In_      PDEBUG_CLIENT Client,
	_In_opt_  PCSTR Args)
{
	PybagCallbacks *callbacks = NULL;
	
	callbacks = new PybagCallbacks(Client, Args);
    
    Client->SetEventCallbacks(callbacks);

	return S_OK;
}

