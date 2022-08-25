#include "header.h"
#include <locale.h>

int main()
{
    setlocale(LC_ALL,"Russian");
    printf("Привет! Эта программа решает квадратные уравнения.");

    while(true)
    {
        double a=NAN,b=NAN,c=NAN;
        double x1 = RANDOM_1,x2 = RANDOM_2;
        printf("%lg\n", x1);

        number_of_roots rootnumb=ROOT_ERROR;

        bool ok_input = enter(&a, &b, &c);

        if(ok_input != 0)
        {
            rootnumb = solve_eq(a, b, c, &x1, &x2);
            output(x1, x2, rootnumb);
        }
        else
        {
            continue;
        }
    }
 }
