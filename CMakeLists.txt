cmake_minimum_required(VERSION 3.20)
project(untitled)

set(CMAKE_CXX_STANDARD 14)
include_directories("/lib/")
add_executable(untitled src/main.cpp src/utils.cpp src/utils.h src/Shader.cpp src/Shader.h src/Camera.cpp src/Camera.h)

target_compile_options(untitled PRIVATE -Wall)

# glfw
add_subdirectory(lib/glfw EXCLUDE_FROM_ALL)
target_link_libraries(untitled PRIVATE glfw)

# glew
add_definitions(-DGLEW_STATIC)
add_subdirectory(lib/glew EXCLUDE_FROM_ALL)
target_link_libraries(untitled PRIVATE libglew_static)

# glm
add_subdirectory(lib/glm EXCLUDE_FROM_ALL)
target_link_libraries(untitled PRIVATE glm)
