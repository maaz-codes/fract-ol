#include <stdio.h>

typedef struct s_complex
{
    double real;
    double i;
}              t_complex;

int main(void)
{
    t_complex z;
    t_complex c;
    double temp;

    // f(c) Z = Z^2 + C;

    int i = 1;

    c.real = 0;
    c.i = 1;
    z.real = 0;
    z.i = 0;

    while (i <= 42)
    {
        temp = (z.real * z.real) - (z.i * z.i);
        z.i = 2 * (z.real * z.i);
        z.real = temp;

        z.real += c.real;
        z.i += c.i;

        printf("Point = %d | Number => %f  %fi\n", i, z.real, z.i);
        i++;
    }
}