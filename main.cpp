#include <locale.h>
#include <ctype.h>
#include "enum_constants.h"
#include "solutions.h"
#include "input_output.h"

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

        int indicator_in = 0;
        int indicator_out = 0;
        int buf = 0;
        int bad_input = 0;

        while((buf = getchar()) != '\n')
            {
                if ((buf != '*') && (buf != '#') && !(isspace(buf)))
                    bad_input++;
                if( buf == '*')
                    indicator_out++;
                if( buf == '#')
                    indicator_in++;
            }

        if((bad_input != 0) or (indicator_in != 1 && indicator_out != 1))
        {
            printf("Команда не распознана. Введи один символ.\n");

            continue;
        }

        if(indicator_in == 1 && bad_input == 0 )
        {
            int rootnumb = ROOT_ERROR;

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
        else if (indicator_out == 1 && bad_input == 0)
            {
                return 0;
            }
    }

    return 0;
 }
