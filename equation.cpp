


#include "declaration.h"
#include <locale.h>

int main()
{

    setlocale(LC_ALL,"Russian");
    printf("Привет! Эта программа решает квадратные уравнения.");

    while(true)
    {
        double a=NAN,b=NAN,c=NAN;
        double x1=NAN,x2=NAN;
        int rootnumb=0;
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





