# EmbedPython39
Example showing how to embed Python 3.9 + (py)imgui

Read the comments in [EmbedPython39.cpp](EmbedPython39.cpp) and [Python39.props](Python39.props) for the technical details.

## Features showcased
 * [Delay-load](https://docs.microsoft.com/en-us/cpp/build/reference/delayload-delay-load-import) `python39.dll` (from a hardcoded directory)
   * This allows executing code before python is loaded, for example to configure the environment or dll-search order.
 * Configure include folders + link folders using a .props file
   * Both `Debug` + `Release` configurations
 * Show how to import a python module that is distributed with the sample [pyimgui](https://github.com/swistakm/pyimgui)

