#include <pybind11/pybind11.h>
#include <pybind11/eigen.h>
#include <Eigen/Dense>

using Eigen::Matrix;
using Eigen::Vector;
using Eigen::Dynamic;

namespace py = pybind11;

int add(int a, int b) {
    // Add two integers. Example of a function that takes two scalars and returns a scalar.
    return a+b;
}

double sum_vec(Vector<double, Dynamic> vec) { // Can also use Eigen::VectorXd for dynamic-size double-precision
    return vec.sum();
}

Vector<double, 3> cross(Vector<double, 3> a, Vector<double, 3> b) {
    Vector<double, 3> out;
    out(0) = a(1)*b(2)-a(2)*b(1);
    out(1) = a(2)*b(0)-a(0)*b(2);
    out(2) = a(0)*b(1)-a(1)*b(0);
    return out;
}

PYBIND11_MODULE(python_c_library, m) {
    m.doc() = "Minimal example module";
    m.def("add", &add, "Add two integers");
    
    m.def("sum_vec", &sum_vec, "Sum a vector, assumes floating-point");
    m.def("cross", &cross, "Cross-product of 2 3D vectors");
}