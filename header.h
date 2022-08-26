#include <stdio.h>
#include <assert.h>
#include <cmath>
#include <fcntl.h>
#include <string.h>

#define RANDOM_1 512
#define RANDOM_2 444

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
@brief Reads new tests from file

@details This function recieves new string from
 the file and sent for testing on solving square equation function.

*/
void getting_new_tests();

/**
@brief Orginizes input

@details This function recieves three arguments and cheks if they're double digits.

@param a coefficient
@param b coefficient
@param c coefficient

@return 1(right input) or 0(wrong input)
*/
int enter(double *a, double *b, double *c);

/**
@brief Solves square equations.

@details This function recieves three coefficients of square equation,
calculates roots and returns number of roots.

@param a   coefficient
@param b   coefficient
@param c   coefficient
@param *x1 pointer of 1st root
@param *x2 pointer of 2st root

@return number_of_roots
*/
int solve_eq(const double a, const double b, const double c, double* x1, double* x2);

/**
@brief Compare double digits

@details This function finds difference between 2 double digits and defines is it suitable.

@param a 1st digit fir comparing
@param b 2nd digit for comparing

*/
bool are_equal(double a, double b);

/**
@brief Outputs results of calculating roots

@param x1 1st root
@param x2 2nd root
@param rootnumb number of roots

@return 1 if digits are equal
@brief Orginizes output

@detailed

@param a coefficient
@param b coefficient

@return true if a == b(for float and double)
*/
void output(double x1, double x2, int rootnumb);

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
bool Test(const double a, const double b, const double c,
          int root_numb_right, const double x1_right,
          const double x2_right);


