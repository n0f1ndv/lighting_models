cmake_minimum_required(VERSION 3.15)
project(ProceduralTerrainGeneration VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

file(GLOB_RECURSE SOURCE_FILES "src/*.cpp")

add_executable(app ${SOURCE_FILES})

target_include_directories(app PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

# Using vendor libraries may vary so check out the documentation for instructions.
# Vendor libraries that are header only:
# target_include_directories(${PROJECT_NAME} SYSTEM PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/libs)

# Vendor libraries are git submodules
# add_subdirectory(libs)
# target_link_libraries(${PROJECT_NAME} PUBLIC name_of_vendor_library)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/libs/glfw)

target_link_libraries(app glfw)