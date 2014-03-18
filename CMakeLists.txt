cmake_minimum_required(VERSION 2.8)
project(Pybag)

if(NOT DEFINED WIN32)
    message(FATAL_ERROR "This can only run on Windows")
endif()

set(PYTHON_PATH "C:/Python33_x64"
                CACHE STRING "Path to the Python 3 executable's directory")
set(DBGSDK_DIR "C:/Program Files(x86)/Windows Kits/8.0/Debuggers" 
                CACHE STRING "Directory to debugger SDK")

if(${CMAKE_SYSTEM_PROCESSOR} EQUAL "AMD64")
    set(ARCHITECTURE x64)
else()
    set(ARCHITECTURE x86)
endif()

add_subdirectory(windbg-ext)

add_custom_command(
        OUTPUT pydbgeng.pyd
        COMMAND py -3 setup.py build_ext
        COMMENT Build the Python extension
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
)
add_custom_target(pydbgeng ALL DEPENDS pydbgeng.pyd)
