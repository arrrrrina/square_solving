#include <stdio.h>
#include <assert.h>
#include <cmath>
#include <fcntl.h>
#include <string.h>

const double FIRST_VALUE_X1 = 512;
const double FIRST_VALUE_X2 = 444;
const double SMALL_DIGIT = 1e-7;

enum number_of_roots
{
    ROOT_ZERO,
    ROOT_ONE,
    ROOT_TWO,
    ROOT_INF,
    ROOT_ERROR
};



