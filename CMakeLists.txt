cmake_minimum_required(VERSION 3.18...4.1)
project(python_c_library LANGUAGES CXX)

# Setup Pybind11
set(PYBIND11_FINDPYTHON ON)
find_package(pybind11 CONFIG REQUIRED)

# Use Eigen, from https://stackoverflow.com/questions/65860094/how-to-add-eigen-library-to-a-cmake-c-project-via-fetchcontent
include(FetchContent)

FetchContent_Declare(
    eigen
    GIT_REPOSITORY https://gitlab.com/libeigen/eigen.git
    GIT_TAG        5.0.0   # Use the latest stable release
    GIT_SHALLOW    TRUE
)
FetchContent_MakeAvailable(eigen)

set(BUILD_TESTING OFF)
set(EIGEN_BUILD_TESTING OFF)
set(EIGEN_MPL2_ONLY ON)
set(EIGEN_BUILD_PKGCONFIG OFF)
set(EIGEN_BUILD_DOC OFF)

# Make library "lib"
# add_library(lib STATIC src/lib/lib.cpp src/lib/lib.hpp)
# target_include_directories(lib PUBLIC src/lib)
# target_compile_features(lib PUBLIC cxx_std_20)

# Make the module
pybind11_add_module(python_c_library src/example.cpp)

target_link_libraries(python_c_library PRIVATE Eigen3::Eigen)

install(TARGETS python_c_library
    LIBRARY DESTINATION .
    RUNTIME DESTINATION .
)