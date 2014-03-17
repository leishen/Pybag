#ifndef __PYBAG_H__
#define __PYBAG_H__

/* 
 * To Do:
 *  - Ensure a Python class can exist with a given interface pointer from Doug's work
 *  - Load Python module
 *  - Create object from module to call the callbacks
 *  - ???
 */

#include <Windows.h>
#include <DbgEng.h>
#include <Python.h>

class PybagCallbacks : public IDebugEventCallbacks
{
    private:
    IDebugClient 	*m_pClient;
	PCSTR			m_moduleName;
	PyObject		*m_hModule;

    public:
	// IUnknown.
	STDMETHOD(QueryInterface)(
		THIS_
		IN REFIID InterfaceId,
		OUT PVOID* Interface
		);
	STDMETHOD_(ULONG, AddRef)(
		THIS
		);
	STDMETHOD_(ULONG, Release)(
		THIS
		);

    PybagCallbacks(PDEBUG_CLIENT client, PCSTR modulename);
    ~PybagCallbacks();

    STDMETHOD_(HRESULT, Breakpoint)(PDEBUG_BREAKPOINT Bp);
	STDMETHOD_(HRESULT, ChangeDebuggeeState)(
                ULONG Flags,
                ULONG64 Argument);
	STDMETHOD_(HRESULT, ChangeEngineState)(
                ULONG Flags,
                ULONG64 Argument);
	STDMETHOD_(HRESULT, ChangeSymbolState)(
                ULONG Flags,
                ULONG64 Argument); 
	STDMETHOD_(HRESULT, CreateProcess)(
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
                ULONG64 StartOffset);
	STDMETHOD_(HRESULT, CreateThread)(
                ULONG64 Handle,
                ULONG64 DataOffset,
                ULONG64 StartOffset);
	STDMETHOD_(HRESULT, Exception)(
                PEXCEPTION_RECORD64 Exception,
                ULONG FirstChance);
	STDMETHOD_(HRESULT, ExitProcess)(ULONG ExitCode);
	STDMETHOD_(HRESULT, ExitThread)(ULONG ExitCode);
	STDMETHOD_(HRESULT, GetInterestMask)(PULONG Mask);
	STDMETHOD_(HRESULT, LoadModule)(
                ULONG64 ImageFileHandle,
                ULONG64 BaseOffset,
                ULONG ModuleSize,
                PCSTR ModuleName,
                PCSTR ImageName,
                ULONG CheckSum,
                ULONG TimeDateStamp);
	STDMETHOD_(HRESULT, SessionStatus)(
                ULONG Status);
	STDMETHOD_(HRESULT, SystemError)(
                ULONG Error,
                ULONG Level);
	STDMETHOD_(HRESULT, UnloadModule)(
                PCSTR ImageBaseName,
                ULONG64 BaseOffset);

};

#endif //__PYBAG_H__
