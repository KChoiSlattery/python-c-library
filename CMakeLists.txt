cmake_minimum_required(VERSION 3.20)
project(python_c_library LANGUAGES CXX)

set(PYBIND11_FINDPYTHON ON)
find_package(pybind11 CONFIG REQUIRED)

pybind11_add_module(python_c_library src/example.cpp)

install(TARGETS python_c_library
    LIBRARY DESTINATION .
    RUNTIME DESTINATION .
)