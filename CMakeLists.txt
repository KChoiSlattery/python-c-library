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

# Make library "example"
add_library(example STATIC src/example/example.cpp src/example/example.hpp)
target_include_directories(example PUBLIC src/example)
target_compile_features(example PUBLIC cxx_std_20)
target_link_libraries(example PRIVATE Eigen3::Eigen)

# Make the module
pybind11_add_module(python_c_library src/bindings.cpp)

# Link eigen and custom libraries
target_link_libraries(python_c_library PRIVATE Eigen3::Eigen)
target_link_libraries(python_c_library PRIVATE example)

install(TARGETS python_c_library
    LIBRARY DESTINATION .
    RUNTIME DESTINATION .
)