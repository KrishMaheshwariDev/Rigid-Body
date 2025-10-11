cmake_minimum_required(VERSION 3.10)
project(RigidBody)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Paths
set(SRC_DIR "${CMAKE_SOURCE_DIR}/src")
set(INCLUDE_DIR "${CMAKE_SOURCE_DIR}/include")
set(LIB_DIR "${CMAKE_SOURCE_DIR}/lib")

include_directories(
    ${INCLUDE_DIR}
    ${LIB_DIR}/glad/include
    ${LIB_DIR}/glfw/include
    ${LIB_DIR}/glm
)

# Source files
file(GLOB_RECURSE SOURCES ${SRC_DIR}/*.cpp)

# Executable
add_executable(${PROJECT_NAME} ${SOURCES})

# GLAD library
add_library(glad ${LIB_DIR}/glad/src/glad.c)
target_include_directories(glad PUBLIC ${LIB_DIR}/glad/include)

# Link GLFW library and OpenGL
find_package(OpenGL REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE glad ${LIB_DIR}/glfw/glfw3.lib ${OPENGL_LIBRARIES})
