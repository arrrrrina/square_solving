#include <stdio.h>
#include <assert.h>
#include <cmath>
#include <math.h>

int enter(double *a, double *b, double *c);
int solve_eq(double a,double b,double c, double* x1, double* x2);
void output( double x1, double x2, int rootnumb);
void clear_stream();
bool comparison(double a, double b);

enum number_of_roots
{
    ROOT_ZERO,
    ROOT_ONE,
    ROOT_TWO,
    ROOT_INF,
    ROOT_ERROR
};

