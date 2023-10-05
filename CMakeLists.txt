cmake_minimum_required(VERSION 3.26)

set(PROJECT_NAME Breakout_Game)
project(${PROJECT_NAME})

set(SOURCES #
    Breakout/src/main.cpp
    Breakout/src/Core/log.cpp
    Breakout/src/Renderer/resources.cpp
    Breakout/src/Renderer/renderer.cpp
    Breakout/src/Renderer/shader.cpp
    Breakout/src/Renderer/texture.cpp
    Breakout/src/Renderer/vertex_array.cpp
    Breakout/src/Renderer/vertex_buffer.cpp
    Breakout/vendor/stb/stb_image.cpp
)

set(HEADERS #
    Breakout/vendor/glad/include/glad/glad.h
    Breakout/vendor/stb/stb_image.h
    Breakout/src/Core/log.h
)

add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})

add_subdirectory(Breakout/vendor/glad)
target_link_libraries(${PROJECT_NAME} glad)

target_include_directories(
    ${PROJECT_NAME}
    PRIVATE
        ${CMAKE_SOURCE_DIR}/Breakout
        ${CMAKE_SOURCE_DIR}/Breakout/vendor/
        ${CMAKE_SOURCE_DIR}/Breakout/vendor/glm
)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "GLFW lib only")
set(GLFW_BUILD_TESTS OFF CACHE BOOL "GLFW lib only")
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "GLFW lib only")
set(GLFW_INSTALL OFF CACHE BOOL "GLFW lib only")

add_subdirectory(Breakout/vendor/GLFW)
target_link_libraries(${PROJECT_NAME} glfw)
add_subdirectory(Breakout/vendor/spdlog)
target_link_libraries(${PROJECT_NAME} spdlog)
