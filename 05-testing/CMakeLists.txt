cmake_minimum_required(VERSION 3.16)
project(main)
set(CMAKE_CXX_STANDARD 17)
include(CTest)
enable_testing()
add_subdirectory(src)

if(BUILD_TESTING)
    add_subdirectory(test)
endif()