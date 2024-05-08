set(GLAD_PATH "${DEPENDENCIES_PATH}/GLAD")

message(${GLAD_PATH})
if (NOT IS_DIRECTORY ${GLAD_PATH})
    message(FATAL_ERROR "Can't find the library by the next path: " ${GLAD_PATH})
endif ()

add_library(
        Glad STATIC
        ${GLAD_PATH}/glad.c
)

target_include_directories(
        Glad PUBLIC ${GLAD_PATH}
        ${GLAD_PATH}/KHR
)