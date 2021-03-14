/*
 * PROJECT:     EmbedPython39
 * LICENSE:     MIT (https://spdx.org/licenses/MIT)
 * PURPOSE:     Example showing how to embed Python 3.9 + (py)imgui
 * COPYRIGHT:   Copyright 2021 Mark Jansen <mark.jansen@reactos.org>
 */


#include <Windows.h>
#include <Python.h>


auto script = "import sys\n\
print(sys.version)\n\
print(sys.version_info)\n\
print(sys.path)";

auto imgui_import = "import imgui\n\
print(imgui.get_version())";


int main()
{
    /* This + delay-loading (see Python39.props) makes sure we can run python even if it is not in the path,
       but only if it is installed in this exact directory!
       Hardcoded for this example */
    SetDllDirectoryW(L"C:\\Program Files\\Python39");

    Py_Initialize();

    /*
     * The included pyimgui distribution is built using:
     * `"c:\Program Files\Python39\python.exe" setup.py build -b ../test_out`
     * The debug binary is created using:
     * `"c:\Program Files\Python39\python.exe" setup.py build_ext --debug -b ../test_out`
     * and then renamed to 'core_d.cp39-win_amd64.pyd'
     * Manually Add the pyimgui output dir to search path:
     */
    PyObject* sys_path = PySys_GetObject("path");
    /* See Python39.props for the definition of EXAMPLEDIR! */
    PyList_Append(sys_path, PyUnicode_FromString(EXAMPLEDIR "\\lib.win-amd64-3.9"));

    /* Show current version*/
    PyRun_SimpleString(script);

    /* Show import statement */
    PyRun_SimpleString(imgui_import);


    Py_Finalize();
    return 0;
}

