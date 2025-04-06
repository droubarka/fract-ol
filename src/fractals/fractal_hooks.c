/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_hooks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-oub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 09:03:38 by mait-oub          #+#    #+#             */
/*   Updated: 2025/03/01 09:03:39 by mait-oub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "julia.h"

static int	fractal_shift_view(int keysym, t_fractal *fractal)
{
	int	scale_px;

	scale_px = 20; //?
	if (keysym == XK_Left)
		fractal_move(fractal, +scale_px, 0);
	else if (keysym == XK_Right)
		fractal_move(fractal, -scale_px, 0);
	else if (keysym == XK_Up)
		fractal_move(fractal, 0, -scale_px);
	else if (keysym == XK_Down)
		fractal_move(fractal, 0, +scale_px);
	else
		return (0);
	return (1);
}

static int	fractal_modify_iterations(int keysym, t_fractal *fractal)
{
	int	new_iterations;

	if (keysym == KEY_PLUS)
		new_iterations = fractal->graph.iterations + 10; //?
	else if (keysym == KEY_MINUS)
		new_iterations = fractal->graph.iterations - 10; //?
	else
		return (0);
	if (new_iterations <= 0)
		return (0);
	fractal->graph.iterations = new_iterations;
	return (1);
}

static int	fractal_reset_view(t_fractal *fractal)
{
	fractal->graph.real[0] = -2;
	fractal->graph.real[1] = +2;
	fractal->graph.imag[0] = -2;
	fractal->graph.imag[1] = +2;
	fractal->graph.iterations = 30; //?
	return (1);
}

int	fractal_keyboard(int keysym, t_fractal *fractal)
{
	if (keysym == XK_Escape)
		fractal_close(fractal);
	if (keysym == XK_r)
		fractal_reset_view(fractal);
	else if (keysym == XK_c)
		fractal->graph.color += 1;
	else if (keysym == XK_v)
		fractal->graph.color -= 1;
	else if (keysym == XK_x)
		fractal->graph.color = +0;
	else if (fractal_shift_view(keysym, fractal))
		;
	else if (fractal_modify_iterations(keysym, fractal))
		;
	else
		return (0);
	fractal->render(fractal);
	return (1);
}

int	fractal_mouse(int keysym, int x, int y, t_fractal *fractal)
{
	if (keysym == Button4)
	{
		fractal_zoom(fractal, x, HEIGHT - y - 1, 0.9);
		fractal->render(fractal);
	}
	else if (keysym == Button5)
	{
		fractal_zoom(fractal, x, HEIGHT - y - 1, 1.1);
		fractal->render(fractal);
	}
	return (1);
}
