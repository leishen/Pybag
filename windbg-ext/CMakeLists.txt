project(windbg-ext)

set(TARGET_NAME windbg-ext)

include_directories(${DBGSDK}/inc)
include_directories(${PYTHON_PATH}/include)
link_directories(${DBGSDK}/lib/${ARCHITECTURE})
link_directories(${PYTHON_PATH}/libs)

list(APPEND source_files 
                ext.cpp
                ext.h
)
        
set(libs dbgeng.lib)

add_library(${TARGET_NAME} SHARED ${source_files})
add_dependencies(${TARGET_NAME} python-dbgeng)
target_link_libraries(${TARGET_NAME} ${libs})




