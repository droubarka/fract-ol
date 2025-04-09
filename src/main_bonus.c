/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-oub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 06:22:17 by mait-oub          #+#    #+#             */
/*   Updated: 2025/02/22 06:22:20 by mait-oub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

static int	usage(void)
{
	const char	*usage_msg;

	usage_msg = \
	"Usage: ./fractol -m | mandelbrot\n" \
	"   Or: ./fractol -j | julia <real> <imag>\n" \
	"   Or: ./fractol -d | julia-d\n" \
	"   Or: ./fractol -t | tricorn\n";
	write(2, usage_msg, ft_strlen(usage_msg));
	return (1);
}

int	main(int ac, char *av[])
{
	t_complex	julia_params;

	if (ac == 2)
	{
		if (!ft_strncmp(av[1], "-m", 3)
			|| !ft_strncmp(av[1], "mandelbrot", 11))
			return (mandelbrot("Fractal: Mandelbrot Set"));
		if (!ft_strncmp(av[1], "-t", 3) || !ft_strncmp(av[1], "tricorn", 8))
			return (tricorn("Fractal: Tricorn"));
		if (!ft_strncmp(av[1], "-d", 3) || !ft_strncmp(av[1], "julia-d", 8))
			return (julia_dancing("Fractal: Dancing Julia"));
		if (!ft_strncmp(av[1], "--help", 7))
			return (usage(), EXIT_SUCCESS);
	}
	else if (ac == 4)
	{
		if (!ft_strncmp(av[1], "-j", 3) || !ft_strncmp(av[1], "julia", 6))
		{
			init_julia_params(&julia_params, av + 2);
			return (julia("Fractal: Julia Set", &julia_params));
		}
	}
	usage_error(ac);
}
