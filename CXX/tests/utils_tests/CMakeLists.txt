add_executable(euler_utils_test
    ../test_main.cpp
    factors_test.cpp
    primes_test.cpp
    strings_test.cpp
    sumMult_test.cpp
    recurrence_test.cpp
)

# I'm using C++17 in the test
target_compile_features(euler_utils_test PRIVATE cxx_std_17)

# Should be linked to the main library, as well as the Catch2 testing library
target_link_libraries(euler_utils_test PRIVATE euler_utils Catch2::Catch2)

# If you register a test, then ctest and make test will run it.
# You can also run examples and check the output, as well.
add_test(NAME euler_utils_test_all COMMAND euler_utils_test) # Command can be a target
