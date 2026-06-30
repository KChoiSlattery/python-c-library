#include <Eigen/Dense>

using Eigen::Matrix;
using Eigen::Vector;
using Eigen::Dynamic;

namespace example
{
    int add(int a, int b);

    double sum_vec(Vector<double, Dynamic> vec);
    
    Vector<double, 3> cross(Vector<double, 3> a, Vector<double, 3> b);
}