
# Note that headers are optional, and do not affect add_library, but they will not
# show up in IDEs unless they are listed in add_library.

# Optionally glob, but only for CMake 3.12 or later:
# file(GLOB HEADER_LIST CONFIGURE_DEPENDS "${ModernCMakeExample_SOURCE_DIR}/include/modern/*.hpp")
set(header_dir "${Euler_SOURCE_DIR}/include/euler/utils/")
set(HEADER_LIST
    ${header_dir}/factors.hpp
    ${header_dir}/lists.hpp
    ${header_dir}/maps.hpp
    ${header_dir}/maths.hpp
    ${header_dir}/primes.hpp
    ${header_dir}/strings.hpp
    ${header_dir}/sum.hpp
    ${header_dir}/template_types.hpp
    ${header_dir}/recurrence.hpp
)

# Make an automatic library - will be static or dynamic based on user setting
add_library(euler_utils
    strings.cpp
    sum.cpp
    recurrence.cpp
    ${HEADER_LIST}
)

# We need this directory, and users of our library will need it too
target_include_directories(euler_utils PUBLIC ${Euler_SOURCE_DIR}/include)

# Use C++17
target_compile_features(euler_utils PRIVATE cxx_std_17)

# IDEs should put the headers in a nice place
source_group(TREE "${PROJECT_SOURCE_DIR}/include" PREFIX "Header Files" FILES ${HEADER_LIST})
