# Set the minimum CMake version
cmake_minimum_required(VERSION 3.10)

set(ExecName DataProcessing)

# Set the project name
project(${ExecName})

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)

add_subdirectory(helpers)

# Add the executable target
add_executable(${ExecName}
    main.cpp
    ${HELPERS_FILES}
)

target_include_directories( ${ExecName} PRIVATE
    helpers
)