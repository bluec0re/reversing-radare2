cmake_minimum_required(VERSION 3.3.2)
project(re-challenges)

option(BUILD_STATIC "Enable static linking" OFF)

if(BUILD_STATIC)
    set(CMAKE_EXE_LINKER_FLAGS "-static -static-libgcc -static-libstdc++")
endif(BUILD_STATIC)


add_subdirectory(sources)
