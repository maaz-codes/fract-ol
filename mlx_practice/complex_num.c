#include <stdio.h>

typedef struct  s_complex
{
    double real;
    double i;
}               t_complex;

t_complex ft_sq_complex(t_complex num)
{
    t_complex result;

    result.real = (num.real * num.real) - (num.i * num.i);
    result.i = 2 * (num.real * num.i);
    return (result);
}

int main(void)
{
    t_complex num;

    num.real = 1;
    num.i = 2;
    // num = 3 + 4i ;

    t_complex sq_num = ft_sq_complex(num);
    printf("result = %f + %fi\n", sq_num.real, sq_num.i);
}