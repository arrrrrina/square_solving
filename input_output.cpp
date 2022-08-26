#include "header.h"

static void clear_stream();

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
    assert(std::isfinite(*a));
    assert(std::isfinite(*b));
    assert(std::isfinite(*c));
    assert(a!=0 && b!=0 && c!=0);
    assert(a!=b && b!=c && a!=c);

    return 1;
}

static void clear_stream()
{
    int stream = 0;
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
            assert(std::isfinite(x1));
            printf("\nУравнение имеет 1 решение: х = %.5lg", x1);
            break;
        case ROOT_TWO:
            assert(std::isfinite(x1));
            assert(std::isfinite(x2));
            printf("\nУравнение имеет 2 решения: х1 = %.5lg, х2 = %.5lg", x1, x2);
            break;
        case ROOT_INF:
            printf("\nУравнение имеет бесконечно много решений.");
            break;
        case ROOT_ERROR:
        default:
            printf("\nОшибка");
    }
}
