#ifndef __PYDBGENG_H__
#define __PYDBGENG_H__

#include <Python.h>
#include <Windows.h>
#include <Dbgeng.h>

/** @brief Createa a new Python object from a Debug client */
__declspec(dllexport) 
PyObject *pydbgeng_FromExisting(IDebugClient *pClient);

#endif // __PYDBGENG_H__
