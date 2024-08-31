#include "fractol.h"

int	check_complex(const char *str)
{
	int	flag;
	int	i;

	i = 0;
	flag = 1;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] != '\0')
	{
		if (str[i] == '.')
			i++;
		if ((str[i] < '0' || str[i] > '9'))
			flag = 0;
		i++;
	}
	return (flag);
}
/*
-menu-
For Mandelbrot set, type :
"mandelbrot"
For Julia set, type :
"julia", "x" "y" OR "julia" "x"
For Burning Ship, type :
"burning_ship"
*/
int fractal_menu()
{   
    int fd;

    fd = 1;
    ft_putstr_fd("For Mandelbrot set, type :\n", fd);
    ft_putstr_fd("\"mandelbrot\"\n", fd);
    ft_putstr_fd("For Julia set, type :\n", fd);
    ft_putstr_fd("\"julia\" AND [\"x\" \"y\" OR \"x\"]\n", fd);
    ft_putstr_fd("For Burning Ship, type :\n", fd);
    ft_putstr_fd("\"burning_ship\"\n", fd);
    return (0);
}

int check_args(int ac, char **av, t_fractal *fractal)
{
    if (ac == 2)
    {
        if (!ft_strncmp(av[1], "mandelbrot", 11))
        {
            printf("run...\n");
            return (mandelbrot(fractal));
        }
        else if (!ft_strncmp(av[1], "burning_ship", 13))
            return (burning_ship(fractal));
    }
    else if (ac == 3)
    {
        if (!ft_strncmp(av[1], "julia", 6))
            return (julia(av[2], "0", fractal));
    }
    else if (ac == 4)
        if (!ft_strncmp(av[1], "julia", 6))
            return (julia(av[2], av[3], fractal));
    return (0);
}
