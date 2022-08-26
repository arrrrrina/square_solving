#include "header.h"

static void clear_stream();

int enter(double *a, double *b, double *c)
{
    printf("\n����� ����������� ��������� a,b � c:\n");
    int is_digits = scanf("%lg%lg%lg", a, b, c);
    if (is_digits != 3)
    {
        printf("����������� ������� ������. ������� 3 �����.");
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
            printf("\n������� ���.");
            break;
        case ROOT_ONE:
            assert(std::isfinite(x1));
            printf("\n��������� ����� 1 �������: � = %.5lg", x1);
            break;
        case ROOT_TWO:
            assert(std::isfinite(x1));
            assert(std::isfinite(x2));
            printf("\n��������� ����� 2 �������: �1 = %.5lg, �2 = %.5lg", x1, x2);
            break;
        case ROOT_INF:
            printf("\n��������� ����� ���������� ����� �������.");
            break;
        case ROOT_ERROR:
        default:
            printf("\n������");
    }
}
