#include <Python.h>
#include <Windows.h>
#include "callbacks.h"
#include <exception>

/*
using namespace std;

class ImportException: public exception
{
	virtual const char *what() const throw()
	{
		return "Failed to import the Python module";
	}
};
*/

PybagCallbacks::PybagCallbacks(PDEBUG_CLIENT client, PCSTR modulename) : 
    m_pClient(client),
    m_moduleName(modulename)
{
	m_hModule = PyImport_ImportModule(modulename);
	if( NULL == m_hModule ) 
	{
		//throw new ImportException();
		throw 42;
	}
	// Now we need to find the class that derives from <SOMETHING>
	// and instantiate it, storing a reference

    m_pClient->AddRef();
}

PybagCallbacks::~PybagCallbacks()
{
	// Decrement the reference on the Python module?  Yes, probably.  How?
    m_pClient->Release();
}

STDMETHODIMP
PybagCallbacks::QueryInterface(
THIS_
IN REFIID InterfaceId,
OUT PVOID* Interface
)
{
	*Interface = NULL;

	if (IsEqualIID(InterfaceId, __uuidof(IUnknown)) ||
		IsEqualIID(InterfaceId, __uuidof(IDebugOutputCallbacks)))
	{
		*Interface = (IDebugOutputCallbacks *)this;
		AddRef();
		return S_OK;
	}
	else
	{
		return E_NOINTERFACE;
	}
}

STDMETHODIMP_(ULONG)
PybagCallbacks::AddRef(
THIS
)
{
	// This class is designed to be static so
	// there's no true refcount.
	return 1;
}

STDMETHODIMP_(ULONG)
PybagCallbacks::Release(
THIS
)
{
	// This class is designed to be static so
	// there's no true refcount.
	return 0;
}

STDMETHODIMP_(HRESULT) PybagCallbacks::Breakpoint(PDEBUG_BREAKPOINT Bp)
{
    return S_OK;
}

STDMETHODIMP_(HRESULT) PybagCallbacks::ChangeDebuggeeState(
            ULONG Flags,
            ULONG64 Arguments)
{
    return S_OK;
}

STDMETHODIMP_(HRESULT) PybagCallbacks::ChangeEngineState(
            ULONG Flags,
            ULONG64 Argument)
{
    return S_OK;
}

STDMETHODIMP_(HRESULT) PybagCallbacks::ChangeSymbolState(
            ULONG Flags,
            ULONG64 Argument) 
{
    return S_OK;
}

STDMETHODIMP_(HRESULT) PybagCallbacks::CreateProcess(
            ULONG64 ImageFileHandle,
            ULONG64 Handle,
            ULONG64 BaseOffset,
            ULONG ModuleSize,
            PCSTR ModuleName,
            PCSTR ImageName,
            ULONG CheckSum,
            ULONG TimeDateStamp,
            ULONG64 InitialThreadHandle,
            ULONG64 ThreadDataOffset,
            ULONG64 StartOffset)
{
    return S_OK;
}

STDMETHODIMP_(HRESULT) PybagCallbacks::CreateThread(
            ULONG64 Handle,
            ULONG64 DataOffset,
            ULONG64 StartOffset)
{
    return S_OK;
}

STDMETHODIMP_(HRESULT) PybagCallbacks::Exception(
            PEXCEPTION_RECORD64 Exception,
            ULONG FirstChance)
{
    return S_OK;
}

STDMETHODIMP_(HRESULT) PybagCallbacks::ExitProcess(ULONG ExitCode)
{
    return S_OK;
}

STDMETHODIMP_(HRESULT) PybagCallbacks::ExitThread(ULONG ExitCode)
{
    return S_OK;
}

STDMETHODIMP_(HRESULT) PybagCallbacks::GetInterestMask(PULONG Mask)
{
    *Mask = DEBUG_EVENT_BREAKPOINT |
            DEBUG_EVENT_EXCEPTION |
            DEBUG_EVENT_CREATE_THREAD |
            DEBUG_EVENT_EXIT_THREAD |
            DEBUG_EVENT_CREATE_PROCESS |
            DEBUG_EVENT_EXIT_PROCESS |
            DEBUG_EVENT_LOAD_MODULE |
            DEBUG_EVENT_UNLOAD_MODULE |
            DEBUG_EVENT_SYSTEM_ERROR |
            DEBUG_EVENT_SESSION_STATUS |
            DEBUG_EVENT_CHANGE_DEBUGGEE_STATE |
            DEBUG_EVENT_CHANGE_ENGINE_STATE |
            DEBUG_EVENT_CHANGE_SYMBOL_STATE;
    return S_OK;
}

STDMETHODIMP_(HRESULT) PybagCallbacks::LoadModule(
            ULONG64 ImageFileHandle,
            ULONG64 BaseOffset,
            ULONG ModuleSize,
            PCSTR ModuleName,
            PCSTR ImageName,
            ULONG CheckSum,
            ULONG TimeDateStamp)
{
    return S_OK;
}

STDMETHODIMP_(HRESULT) PybagCallbacks::SessionStatus(
            ULONG Status)
{
	return S_OK;
}

STDMETHODIMP_(HRESULT) PybagCallbacks::SystemError(
            ULONG Error,
            ULONG Level)
{
	return S_OK;
}

STDMETHODIMP_(HRESULT) PybagCallbacks::UnloadModule(
            PCSTR ImageBaseName,
            ULONG64 BaseOffset)
{
    return S_OK;
}
