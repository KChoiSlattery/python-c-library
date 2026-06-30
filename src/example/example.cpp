#include <Eigen/Dense>
#include "example.hpp"

using Eigen::Matrix;
using Eigen::Vector;
using Eigen::Dynamic;

namespace example {
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
}