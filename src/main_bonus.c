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
	"Usage: ./fractol mandelbrot\n" \
	"   Or: ./fractol julia <real> <imag>\n" \
	"   Or: ./fractol tricorn\n";
	write(2, usage_msg, ft_strlen(usage_msg));
	return (1);
}

int	main(int argc, char **argv)
{
	t_complex	julia_params;

	if (argc == 2)
	{
		if (!ft_strncmp(argv[1], "-m", 3)
			|| !ft_strncmp(argv[1], "mandelbrot", 11))
		{
			return (mandelbrot("Fractal: Mandelbrot"));
		}
		if (!ft_strncmp(argv[1], "-t", 3)
			|| !ft_strncmp(argv[1], "tricorn", 8))
		{
			return (tricorn("Fractal: Tricorn"));
		}
		if (!ft_strncmp(argv[1], "--help", 7))
		{
			usage();
			return (EXIT_SUCCESS);
		}
	}
	else if (argc == 4)
	{
		if (!ft_strncmp(argv[1], "-j", 3)
			|| !ft_strncmp(argv[1], "julia", 6))
		{
			init_julia_params(&julia_params, argv + 2);
			return (julia("Fractal: Julia", &julia_params));
		}
	}
	usage_error(argc);
}
