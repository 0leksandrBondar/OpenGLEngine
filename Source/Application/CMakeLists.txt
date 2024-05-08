cmake_minimum_required(VERSION 3.14)

set(SOURCES
        main.cpp)

add_executable(OpenGl ${SOURCES})

target_link_libraries(
        OpenGl
        Glm
        Glew
        glfw
        Glad
        Utils
        Render
        Window
)

