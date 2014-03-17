project(python-dbgeng)

set(TARGET_NAME python-dbgeng)

include_directories(${DBGSDK}/inc)
include_directories(${PYTHON_PATH}/include)
link_directories(${DBGSDK}/lib/${ARCHITECTURE})
link_directories(${PYTHON_PATH}/libs)

list(APPEND source_files 
                constants.cpp
                constants.h
                debugadvanced.cpp
                debugbreakpoint.cpp
                debugclient.cpp
                debugcontrol.cpp
                debugdataspaces.cpp
                debugregisters.cpp
                debugsymbolgroup.cpp
                debugsymbols.cpp
                debugsystemsobject.cpp
                eventcallbacks.cpp
                eventcallbacks.h
                exceptions.cpp
                exceptions.h
                outputcallbacks.cpp
                outputcallbacks.h
                pydbgeng.cpp
                pydbgeng.h
                winstructs.cpp
                winstructs.h
				config.h
)
        
set(libs dbgeng.lib)

add_library(${TARGET_NAME} SHARED ${source_files})
target_link_libraries(${TARGET_NAME} ${libs})



