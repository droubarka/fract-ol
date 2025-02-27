/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-oub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 06:22:17 by mait-oub          #+#    #+#             */
/*   Updated: 2025/02/22 06:22:20 by mait-oub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int	usage(void)
{
	write(2, "which one?\n", 11); //?
	return (1);
}

int	main(int argc, char **argv)
{
	if (argc < 2)
	{
		usage();
		return (EXIT_FAILURE);
	}

	if (!ft_strncmp(argv[1], "mandelbrot", 11))
	{
		mandelbrot(argv[1]);
	}
	else if (!ft_strncmp(argv[1], "julia", 6))
	{
	}
	else if (!ft_strncmp(argv[1], "x", 6))
	{
	}

	return (EXIT_SUCCESS);
}
