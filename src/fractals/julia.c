/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-oub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 08:12:03 by mait-oub          #+#    #+#             */
/*   Updated: 2025/03/03 12:11:44 by mait-oub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "julia.h"

static int	julia_get_iterations(t_fractal *fractal, t_complex *z0)
{
	int			iterations;
	t_graph		*graph;
	t_complex	zx;

	graph = &fractal->graph;
	iterations = 0;
	while (iterations < graph->iterations)
	{
		zx.real = (z0->real * z0->real) - (z0->imag * z0->imag) + graph->c->real;
		zx.imag = 2 * z0->real * z0->imag + graph->c->imag;
		iterations++;
		if (4 <= (zx.real * zx.real + zx.imag * zx.imag))
		{
			return (iterations);
		}
		z0->real = zx.real;
		z0->imag = zx.imag;
	}
	return (iterations);
}

static int	julia_color(t_fractal *fractal, int iterations)
{
	t_graph	*graph;

	graph = &fractal->graph;
	if (iterations == graph->iterations)
	{
		return (0);
	}
	return (get_color(fractal, iterations));
}

static int	julia_draw(t_fractal *fractal, t_complex *z0, int x, int y)
{
	int		iterations;
	int		offset;
	t_data	*data;

	data = &fractal->graph.data;
	iterations = julia_get_iterations(fractal, z0);
	offset = (y * data->size_line + x * (data->depth / 8)) / 4;
	data->ptr[offset] = julia_color(fractal, iterations);
	return (1);
}

int	julia_graph(t_fractal *fractal)
{
	int			x;
	int			y;
	t_complex	z0;

	y = 0;
    while (y < HEIGHT)
    {
		x = 0;
	    while (x < WIDTH)
        {
			z0.real = remap2(WIDTH, fractal->graph.real, x);
			z0.imag = remap2(HEIGHT, fractal->graph.imag, HEIGHT - y - 1);
			julia_draw(fractal, &z0, x, y);
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
	if (fractal == NULL)
	{
		return (0);
	}
	fractal->graph.real[0] = -2;
	fractal->graph.real[1] = +2;
	fractal->graph.imag[0] = -2;
	fractal->graph.imag[1] = +2;
	fractal->graph.iterations = 30;
	fractal->graph.color = 0;
	fractal->graph.c = c;
	julia_graph(fractal);
	fractal_hook(fractal, julia_keyboard, julia_mouse);
	fractal_loop(fractal);
	return (1);
}

