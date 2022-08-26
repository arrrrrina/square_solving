#include "header.h"

int solve_eq(const double a, const double b, const double c, double* x1, double* x2)
{
    assert(std::isfinite(a));
    assert(std::isfinite(b));
    assert(std::isfinite(c));

    double diskr = NAN;
    bool right_digits = (std::isfinite(a) && std::isfinite(b) && std::isfinite(c) && (x2!=x1));

    if(right_digits == 0)
    {
        return ROOT_ERROR;
    }

    if (are_equal(a,0))
    {
        if (!are_equal(b,0))
        {
            *x1 = -c / b;
            return ROOT_ONE;
        }
        else if(are_equal(b,0) && are_equal(c,0))
        {
            return ROOT_INF;
        }
        else return ROOT_ZERO;
    }
    else
    {
        diskr = b*b - 4*a*c;

        if(are_equal(diskr,0))
        {
            *x1 = -b/(2*a);
            return ROOT_ONE;
        }

        if(diskr > 0)
        {
            *x1 = (-b + sqrt(diskr))/(2*a);
            *x2 = (-b - sqrt(diskr))/(2*a);
            assert(std::isfinite(*x1));
            assert(std::isfinite(*x2));
            return ROOT_TWO;
        }
        if(diskr < 0)
        {
            return ROOT_ZERO;
        }

        assert(x1!=x2);
        assert(x1!=0 and x2!=0);
        assert(x1!=0 and x2!=0);

        return ROOT_ERROR;
    }
}

bool are_equal(const double a,const double b)
{
    assert(std::isfinite(a));
    assert(std::isfinite(b));

    if (fabs(a - b) <= SMALL_DIGIT)
    {
        return 1;
    }
    return 0;
}


