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

/**
@brief Compare double digits

@details This function finds difference between 2 double digits and defines is it suitable.

@param a 1st digit fir comparing
@param b 2nd digit for comparing

*/
bool are_equal(double a, double b);
