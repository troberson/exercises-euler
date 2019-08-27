add_subdirectory(utils)

add_library(euler
    euler001.cpp
    euler002.cpp
)

target_link_libraries(euler PRIVATE euler_utils)
