#include "usefull_functions.h"

int enter(double *a, double *b, double *c)
{
    printf("Введи через пробел коэффиценты уравнения a,b и c.\n(Не вводи лишних символов, пробел после последнего числа ставить не требуется)\n");
    int is_digits = scanf("%lg%lg%lg", a, b, c);
    if (is_digits != 3)
    {
        printf("Неправильно введены данные. Введите 3 числа.\n");
        printf("Чтобы продолжить нажмите # + enter, чтобы закончить, нажми * + enter.\n");;

        return 0;
    }
    int left_symb = 0;
    int left_numb = 0;
    while((left_symb = getchar()) != '\n')
        left_numb++;
    if(left_numb != 0)
    {
        printf("Неправильно введены данные. Введите 3 числа. Пробел после последнего числа ставить не требуется. \n");
        printf("Чтобы продолжить, # + enter, чтобы закончить, нажми * + enter.\n");
        return 0;
    }
    assert(std::isfinite(*a));
    assert(std::isfinite(*b));
    assert(std::isfinite(*c));
    assert(a!=0 && b!=0 && c!=0);
    assert(a!=b && b!=c && a!=c);

    return 1;
}

void clear_stream()
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
            printf("Решений нет.\n");
            printf("Чтобы продолжить, # + enter, чтобы закончить, нажми * + enter.\n");            break;
        case ROOT_ONE:
            assert(std::isfinite(x1));
            printf("Уравнение имеет 1 решение: х = %.5lg\n", x1);
            printf("Чтобы продолжить, # + enter, чтобы закончить, нажми * + enter.\n");
            break;
        case ROOT_TWO:
            assert(std::isfinite(x1));
            assert(std::isfinite(x2));
            printf("Уравнение имеет 2 решения: х1 = %.5lg, х2 = %.5lg\n", x1, x2);
            printf("Чтобы продолжить, # + enter, чтобы закончить, нажми * + enter.\n");
            break;
        case ROOT_INF:
            printf("Уравнение имеет бесконечно много решений.\n");
            printf("Чтобы продолжить, # + enter, чтобы закончить, нажми * + enter.\n");
            break;
        case ROOT_ERROR:
        default:
            printf("Ошибка\n");
            assert(false);
    }
}
