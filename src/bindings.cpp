#include <pybind11/pybind11.h>
#include <pybind11/eigen.h>
#include "example.hpp"

namespace py = pybind11;

PYBIND11_MODULE(python_c_library, m) {
    m.doc() = "Minimal example module";

    // Bind functions from "example"
    m.def("add", &example::add, "Add two integers");
    m.def("sum_vec", &example::sum_vec, "Sum a vector, assumes floating-point");
    m.def("cross", &example::cross, "Cross-product of 2 3D vectors");
}