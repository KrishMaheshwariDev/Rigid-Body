cmake_minimum_required(VERSION 3.10)
project(RigidBody LANGUAGES C CXX)

# ---------------------------------------------------------
# Compiler setup
# ---------------------------------------------------------
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
add_definitions(-DGLM_ENABLE_EXPERIMENTAL)


# ---------------------------------------------------------
# Directory setup
# ---------------------------------------------------------
set(SRC_DIR "${CMAKE_SOURCE_DIR}/src")
set(INCLUDE_DIR "${CMAKE_SOURCE_DIR}/include")
set(LIB_DIR "${CMAKE_SOURCE_DIR}/lib")

# ---------------------------------------------------------
# Include directories
# ---------------------------------------------------------
include_directories(
    ${INCLUDE_DIR}
    ${LIB_DIR}/glad/include
    ${LIB_DIR}/glfw/include
    ${LIB_DIR}/glm
)

# ---------------------------------------------------------
# Source collection (auto-detects cpp/h inside subfolders)
# ---------------------------------------------------------
file(GLOB_RECURSE SOURCES 
    ${SRC_DIR}/*.cpp
    ${SRC_DIR}/*.c
    ${SRC_DIR}/*.h
)

# ---------------------------------------------------------
# GLAD (C library)
# ---------------------------------------------------------
add_library(glad STATIC ${LIB_DIR}/glad/src/glad.c)
set_target_properties(glad PROPERTIES LINKER_LANGUAGE C)
target_include_directories(glad PUBLIC ${LIB_DIR}/glad/include)

# ---------------------------------------------------------
# Executable target
# ---------------------------------------------------------
add_executable(${PROJECT_NAME} ${SOURCES})

# ---------------------------------------------------------
# Link dependencies
# ---------------------------------------------------------
find_package(OpenGL REQUIRED)
target_link_libraries(${PROJECT_NAME}
    PRIVATE
        glad
        ${LIB_DIR}/glfw/glfw3.lib
        ${OPENGL_LIBRARIES}
)

# ---------------------------------------------------------
# Output directories
# ---------------------------------------------------------
set_target_properties(${PROJECT_NAME} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/out"
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/out/lib"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/out/lib"
)

# ---------------------------------------------------------
# Message summary (optional debug info)
# ---------------------------------------------------------
message(STATUS "Project: ${PROJECT_NAME}")
message(STATUS "C++ Standard: ${CMAKE_CXX_STANDARD}")
message(STATUS "Source Directory: ${SRC_DIR}")
message(STATUS "Library Directory: ${LIB_DIR}")
