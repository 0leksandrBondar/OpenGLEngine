cmake_minimum_required(VERSION 3.14)

set(SOURCE
        ShaderProgram.h
        ShaderProgram.cpp
        ResourceManager.cpp
        ResourceManager.h
)

add_library(Render ${SOURCE})

target_link_libraries(Render
        Glad
        Utils
        Singleton
)

target_include_directories(Render PUBLIC ./)