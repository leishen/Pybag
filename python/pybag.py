#!/usr/bin/env python3

class PybagEventCallbacks(object):
    """Base implementation of the PybagEventCallbacks class for handling Windbg
    data.  The API closely mimics the IDebugEventCallbacks interface
    defined in the dbgeng API.  See MSDN for information about the
    interface.

    In addition, this object is instantiated with the IDebugClient
    interface so that changes can be made to the debug engine while
    handling callbacks.
    """
    def __init__(self, client):
        self._client = client

    @property
    def client(self):
        return self._client
    
    def Breakpoint(self, bp):
        raise NotImplementedError
    
    def ChangeDebuggeeState(self, flags, arg):
        raise NotImplementedError

    def ChangeEngineState(self, flags, arg):
        raise NotImplementedError

    def ChangeSymbolState(self, flags, arg);
        raise NotImplementedError

    def CreateProcess(self, ImageFileHandle, Handle, BaseOffset, ModuleSize, ModuleName,
                      ImageName, CheckSum, TimeDateStamp, InitialThreadHandle, 
                      ThreadDataOffset, StartOffset):
        raise NotImplementedError

    def CreateThread(self, Handle, DataOffset, StartOffset):
        raise NotImplementedError

    def Exception(self, WindbgException, FirstChance):
        raise NotImplementedError

    def ExitProcess(self, ExitCode):
        raise NotImplementedError

    def ExitThread(self, ExitCode):
        raise NotImplementedError
        
    def GetInterestMask(self, Mask):
        raise NotImplementedError

    def LoadModule(self, ImageFileHandle, BaseOffset, ModuleSize, ModuleName, 
                   ImageName, CheckSum, TimeDateStamp):
        raise NotImplementedError

    def SessionStatus(self, Status):
        raise NotImplementedError

    def SystemError(self, Level):
        raise NotImplementedError

    def UnloadModule(self, ImageBaseName, BaseOffset):
        raise NotImplementedError
        
