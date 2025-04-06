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

#include "mandelbrot.h"

static int	mandelbrot_get_iterations(t_fractal *fractal, t_complex *c)
{
	int			iterations;
	t_graph		*graph;
	t_complex	z0;
	t_complex	zx;

	graph = &fractal->graph;
	z0.real = 0;
	z0.imag = 0;
	iterations = 0;
	while (iterations < graph->iterations)
	{
		zx.real = (z0.real * z0.real) - (z0.imag * z0.imag) + c->real;
		zx.imag = 2 * z0.real * z0.imag + c->imag;
		iterations++;
		if (4 <= (zx.real * zx.real + zx.imag * zx.imag))
		{
			return (iterations);
		}
		z0.real = zx.real;
		z0.imag = zx.imag;
	}
	return (iterations);
}

static int	mandelbrot_draw(t_fractal *fractal, t_complex *c, int x, int y)
{
	int		iterations;
	int		offset;
	t_data	*data;

	data = &fractal->graph.data;
	iterations = mandelbrot_get_iterations(fractal, c);
	offset = (y * data->size_line + x * (data->depth / 8)) / 4;
	data->ptr[offset] = get_color(fractal, iterations);
	return (1);
}

int	mandelbrot_graph(t_fractal *fractal)
{
	int			x;
	int			y;
	t_complex	c;

	y = 0;
    while (y < HEIGHT)
    {
		x = 0;
	    while (x < WIDTH)
        {
			c.real = remap2(WIDTH, fractal->graph.real, x);
			c.imag = remap2(HEIGHT, fractal->graph.imag, HEIGHT - y - 1);
			fractal->graph.position.real = c.real;
			fractal->graph.position.imag = c.imag;
			mandelbrot_draw(fractal, &c, x, y);
			x++;
        }
		y++;
    }
	fractal_update(fractal);
	return (1);
}

int	mandelbrot(char *title)
{
	t_fractal	*fractal;

	fractal = fractal_init(WIDTH, HEIGHT, title);
	if (fractal == NULL)
	{
		return (EXIT_FAILURE);
	}
	fractal->graph.real[0] = -2;
	fractal->graph.real[1] = +2;
	fractal->graph.imag[0] = -2;
	fractal->graph.imag[1] = +2;
	fractal->graph.iterations = 40; //? reset
	fractal->graph.color = 0; //? why?
	mandelbrot_graph(fractal);
	fractal_hook(fractal, mandelbrot_key, mandelbrot_mouse, fractal_xclose);
	fractal_loop(fractal);
	return (1);
}
