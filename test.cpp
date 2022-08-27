#include "test.h"
#include "enum_constants.h"

#define NAME_OF_FILE "testing_data.txt"

/**
@brief Reads new tests from file and run them

@details This function receives new string from
         the file and sent for testing on solving square equation function.
*/
static void running_new_tests();

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
static bool test(const double a, const double b, const double c,
          int root_numb_right, const double x1_right,
          const double x2_right);

static bool test(const double a, const double b, const double c,
          int root_numb_right, const double x1_right, const double x2_right)
{
    double x1_testing = FIRST_VALUE_X1, x2_testing = FIRST_VALUE_X2;
    int root_numb_testing = ROOT_ERROR;
    bool checker_x1 = 1, checker_x2 = 1;

    root_numb_testing = solve_eq(a, b, c, &x1_testing, &x2_testing);

    if(root_numb_testing == root_numb_right)
    {

        checker_x1 = are_equal(x1_right, x1_testing);
        checker_x2 = are_equal(x2_right, x2_testing);

        if(checker_x1 == 0 || checker_x2 == 0)
        {
            printf("Error in calculating roots.\nTesting data: %d %lg %lg\n"
                   "Right data: %d %lg %lg\n",
                    root_numb_testing, x1_testing, x2_testing,
                    root_numb_right, x1_right, x2_right);
            return 1;
        }
        return 0;
    }
    else
    {
        printf("Error in calculating number of roots in case(a, b, c) = %lg %lg %lg.\nTesting data(nroots, x1, x2): %d %lg %lg\n"
                   "Right data: %d %lg %lg\n",
                    a, b, c,
                    root_numb_testing, x1_testing, x2_testing,
                    root_numb_right, x1_right, x2_right);
        return 1;
    }
}

static void running_new_tests()
{
    double a_file = NAN, b_file = NAN, c_file = NAN, x1_file = NAN, x2_file = NAN;
    char end_file[200];
    int rootN_file = ROOT_ERROR;
    int failed_tests = 0;

    FILE *stream;

    stream = fopen(NAME_OF_FILE,"r");
    while(fscanf(stream,"%lg %lg %lg %d %lg %lg", &a_file, &b_file, &c_file, &rootN_file, &x1_file, &x2_file) == 6)
    {
        failed_tests += test(a_file, b_file, c_file, rootN_file, x1_file, x2_file);
    }

        fclose(stream);
        printf("%d are failed\n", failed_tests);
}

