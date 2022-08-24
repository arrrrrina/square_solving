#include "declaration.h"

int enter(double *a, double *b, double *c)
{
    printf("\nВведи коэффиценты уравнения a,b и c:\n");
    int is_digits = scanf("%lg%lg%lg", a, b, c);
    if (is_digits != 3)
    {
        printf("Неправильно введены данные. Введите 3 числа.");
        clear_stream();
        return 0;
    }
    return 1;
}

void clear_stream()
{
    char stream = ' ';
    while ((stream = getchar()) != '\n')
    ;
}

void output(double x1, double x2, int rootnumb)
{
    switch(rootnumb)
    {
        case ROOT_ZERO:
            printf("\nРешений нет.");
            break;
        case ROOT_ONE:
            printf("\nУравнение имеет 1 решение: х = %lg", x1);
            break;
        case ROOT_TWO:
            printf("\nУравнение имеет 2 решения: х1 = %lg, х2 = %lg", x1, x2);
            break;
        case ROOT_INF:
            printf("\nУравнение имеет бесконечно много решений.");
            break;
        case ROOT_ERROR:
        default:
            printf("\nОшибка");
    }
}

int solve_eq(double a, double b, double c, double* x1, double* x2)
{
    double diskr = NAN;
    bool right_digits = (std::isfinite(a) && std::isfinite(b) && std::isfinite(c) && (x2!=x1));
    //printf("%lg", diskr);
    if(right_digits == 0)
        {
            return 4;
        }
    if (comparison(a,0))
    {
        if (!comparison(b,0))
        {
            *x1 = -c / b;
            return 1;
        }
        else if(comparison(b,0) && comparison(c,0))
        {
            return ROOT_INF;
        }
        else return 0;
    }

    else diskr = b*b - 4*a*c;

    if(diskr > 0)
    {
        *x1 = (-b + sqrt(diskr))/(2*a);
        *x2 = (-b - sqrt(diskr))/(2*a);
        return 2;
    }
    if(diskr < 0)
    {
        return 0;
    }

    if( comparison(diskr,0))
    {
    *x1 = -b/(2*a);
    return 1;
    }
    return 4;
}
bool comparison(double a, double b)
{
    if ((max(a,b)-min(a,b)) <= 1e-6)
    {
        return 1;
    }
    return 0;
}
