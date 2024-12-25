cmake_minimum_required(VERSION 3.10)

project(ChatBoxUI)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

find_package(SFML 3.0 COMPONENTS graphics window system network REQUIRED)

# Include directories
include_directories(${SFML_INCLUDE_DIRS})

# Source Files
set(SOURCE_FILES
    src/main.cpp
)

# Output Executable
add_executable(ChatBoxUI ${SOURCE_FILES})

# Link SFML Libraries
target_link_libraries(ChatBoxUI sfml-graphics sfml-window sfml-system sfml-network)

# Automatically create build directory
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build)
file(MAKE_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})