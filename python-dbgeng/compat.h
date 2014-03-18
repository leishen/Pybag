#ifndef __CONFIG_H__
#define __CONFIG_H__


#include <Python.h>

#if PY_MAJOR_VERSION >= 3
#define IS_PY3K
#endif


#ifdef IS_PY3K
#define PyInt_FromLong  PyLong_FromLong
#define PyInt_AsLong PyLong_AsLong
#define PyString_FromFormat PyUnicode_FromFormat
#endif


#endif // __CONFIG_H__
