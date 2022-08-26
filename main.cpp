#include "usefull_functions.h"
#include <locale.h>

int stream_left();

int stream_left()
{
    int character = 0;
    int char_numb = 0;
    while((character = getchar()) != '\n')
        char_numb++;

    return char_numb;
}

int main()
{
    setlocale(LC_ALL,"Russian");
    printf("Привет! Эта программа решает квадратные уравнения.\n"
           "\nЧтобы начать решать уравнения, введи # + enter.\n"
           "Чтобы выйти из программы, введи * + enter.\n");

    while(true)
    {
        double a = NAN,b = NAN,c = NAN;
        double x1 = FIRST_VALUE_X1,x2 = FIRST_VALUE_X2;
        int indicator = 0;
        int buf = 0;

        indicator = getchar();
        buf = getchar();
       // printf("indicator: <%c> (%d)\n" "buf: <%c> (%d)\n", indicator, indicator, buf, buf);

        if(buf != '\n')
        {
            printf("Команда не распознана. Введи один символ.\n");
            //clear_stream();
        }
        else if(indicator == '#')
        {
            int rootnumb = ROOT_ERROR;
            //clear_stream();
            bool ok_input = enter(&a, &b, &c);

            if(ok_input != 0 and indicator == '#')
            {
                rootnumb = solve_eq(a, b, c, &x1, &x2);
                output(x1, x2, rootnumb);
            }
            else
            {
                continue;
            }
        }
        else if (indicator == '*')
            {
                return 0;
            }
        else
            printf("Команда не распознана. Введите * + enter или # + enter.\n");
    }
    return 0;
 }
