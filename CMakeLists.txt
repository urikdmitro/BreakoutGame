cmake_minimum_required(VERSION 3.26)

set(PROJECT_NAME Breakout_Game)
project(${PROJECT_NAME})

set(SOURCES #
    # Breakout/src/main.cpp
    Breakout/src/Core/entry_point.cpp
    Breakout/src/Core/application.cpp
    Breakout/src/Core/window.cpp
    Breakout/src/Core/log.cpp
    Breakout/src/Events/event.cpp
    Breakout/src/Events/event_dispatcher.h
    Breakout/src/Events/window_events.cpp
    Breakout/src/Events/mouse_events.cpp
    Breakout/src/Events/key_events.cpp
    # Breakout/src/Core/resources.cpp
    # Breakout/src/Renderer/renderer.cpp
    # Breakout/src/Renderer/shader.cpp
    # Breakout/src/Renderer/texture.cpp
    # Breakout/src/Renderer/vertex_array.cpp
    # Breakout/src/Renderer/vertex_buffer.cpp
    Breakout/vendor/stb/stb_image.cpp
    Breakout/src/Platform/Linux/GLFW/window_glfw.cpp
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
        ${CMAKE_SOURCE_DIR}/Breakout/src/Core
        ${CMAKE_SOURCE_DIR}/Breakout/src/Renderer
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
