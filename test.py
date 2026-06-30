import numpy as np
import python_c_library as lib

print(lib.add(5,3))

print(lib.sum_vec(np.array([3.6,7.2,5.0])))

a = np.random.randn(3)
b = np.random.randn(3)

c = lib.cross(a,b)

print(c)
print(a.T @ c)
print(b.T @ c)