/**
@brief Reads new tests from file and run them

@details This function receives new string from
         the file and sent for testing on solving square equation function.
*/
void running_new_tests();

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
