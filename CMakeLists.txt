cmake_minimum_required(VERSION 3.26)

set(PROJECT_NAME Breakout_Game)
project(${PROJECT_NAME})

# FIXME Horrible piece of shit
include_directories(
    ${CMAKE_SOURCE_DIR}/Breakout
    ${CMAKE_SOURCE_DIR}/Breakout/vendor
    ${CMAKE_SOURCE_DIR}/Breakout/vendor/GLFW
    ${CMAKE_SOURCE_DIR}/Breakout/vendor/GLFW/include
    ${CMAKE_SOURCE_DIR}/Breakout/vendor/Glad
    ${CMAKE_SOURCE_DIR}/Breakout/vendor/Glad/include
    ${CMAKE_SOURCE_DIR}/Breakout/vendor/glm
    ${CMAKE_SOURCE_DIR}/Breakout/vendor/stb
)

set(SOURCES #
    Breakout/src/main.cpp
)

set(HEADERS #
    Breakout/src/test.h
    Breakout/vendor/Glad/include/glad/glad.h
    Breakout/vendor/stb/stb_image.h
)

add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})

set(GLFW_BUILD_DOCS OFF CACHE BOOL "GLFW lib only")
set(GLFW_BUILD_TESTS OFF CACHE BOOL "GLFW lib only")
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "GLFW lib only")
set(GLFW_INSTALL OFF CACHE BOOL "GLFW lib only")

# GLFW
add_subdirectory(Breakout/vendor/GLFW)
target_link_libraries(${PROJECT_NAME} glfw)

add_subdirectory(Breakout/vendor/Glad)
target_link_libraries(${PROJECT_NAME} glad)

set(CMAKE_EXPORT_COMPILE_COMMANDS YES)
