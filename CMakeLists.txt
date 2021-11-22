cmake_minimum_required(VERSION 3.0.0)
project(SuperRenderEngine VERSION 0.1.0)

include(CTest)

enable_testing()

add_executable(SuperRenderEngine
    src/RenderObject.h
    src/ROTriangle.h
    # src/RORect.h
    src/RenderEngine.h

    src/RenderObject.cpp
    src/ROTriangle.cpp
    # src/RORect.cpp
    src/RenderEngine.cpp

    tests.cpp
)

target_link_libraries(SuperRenderEngine ncurses foresteamnd)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)