/**
 * \defgroup example
 * \ingroup lib
 * 
 * \author Kieran Choi-Slattery
 * 
 * @{
 * Simple functions that demonstrate documentation and c function syntax, as well as providing targets to test with test_example_funcs
 */

#ifndef __EXAMPLE_FUNCS_H__
#define __EXAMPLE_FUNCS_H__

/// @brief Returns the product of x and y. This is an example of a function that takes two scalar inputs and returns a scalar value.
/// @param x 
/// @param y 
/// @return the product of x and y
float mult(float x, float y);

/// @brief Returns the sum of arr. This is an example of a function that takes an array input and returns a scalar value.
/// @param arr array to sum
/// @param len number of elements to sum
/// @return the sum of all elements of arr
float sum_arr(float *arr, int len);

#endif /* __EXAMPLE_FUNCS_H__ */