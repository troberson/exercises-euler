# Process the utils directory and generate the utils library first
add_subdirectory(utils)

# Compile the main euler library
add_library(euler
    euler001.cpp
    euler002.cpp
    euler003.cpp
    euler004.cpp
    euler005.cpp
    euler006.cpp
    euler007.cpp
    euler008.cpp
    euler009.cpp
    euler010.cpp
    euler011.cpp
    euler012.cpp
)

# Use C++17
target_compile_features(euler PRIVATE cxx_std_17)

# Link with the utils library
target_link_libraries(euler PRIVATE euler_utils)
