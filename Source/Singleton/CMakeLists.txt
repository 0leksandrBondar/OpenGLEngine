cmake_minimum_required(VERSION 3.14)

set(SOURCE
        ISingleton.cpp
        ISingleton.h
)

add_library(Singleton ${SOURCE})

target_link_libraries(Singleton
        Glm
        Glew
        glfw
        Glad
        Utils
)

target_include_directories(Singleton PUBLIC ./)