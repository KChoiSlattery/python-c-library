#include <pybind11/pybind11.h>

namespace py = pybind11;

int add(int a, int b) {
    return a + b;
}

PYBIND11_MODULE(python_c_library, m) {
    m.doc() = "Minimal example module";
    m.def("add", &add, "Add two integers");
}