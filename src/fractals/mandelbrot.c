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

int	mandelbrot_key(int keysym, t_fractal *fractal)
{
	if (keysym == XK_Escape)
	{
		fractal_xclose(fractal);
	}
	return (1);
}

int	zoom(t_fractal *fractal, int x, int y, int xzoom)
{
	t_graph		*graph;
	long double	sx;
	long double	sy;

	graph = &fractal->graph;

	sx = remap(graph->size_x, graph->real, x);
	sy = remap(graph->size_y, graph->imag, y);

	graph->real[0] = sx - (sx - graph->real[0]) * (long double) xzoom;
	graph->real[1] = sx + (graph->real[1] - sx) * (long double) xzoom;
	graph->imag[0] = sy - (sy - graph->imag[0]) * (long double) xzoom;
	graph->imag[1] = sy + (graph->imag[1] - sy) * (long double) xzoom;

	dprintf(2, "done: %Lf: %Lf\n", graph->real[0]);
	return (1);
}

int	mandelbrot_mouse(int keysym, int x, int y, t_fractal *fractal)
{
	if (keysym == MOUSE_UP)
	{
		zoom(fractal, x, y, 1.1);
		mandelbrot_graph(fractal);
	}
	else if (keysym == MOUSE_DOWN)
	{
		zoom(fractal, x, y, 0.9);
		mandelbrot_graph(fractal);
	}
	return (1);
}

#define MAX_ITERATION 1000

int	mandelbrot_iteration(t_complex *z, t_complex *c) //? shared
{
	int			iteration;
	t_complex	z0;
	t_complex	zx;

	z0.real = z->real;
	z0.imag = z->imag;
	iteration = 0;
	while (iteration < MAX_ITERATION)
	{
		zx.real = (z0.real * z0.real) - (z0.imag * z0.imag);
		zx.imag = 2 * z0.real * z0.imag;
		zx.real += c->real;
		zx.imag += c->imag;
		if (4 <= (zx.real * zx.real + zx.imag * zx.imag))
		{
			return (iteration);
		}
		iteration++;
		z0.real = zx.real;
		z0.imag = zx.imag;
	}
	return (0);
}

int	mandelbrot_color(int iteration)
{
	return (remap((long double [2]){0, MAX_ITERATION}, (long double [2]){0, 0xffffff}, iteration));
}

int	mandelbrot_draw(t_data *data, t_complex *c, int x, int y)
{
	int	iteration;
	int	color;
	int	offset;

	iteration = mandelbrot_iteration(&((t_complex) {0, 0}), c);
	color = mandelbrot_color(iteration);
	offset = (y * data->size_line + x * (data->depth / 8));
	*((int *)(data->ptr + offset)) = color;
}

int	mandelbrot_graph(t_fractal *fractal)
{
	int			x;
	int			y;
	t_graph		*graph;
	t_complex	c;

    graph = &fractal->graph;
	y = 0;
    while (y < graph->size_y[1])
    {
		x = 0;
	    while (x < graph->size_x[1])
        {
			c.real = remap(graph->size_x, graph->real, x);
			c.imag = remap(graph->size_y, graph->imag, y);
			mandelbrot_draw(&graph->data, &c, x, y);
			x++;
        }
		y++;
    }
	fractal_update(fractal);
}

int	mandelbrot(int size_x, int size_y, char *title)
{
	t_fractal	*fractal;

	fractal = fractal_init(size_x, size_y, title);
	if (fractal == NULL)
	{
		return (0);
	}
	fractal->graph.real[0] = -2;
	fractal->graph.real[1] = +2;
	fractal->graph.imag[0] = -2;
	fractal->graph.imag[1] = +2;

	fractal->graph.size_x[0] = 0;
	fractal->graph.size_x[1] = size_x;

	fractal->graph.size_y[0] = 0;
	fractal->graph.size_y[1] = size_y;

	mandelbrot_graph(fractal);

	fractal_hook(fractal, mandelbrot_key, mandelbrot_mouse, fractal_xclose);
	fractal_loop(fractal);
	return (1);
}
