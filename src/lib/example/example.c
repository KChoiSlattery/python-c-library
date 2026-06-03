#include "example.h"

float mult(float x, float y)
{
    return x * y;
}


float sum_arr(float *arr, int len)
{
    float out = 0;
    for (int i = 0; i < len; i++)
    {
        out += arr[i];
    }
    return out;
}

// TODO: write outer_product 