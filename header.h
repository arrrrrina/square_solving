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

void getting_new_tests();

/**
@brief Orginizes input

@detailed This function recieves three arguments and cheks if they're double digits.

@param a coefficient
@param b coefficient
@param c coefficient

@return 1(right input) or 0(wrong input)
*/
int enter(double *a, double *b, double *c);

/**
@brief Solves square equations.

@detailed This function recieves three coefficients of square equation,
calculates roots and returns number of roots.

@param a a - coefficient
@param b b - coefficient
@param c c - coefficient
@param *x1 *x1- pointer of 1st root
@param *x2 *x2- pointer of 2st root

@return number_of_roots
*/
number_of_roots solve_eq(const double a, const double b, const double c, double* x1, double* x2);

bool are_equal(double a, double b);

/**
@brief Orginizes output

@detailed

@param a coefficient
@param b coefficient

@return true if a == b(for float and double)
*/
void output(double x1, double x2, number_of_roots rootnumb);

bool Test(const double a, const double b, const double c,
          const double root_numb_right, const double x1_right,
          const double x2_right);
