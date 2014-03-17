/*
 * TODO:
 * Missing functions
 */

#include "pydbgeng.h"

static PyObject *
pydbgeng_DebugConnect(PyObject *self, PyObject *args)
{
    HRESULT hr;
    char *RemoteOptions = NULL;
    IDebugClient5 *debugClient = NULL;
    PyDebugClientObject *cli = NULL;
    PyDebugEventCallbacks *ev = NULL;
    PyObject *ret = NULL;

    if (!PyArg_ParseTuple(args, "s:DebugConnect", &RemoteOptions))
        return NULL;
    if ((hr = DebugConnect(RemoteOptions, __uuidof(IDebugClient5), 
                (PVOID *)&debugClient)) != S_OK)
        return err_dbgeng(hr);

    cli = (PyDebugClientObject *)PyObject_CallObject(
            (PyObject *)&PyDebugClientType, NULL);
    if (cli == NULL)
        Py_RETURN_NONE;

    cli->client = debugClient;

    ev = new PyDebugEventCallbacks();
    if (ev == NULL) {
        PyErr_NoMemory();
        goto error;
    }

    if ((hr = cli->client->SetEventCallbacks((IDebugEventCallbacks *)ev)) != S_OK) {
        err_dbgeng(hr);
        goto error;
    }

    ret = Py_BuildValue("N", cli);

error:
    if (ret == NULL) {
        if (ev) ev->Release();
        if (cli) { 
            if (cli->client) {
                cli->client->Release();
                cli->client = NULL;
            }
            Py_DECREF(cli);
        }
    }
    return ret;
}

static PyObject *
pydbgeng_DebugCreate(PyObject *self)
{
    HRESULT hr;
    IDebugClient5 *debugClient = NULL;
    PyDebugClientObject *cli = NULL;
    PyDebugEventCallbacks *ev = NULL;
    PyObject *ret = NULL;

    if ((hr = DebugCreate(__uuidof(IDebugClient5), 
                    (PVOID *)&debugClient)) != S_OK) 
        return err_dbgeng(hr);

    cli = (PyDebugClientObject *)PyObject_CallObject(
            (PyObject *)&PyDebugClientType, NULL);
    if (cli == NULL)
        Py_RETURN_NONE;

    cli->client = debugClient;

    ev = new PyDebugEventCallbacks();
    if (ev == NULL) {
        PyErr_NoMemory();
        goto error;
    }

    if ((hr = cli->client->SetEventCallbacks((IDebugEventCallbacks *)ev)) != S_OK) {
        err_dbgeng(hr);
        goto error;
    }

    ret = Py_BuildValue("N", cli);

error:
    if (ret == NULL) {
        if (ev) ev->Release();
        if (cli) { 
            if (cli->client) {
                cli->client->Release();
                cli->client = NULL;
            }
            Py_DECREF(cli);
        }
    }
    return ret;
}

static PyMethodDef  PyDbgEngMethods[] = {
    {"DebugConnect", 
     (PyCFunction)pydbgeng_DebugConnect, METH_VARARGS, 
     "DebugConnect(RemoteOptions)"
    },
    {"DebugCreate", 
     (PyCFunction)pydbgeng_DebugCreate, METH_NOARGS, 
     "DebugCreate()"
    },
    {NULL, NULL, 0, NULL}
};

struct TypeList {
    char *name;
    PyTypeObject *type;
};

static void AddTypes(PyObject *m)
{
    struct TypeList tlist[] = {
        {"DebugClient",     &PyDebugClientType},
        {"DebugControl",    &PyDebugControlType},
        {"DebugBreakpoint", &PyDebugBreakpointType},
        {"DebugAdvanced",   &PyDebugAdvancedType},
        {"DebugRegisters",  &PyDebugRegistersType},
        {"DebugDataSpaces", &PyDebugDataSpacesType},
        {"DebugSymbols",    &PyDebugSymbolsType},
        {"DebugSystems",    &PyDebugSystemsObjectsType},

        {"DebugSymbolEntry",            &PyDebugSymbolEntryType},
        {"DebugRegisterDescription",    &PyDebugRegisterDescriptionType},
        {"DebugStackFrame",             &PyDebugStackFrameType},
        {"ModuleParameters",            &PyDebugModuleParametersType},
        {"BreakPointParameters",        &PyDebugBreakPointParametersType},
        {"DebugModuleAndId",            &PyDebugModuleAndIdType},
        {"ExceptionRecord",             &PyExceptionRecordType},
        {"Context64",                   &PyContext64Type},
        {"Context32",                   &PyContext32Type},

        {NULL},
    };
    int i;
    
    for (i = 0; tlist[i].name != NULL; i++) {
        PyType_Ready(tlist[i].type);
        Py_INCREF(tlist[i].type);
        PyModule_AddObject(m, tlist[i].name, (PyObject *)(tlist[i].type));
    }
}

#ifdef IS_PY3K
	static struct PyModuleDef moduledef = {
		PyModuleDef_HEAD_INIT,
		"pydbgeng",     /* m_name */
		"Python interface to the Windbg engine",  /* m_doc */
		-1,                  /* m_size */
		PyDbgEngMethods,     /* m_methods */
		NULL,                /* m_reload */
		NULL,                /* m_traverse */
		NULL,                /* m_clear */
		NULL,                /* m_free */
	};
#endif

PyMODINIT_FUNC initpydbgeng(void)
{
    PyObject *m;

#if PY_MAJOR_VERSION >= 3
	m = PyModule_Create(&moduledef);
#else
	m = Py_InitModule("pydbgeng", PyDbgEngMethods);
#endif
    if (m == NULL)
        goto error;

    AddConstants(m);
    AddExceptions(m);
    AddTypes(m);

	return m;

error:
    if (PyErr_Occurred())
        PyErr_SetString(PyExc_ImportError, "pydbgeng: init failed");
	return NULL;
}

