/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-oub <mait-oub@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 08:12:03 by mait-oub          #+#    #+#             */
/*   Updated: 2025/02/26 08:12:04 by mait-oub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

static unsigned int	julia_get_iter(t_fractal *fractal)
{
	unsigned int	iterations;
	t_complex		zx;
	t_complex		*z0;
	t_complex		*c;

	z0 = &fractal->graph.z0;
	c = &fractal->graph.c;
	iterations = 0;
	while (iterations < fractal->graph.max_iterations)
	{
		zx.real = (z0->real * z0->real) - (z0->imag * z0->imag) + c->real;
		zx.imag = 2 * z0->real * z0->imag + c->imag;
		if (4.0 <= (zx.real * zx.real + zx.imag * zx.imag))
		{
			return (iterations + 1);
		}
		*z0 = zx;
		iterations++;
	}
	return (iterations);
}

int	julia_render(t_fractal *fractal)
{
	t_graph	*graph;
	int		x;
	int		y;

	graph = &fractal->graph;
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			graph->z0.real = map_value(x, WIDTH - 1, graph->real_range);
			graph->z0.imag = map_value(HEIGHT - 1 - y, HEIGHT - 1, graph->imag_range);
			fractal_draw(fractal, x, y, julia_get_iter);
			x++;
		}
		y++;
	}
	fractal_update(fractal);
	return (1);
}

int	julia(char *title, t_complex *c)
{
	t_fractal	*fractal;

	fractal = fractal_init(WIDTH, HEIGHT, title);
	if (fractal != NULL)
	{
		fractal->graph.render = julia_render;
		fractal->graph.real_range[0] = DEF_REAL_RANGE_MIN;
		fractal->graph.real_range[1] = DEF_REAL_RANGE_MAX;
		fractal->graph.imag_range[0] = DEF_IMAG_RANGE_MIN;
		fractal->graph.imag_range[1] = DEF_IMAG_RANGE_MAX;
		fractal->graph.max_iterations = 32;
		fractal->graph.color = 0;
		fractal->graph.c = *c;
		fractal->graph.render(fractal);
		fractal_hook(fractal, fractal_keyboard, fractal_mouse);
		fractal_loop(fractal, NULL);
	}
	return (EXIT_FAILURE);
}
