
#include "utils.h"

int	init_julia_params(t_complex *julia_params, char **av)
{
	char	*endptr;

	julia_params->real = ft_strtold(av[0], &endptr);
	if (*av[0] == '\0' || *endptr != '\0')
	{
		error("./fractol: invalid <read> value\n");
	}
	julia_params->imag = ft_strtold(av[1], &endptr);
	if (*av[1] == '\0' || *endptr != '\0')
	{
		error("./fractol: invalid <imag> value\n");
	}
	return (1);
}
