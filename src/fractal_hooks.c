/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_hooks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-oub <mait-oub@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 09:03:38 by mait-oub          #+#    #+#             */
/*   Updated: 2025/03/01 09:03:39 by mait-oub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

static int	adjust_iterations(int keysym, t_fractal *fractal)
{
	t_graph			*graph;
	unsigned int	iteration_step;

	graph = &fractal->graph;
	iteration_step = ITERATION_STEP;
	if (keysym == KEY_PLUS)
	{
		if (graph->max_iterations <= UINT_MAX - iteration_step)
		{
			graph->max_iterations += iteration_step;
			return (1);
		}
	}
	else if (keysym == KEY_MINUS)
	{
		if ((iteration_step <= graph->max_iterations)
			&& (ITERATION_MIN <= graph->max_iterations - iteration_step))
		{
			graph->max_iterations -= iteration_step;
			return (1);
		}
	}
	return (0);
}

static int	reset_params(t_fractal *fractal)
{
	fractal->graph.real_range[0] = DEF_REAL_RANGE_MIN;
	fractal->graph.real_range[1] = DEF_REAL_RANGE_MAX;
	fractal->graph.imag_range[0] = DEF_IMAG_RANGE_MIN;
	fractal->graph.imag_range[1] = DEF_IMAG_RANGE_MAX;
	fractal->graph.max_iterations = DEF_MAX_ITERATIONS;
	return (1);
}

int	fractal_keyboard(int keysym, t_fractal *fractal)
{
	if (!adjust_iterations(keysym, fractal))
	{
		if (keysym == XK_Escape)
		{
			fractal_close(fractal);
		}
		if (keysym != XK_r && keysym != XK_c)
		{
			return (0);
		}
		if (keysym == XK_c)
			fractal->graph.color += 1;
		else
			reset_params(fractal);
	}
	fractal->graph.render(fractal);
	return (1);
}

int	fractal_mouse(int keysym, int x, int y, t_fractal *fractal)
{
	(void) x;
	(void) y;
	if (keysym == Button4)
	{
		fractal_zoom(fractal, WIDTH / 2, HEIGHT / 2, 0.9);
		fractal->graph.render(fractal);
	}
	else if (keysym == Button5)
	{
		fractal_zoom(fractal, WIDTH / 2, HEIGHT / 2, 1.1);
		fractal->graph.render(fractal);
	}
	return (1);
}
