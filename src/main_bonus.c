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
	"   Or: ./fractol julia <real> <imag>\n";
	"   Or: ./fractol x\n";
	write(2, usage_msg, ft_strlen(usage_msg));
	return (1);
}

int	main(int argc, char **argv)
{
	t_complex	julia_params;

	if (argc == 2 && !ft_strncmp(argv[1], "mandelbrot", 11))
	{
		mandelbrot(argv[1]);
	}
	else if (argc == 4 && !ft_strncmp(argv[1], "julia", 6))
	{
//		julia_params.real = ft_atof(argv[2]);
//		julia_params.imag = ft_atof(argv[3]);

		julia(argv[1], &julia_params);
	}
	else
	{
		usage();
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
