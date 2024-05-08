cmake_minimum_required(VERSION 3.14)

set(SOURCE
        MainWindow.h
        MainWindow.cpp
)

add_library(Window ${SOURCE})

target_link_libraries(Window
        Singleton
)

target_include_directories(Window PUBLIC ./)