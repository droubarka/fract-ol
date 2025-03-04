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

#include "julia.h"

static int	julia_move(int keysym, t_fractal *fractal)
{
	int	scale_px;

	scale_px = 20;
	if (keysym == XK_Left)
	{
		fractal_move(fractal, +scale_px, 0);
		julia_graph(fractal);
	}
	else if (keysym == XK_Right)
	{
		fractal_move(fractal, -scale_px, 0);
		julia_graph(fractal);
	}
	else if (keysym == XK_Up)
	{
		fractal_move(fractal, 0, -scale_px);
		julia_graph(fractal);
	}
	else if (keysym == XK_Down)
	{
		fractal_move(fractal, 0, +scale_px);
		julia_graph(fractal);
	}
	return (1);
}

static int	julia_iterations(int keysym, t_fractal *fractal)
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
	julia_graph(fractal);
	return (1);
}

static int	julia_reset(t_fractal *fractal)
{
	fractal->graph.real[0] = -2;
	fractal->graph.real[1] = +2;
	fractal->graph.imag[0] = -2;
	fractal->graph.imag[1] = +2;
	fractal->graph.iterations = 30;
	julia_graph(fractal);
	return (1);
}

int	julia_key(int keysym, t_fractal *fractal)
{
	if (keysym == XK_Escape)
	{
		fractal_xclose(fractal);
	}
	else if (keysym == XK_r)
	{
		julia_reset(fractal);
	}
	else if (keysym == XK_c)
	{
		fractal->graph.color += 1;
		julia_graph(fractal);
	}
	else if (keysym == XK_v)
	{
		fractal->graph.color -= 1;
		julia_graph(fractal);
	}
	else if (keysym == XK_x)
	{
		fractal->graph.color = 1;
		julia_graph(fractal);
	}
	julia_move(keysym, fractal);
	julia_iterations(keysym, fractal);
	return (1);
}

int	julia_mouse(int keysym, int x, int y, t_fractal *fractal)
{
	if (keysym == Button4)
	{
		fractal_zoom(fractal, x, HEIGHT - y - 1, 0.9);
		julia_graph(fractal);
	}
	else if (keysym == Button5)
	{
		fractal_zoom(fractal, x, HEIGHT - y - 1, 1.1);
		julia_graph(fractal);
	}
	return (1);
}
