# Require at least CMake version 3.16.
cmake_minimum_required(VERSION 3.16)

# Define the project name and enable C++ as the programming language.
project(SdaLab01VoltageUtils LANGUAGES CXX)

# Use the C++17 language standard.
set(CMAKE_CXX_STANDARD 17)

# Require C++17 support; do not fall back to an older standard.
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Disable compiler-specific language extensions (e.g., GNU extensions).
set(CMAKE_CXX_EXTENSIONS OFF)

# ------------------------------------------------------------
# 1. Library
# ------------------------------------------------------------

# Create a library target named "voltage_utils".
add_library(voltage_utils src/VoltageUtils.cpp)

# Specify where the compiler can find the library's header files.
#
# PUBLIC means:
# - The library itself uses this include directory.
# - Other targets linking to this library inherit it as well.
#
# CMAKE_CURRENT_SOURCE_DIR refers to the directory containing
# this CMakeLists.txt file.
target_include_directories(voltage_utils
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)


# ------------------------------------------------------------
# 2. Application
# ------------------------------------------------------------

# Create an executable target named "voltage_demo".
# Its entry point (main function) is defined in app/main.cpp.
add_executable(voltage_demo app/main.cpp)

# Link the application against our voltage_utils library.
#
# PRIVATE means that this dependency is used by voltage_demo
# but is not propagated to targets depending on voltage_demo.
#
# The application can now use the library's functions.
target_link_libraries(voltage_demo PRIVATE voltage_utils)


# ------------------------------------------------------------
# 3. Testing Infrastructure
# ------------------------------------------------------------

# Load CMake's CTest module.
# This enables testing support and provides the BUILD_TESTING option.
#
# BUILD_TESTING is ON by default.
# It can be disabled using: -DBUILD_TESTING=OFF
include(CTest)

# Only configure and build the tests when testing is enabled.
if(BUILD_TESTING)

    # Load CMake's FetchContent module.
    # FetchContent allows external dependencies to be downloaded
    # and integrated into the project during configuration.
    include(FetchContent)

    # Declare GoogleTest as an external dependency.
    #
    # We use a specific version to make builds reproducible.
    # DOWNLOAD_EXTRACT_TIMESTAMP TRUE assigns extraction timestamps
    # to downloaded files instead of preserving archive timestamps.
    FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/refs/tags/v1.15.2.zip
        DOWNLOAD_EXTRACT_TIMESTAMP TRUE
    )

    # Download GoogleTest (if necessary) and make its CMake
    # targets available to our project.
    FetchContent_MakeAvailable(googletest)


    # --------------------------------------------------------
    # 4. Test Executable
    # --------------------------------------------------------

    # Create a separate executable containing our unit tests.
    # The test cases are implemented in test_voltage_utils.cpp.
    add_executable(voltage_tests tests/test_voltage_utils.cpp)

    # Link the test executable against:
    #
    # voltage_utils:
    #   The library containing the functions we want to test.
    #
    # GTest::gtest_main:
    #   GoogleTest library including a predefined main() function.
    #   Therefore, we do not need to write our own test main().
    target_link_libraries(voltage_tests PRIVATE voltage_utils GTest::gtest_main)

    # Load CMake's GoogleTest integration module.
    include(GoogleTest)

    # Automatically discover GoogleTest test cases and register
    # them with CTest.
    #
    # This allows us to run all tests using the "ctest" command.
    gtest_discover_tests(voltage_tests)

endif()
