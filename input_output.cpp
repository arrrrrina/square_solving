#include "usefull_functions.h"

int enter(double *a, double *b, double *c)
{
    printf("����� ����� ������ ����������� ��������� a,b � c.\n(�� ����� ������ ��������, ������ ����� ���������� ����� ������� �� ���������)\n");
    int is_digits = scanf("%lg%lg%lg", a, b, c);
    if (is_digits != 3)
    {
        printf("����������� ������� ������. ������� 3 �����.\n");
        printf("����� ���������� ������� # + enter, ����� ���������, ����� * + enter.\n");;

        return 0;
    }
    int left_symb = 0;
    int left_numb = 0;
    while((left_symb = getchar()) != '\n')
        left_numb++;
    if(left_numb != 0)
    {
        printf("����������� ������� ������. ������� 3 �����. ������ ����� ���������� ����� ������� �� ���������. \n");
        printf("����� ����������, # + enter, ����� ���������, ����� * + enter.\n");
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
            printf("������� ���.\n");
            printf("����� ����������, # + enter, ����� ���������, ����� * + enter.\n");            break;
        case ROOT_ONE:
            assert(std::isfinite(x1));
            printf("��������� ����� 1 �������: � = %.5lg\n", x1);
            printf("����� ����������, # + enter, ����� ���������, ����� * + enter.\n");
            break;
        case ROOT_TWO:
            assert(std::isfinite(x1));
            assert(std::isfinite(x2));
            printf("��������� ����� 2 �������: �1 = %.5lg, �2 = %.5lg\n", x1, x2);
            printf("����� ����������, # + enter, ����� ���������, ����� * + enter.\n");
            break;
        case ROOT_INF:
            printf("��������� ����� ���������� ����� �������.\n");
            printf("����� ����������, # + enter, ����� ���������, ����� * + enter.\n");
            break;
        case ROOT_ERROR:
        default:
            printf("������\n");
            assert(false);
    }
}
