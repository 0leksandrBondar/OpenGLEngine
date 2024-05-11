cmake_minimum_required(VERSION 3.14)

set(HEADER_FILES
        OpenGl.h
        InitOpenGl.h
        stb_image.h
)

add_library(Utils INTERFACE)

target_link_libraries(Utils INTERFACE
        Glm
        Glew
        glfw
        Glad
)

target_sources(Utils INTERFACE ${HEADER_FILES})

target_include_directories(Utils INTERFACE ./)
