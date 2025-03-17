# Set the minimum CMake version
cmake_minimum_required(VERSION 3.10)

set(ExecName DataProcessing)

# Set the project name
project(${ExecName})

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)



add_subdirectory(helpers)
add_subdirectory(jumps_detection)
add_subdirectory(filtering)

# Add the executable target
add_executable(${ExecName}
    main.cpp
    ${HELPERS_FILES}
    ${FILTERING_FILES}
    ${JUMP_DETECTION_FILES}
)

target_include_directories( ${ExecName} PRIVATE
    helpers
    filtering
    jumps_detection
)


enable_testing()

add_executable(
  jump_test
  jumps_detection/JumpJoiner.h
  jumps_detection/JumpJoiner.cpp
  jumps_detection/JumpDetector.h
  jumps_detection/JumpDetector.cpp
  tests/jump_joiner_test.cpp
  tests/jump_detection_test.cpp
)

target_include_directories(jump_test PRIVATE jumps_detection)

target_link_libraries(
  jump_test
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(jump_test)