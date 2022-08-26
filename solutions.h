/**
@brief Solves square equations.

@details This function receives three coefficients of square equation,
calculates roots and returns number of roots.

@param a   coefficient
@param b   coefficient
@param c   coefficient
@param *x1 pointer of 1st root
@param *x2 pointer of 2st root

@return number_of_roots
*/
int solve_eq(const double a, const double b, const double c, double* x1, double* x2);
