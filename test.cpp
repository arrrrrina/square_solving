#include "header.h"

#define root_numberIS_right true
#define root_numberNOT_right false

bool Test(const double a, const double b, const double c,
          number_of_roots root_numb_right, const double x1_right, const double x2_right)
{
    double x1_testing = RANDOM_1, x2_testing = RANDOM_2 ;
    number_of_roots root_numb_testing = ROOT_ERROR;
    bool checker_x1 = 1, checker_x2 = 1;

    root_numb_testing = solve_eq(a, b, c, &x1_testing, &x2_testing);

    switch(root_numb_testing == root_numb_right)
    {
        case root_numberIS_right:
        {
            checker_x1 = (are_equal(x1_right, x1_testing))?1:0;
            checker_x2 = (are_equal(x2_right, x2_testing))?1:0;

            if(checker_x1 == 0 || checker_x2 == 0)
            {
                printf("\nError in calculating roots.\nTesting data: %d %lg %lg\n"
                       "Right data: %d %lg %lg",
                        root_numb_testing, x1_testing, x2_testing,
                        root_numb_right, x1_right, x2_right);
                return 1;
            }
            return 0;
        }
        case root_numberNOT_right:
        {
            printf("\nError in calculating number of roots in case(a, b, c) = %lg %lg %lg.\nTesting data(nroots, x1, x2): %d %lg %lg\n"
                       "Right data: %d %lg %lg",
                        a, b, c,
                        root_numb_testing, x1_testing, x2_testing,
                        root_numb_right, x1_right, x2_right);
            return 1;
        }
        default:
        {
            printf("\nERROR IS NOT DEFINED");
            return 1;
        }
    }
}


void getting_new_tests()
{
    double a_file = NAN, b_file = NAN, c_file = NAN, x1_file = NAN, x2_file = NAN;
    char end_file[100];
    char marker_end[]="end_of_tests";
    number_of_roots rootN_file = ROOT_ERROR;
    int failed_tests = 0;

    FILE *stream;

    stream = fopen("testing_data.txt","r");
    while(fscanf(stream,"%lg %lg %lg %d %lg %lg", &a_file, &b_file, &c_file, &rootN_file, &x1_file, &x2_file) == 6)
    {
        failed_tests += Test(a_file, b_file, c_file, rootN_file, x1_file, x2_file);
    }
    fscanf(stream,"%s",&end_file);
    if(strcmp(end_file, marker_end) == 0)
    {
        fclose(stream);
        printf("\n%d are failed\n", failed_tests);
    }

}

