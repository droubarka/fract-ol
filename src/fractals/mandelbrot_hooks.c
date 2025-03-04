/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot_hooks.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-oub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 09:03:38 by mait-oub          #+#    #+#             */
/*   Updated: 2025/03/01 09:03:39 by mait-oub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mandelbrot.h"

static int	mandelbrot_move(int keysym, t_fractal *fractal)
{
	int	scale_px;

	scale_px = 20;
	if (keysym == XK_Left)
	{
		fractal_move(fractal, +scale_px, 0);
		mandelbrot_graph(fractal);
	}
	else if (keysym == XK_Right)
	{
		fractal_move(fractal, -scale_px, 0);
		mandelbrot_graph(fractal);
	}
	else if (keysym == XK_Up)
	{
		fractal_move(fractal, 0, +scale_px);
		mandelbrot_graph(fractal);
	}
	else if (keysym == XK_Down)
	{
		fractal_move(fractal, 0, -scale_px);
		mandelbrot_graph(fractal);
	}
	return (1);
}

static int	mandelbrot_iterations(int keysym, t_fractal *fractal)
{
	if (keysym == KEY_PLUS)
	{
		fractal->graph.iterations += 10;
	}
	else if (keysym == KEY_MINUS)
	{
		fractal->graph.iterations -= 10;
	}
	else
	{
		return (0);
	}
	if (fractal->graph.iterations <= 0)
	{
		fractal->graph.iterations = 10;
	}
	mandelbrot_graph(fractal);
	return (1);
}

static int	mandelbrot_reset(t_fractal *fractal)
{
	fractal->graph.real[0] = -2;
	fractal->graph.real[1] = +2;
	fractal->graph.imag[0] = -2;
	fractal->graph.imag[1] = +2;
	fractal->graph.iterations = 30;
	mandelbrot_graph(fractal);
	return (1);
}

int	mandelbrot_key(int keysym, t_fractal *fractal)
{
	if (keysym == XK_Escape)
	{
		fractal_xclose(fractal);
	}
	else if (keysym == XK_r)
	{
		mandelbrot_reset(fractal);
	}
	else if (keysym == XK_c)
	{
		fractal->graph.color += 1;
		mandelbrot_graph(fractal);
	}
	else if (keysym == XK_v)
	{
		fractal->graph.color -= 1;
		mandelbrot_graph(fractal);
	}
	else if (keysym == XK_x)
	{
		fractal->graph.color = 1;
		mandelbrot_graph(fractal);
	}
	mandelbrot_move(keysym, fractal);
	mandelbrot_iterations(keysym, fractal);
	return (1);
}

int	mandelbrot_mouse(int keysym, int x, int y, t_fractal *fractal)
{
	if (keysym == Button4)
	{
		fractal_zoom(fractal, x, y, 0.9);
		mandelbrot_graph(fractal);
	}
	else if (keysym == Button5)
	{
		fractal_zoom(fractal, x, y, 1.1);
		mandelbrot_graph(fractal);
	}
	return (1);
}
