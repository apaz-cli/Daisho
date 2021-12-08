#pragma once
#ifndef __STILTS_STDLIB_PYTHON
#define __STILTS_STDLIB_PYTHON

/* No stdlib stuff in here. Only python. */

#if __STILTS_EMBED_PYTHON
#define PY_SSIZE_T_CLEAN
#include <Python.h>


static wchar_t* __Stilts_py_progname = NULL;

__STILTS_FN void
__Stilts_py_init(int argc, char** argv) {
    (void)argc;

    /* Start the python interpreter */
    __Stilts_py_progname = Py_DecodeLocale(argv[0], NULL);
    if (__Stilts_py_progname == NULL) {
        fprintf(stderr, "Fatal error: Python cannot decode argv[0].\n");
        exit(1);
    }

    Py_SetProgramName(__Stilts_py_progname);
    Py_Initialize();
}

__STILTS_FN void
__Stilts_py_exit(void) {
    /* Shut down the python interpreter */
    /* This should be the last thing that's done. */
    if (Py_FinalizeEx() < 0) exit(120);
    PyMem_RawFree(__Stilts_py_progname);
}

__STILTS_FN void
__Stilts_py_eval(char* to_eval) {
    PyRun_SimpleString(to_eval);
}

#endif /* __STILTS_EMBED_PYTHON */
#endif /* __STILTS_STDLIB_PYTHON */
