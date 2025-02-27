/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-oub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 08:12:03 by mait-oub          #+#    #+#             */
/*   Updated: 2025/02/26 08:12:04 by mait-oub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int	mandelbrot_keyboard()
{
}

int	mandelbrot_mouse()
{
}

int	mandelbrot_graph(t_fractal *fractal, int size_x, int size_y)
{
	int		row;
	int		col;
	t_mlx	*mlx;
	t_graph	*graph;

	mlx = fractal->mlx;
	graph = &fractal->graph;
	row = 0;
	col = 0;
	while (row < size_y)
	{
		while (col < size_x)
		{
			
			col++;
		}
		row++;
	}
	return (1);
}

int	mandelbrot(int size_x, int size_y, char *title)
{
	t_fractal	*fractal;
	t_graph		*graph;

	fractal = fractal_init(size_x, size_y, title);
	if (fractal == NULL)
	{
		return (0);
	}

	graph = &fractal->graph;

	graph->real[0] = -2;
	graph->real[1] = +2;
	graph->imag[0] = -2;
	graph->imag[1] = +2;

	mandelbrot_graph(fractal, size_x, size_y);

	fractal_hook(mandelbrot_keyboard, mandelbrot_mouse, fractal_xclose);
//	fractal_loop(fractal);

	fractal_destroy(fractal);
	return (1);
}
