#include <stdio.h>
#include <assert.h>
#include <cmath>
#include <fcntl.h>
#include <string.h>
#include "solutions.h"
#include "input_output.h"

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

/**
@brief Reads new tests from file and run them

@details This function receives new string from
         the file and sent for testing on solving square equation function.
*/
void running_new_tests();

/**
@brief Compare double digits

@details This function finds difference between 2 double digits and defines is it suitable.

@param a 1st digit fir comparing
@param b 2nd digit for comparing

*/
bool are_equal(double a, double b);

/**
@brief checks 1 string of test data with solving square equation function

@param a coefficient
@param b coefficient
@param c coefficient
@param root_numb_right right number of roots from file
@param x1_right right 1st root
@param x2_right right 2nd root

@return 1(accepted) or 0(failed)

*/
bool test(const double a, const double b, const double c,
          int root_numb_right, const double x1_right,
          const double x2_right);
/**
@brief Clears the stream.

@details For right input working this function clears the stream.
*/
void clear_stream();


