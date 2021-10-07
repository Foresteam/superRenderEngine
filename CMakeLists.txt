cmake_minimum_required(VERSION 3.0.0)
project(SuperRenderEngine VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(
    SuperRenderEngine

    Vector.h
    Triangle.h
    RenderObject.h
    ROTriangle.h
    # RORect.h
    RenderEngine.h

    Vector.cpp
    Triangle.cpp
    RenderObject.cpp
    ROTriangle.cpp
    # RORect.cpp
    RenderEngine.cpp

    main.cpp
)

target_link_libraries(SuperRenderEngine ncurses)
add_compile_options(--std=c++20)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)