# Testing library
FetchContent_Declare(
catch2
GIT_REPOSITORY https://github.com/catchorg/Catch2.git
GIT_TAG        v2.9.1
)
FetchContent_MakeAvailable(catch2)

add_executable(euler_test
    test_main.cpp
    euler001_test.cpp
    euler002_test.cpp
    euler003_test.cpp
    euler004_test.cpp
    euler005_test.cpp
    euler006_test.cpp
    euler007_test.cpp
    euler008_test.cpp
    euler009_test.cpp
    euler010_test.cpp
    euler011_test.cpp
    euler012_test.cpp
    euler013_test.cpp
)

# I'm using C++17 in the test
target_compile_features(euler_test PRIVATE cxx_std_17)

# Should be linked to the main library, as well as the Catch2 testing library
target_link_libraries(euler_test PRIVATE euler_utils euler Catch2::Catch2)

# If you register a test, then ctest and make test will run it.
# You can also run examples and check the output, as well.
add_test(NAME euler_test_all COMMAND euler_test) # Command can be a target

# Build utils_tests
add_subdirectory(utils_tests)
