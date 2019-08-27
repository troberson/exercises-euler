# CMake files adapted from modern-cmake example by Henry Schreiner:
# https://gitlab.com/CLIUtils/modern-cmake/tree/master/examples/extended-project

# Works with 3.11 and tested through 3.15
cmake_minimum_required(VERSION 3.11...3.15)

# Project name and a few useful settings. Other commands can pick up the results
project(Euler
    VERSION 0.1
    DESCRIPTION "Project Euler Solutions"
    LANGUAGES CXX)

# Only do these if this is the main project, and not if it is included through add_subdirectory
if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
    # Let's ensure -std=c++xx instead of -std=g++xx
    set(CMAKE_CXX_EXTENSIONS OFF)

    # Let's nicely support folders in IDE's
    set_property(GLOBAL PROPERTY USE_FOLDERS ON)

    # Testing only available if this is the main app
    # Note this needs to be done in the main CMakeLists
    # since it calls enable_testing, which must be in the
    # main CMakeLists.
    include(CTest)

    # Docs only available if this is the main app
    # find_package(Doxygen)
    # if(Doxygen_FOUND)
	# add_subdirectory(docs)
    # else()
	# message(STATUS "Doxygen not found, not building docs")
    # endif()
endif()


# FetchContent added in CMake 3.11, downloads during the configure step
include(FetchContent)
# FetchContent_MakeAvailable was not added until CMake 3.14
if(${CMAKE_VERSION} VERSION_LESS 3.14)
    include(cmake/add_FetchContent_MakeAvailable.cmake)
endif()


# The compiled library code is here
add_subdirectory(src)

# The executable code is here
#add_subdirectory(apps)

# Testing only available if this is the main app
# Emergency override EULER_BUILD_TESTING provided as well
if((CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME OR EULER_BUILD_TESTING) AND BUILD_TESTING)
    add_subdirectory(tests)
endif()

