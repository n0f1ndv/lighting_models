cmake_minimum_required(VERSION 3.15)
project(LightingModels VERSION 1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(app
    src/main.cpp
    src/shader.cpp
    src/window.cpp
    src/clock.cpp
    src/renderer.cpp
    src/camera.cpp
    src/scene.cpp
    src/gui.cpp
    libs/glad/glad.c
    libs/imgui/imgui.cpp
    libs/imgui/imgui_demo.cpp
    libs/imgui/imgui_draw.cpp
    libs/imgui/imgui_tables.cpp
    libs/imgui/imgui_widgets.cpp
    libs/imgui/backends/imgui_impl_glfw.cpp
    libs/imgui/backends/imgui_impl_opengl3.cpp
)

target_include_directories(app PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

# Using vendor libraries may vary so check out the documentation for instructions.
# Vendor libraries that are header only:
# target_include_directories(${PROJECT_NAME} SYSTEM PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/libs)

# Vendor libraries are git submodules
# add_subdirectory(libs)
# target_link_libraries(${PROJECT_NAME} PUBLIC name_of_vendor_library)

target_include_directories(app SYSTEM PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/libs/imgui/backends)
target_include_directories(app SYSTEM PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/libs/imgui)
target_include_directories(app SYSTEM PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/libs/glm)
target_include_directories(app SYSTEM PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/libs)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/libs/glfw)
target_link_libraries(app glfw)