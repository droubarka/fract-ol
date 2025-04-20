/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_colors.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-oub <mait-oub@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 10:29:49 by mait-oub          #+#    #+#             */
/*   Updated: 2025/03/04 05:57:01 by mait-oub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

static unsigned int	scheme_0(t_fractal *fractal, unsigned int iters)
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
	t_ldouble		t;

	t = ((t_ldouble) iters) / fractal->graph.max_iterations;
	r = (unsigned char)(9 * (1 - t) * t * t * t * 255);
	g = (unsigned char)(15 * (1 - t) * (1 - t) * t * t * 255);
	b = (unsigned char)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
	return (r << 16 | g << 8 | b);
}

static unsigned int	scheme_1(t_fractal *fractal, unsigned int iters)
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
	t_ldouble		t;

	t = ((t_ldouble) iters) / fractal->graph.max_iterations;
	r = (unsigned char)(15 * (1 - t) * (1 - t) * t * t * 255);
	g = (unsigned char)(9 * (1 - t) * t * t * t * 255);
	b = (unsigned char)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
	return (r << 16 | g << 8 | b);
}

static unsigned int	scheme_2(t_fractal *fractal, unsigned int iters)
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
	t_ldouble		t;

	t = ((double) iters) / fractal->graph.max_iterations;
	r = (unsigned char)(255 * (1.0 - t) * t * t * t + 255 * t);
	g = (unsigned char)(150 * (1 - t) * (1 - t) * t * t);
	b = (unsigned char)(40 * (1 - t) * (1 - t) * t);
	return (r << 16 | g << 8 | b);
}

unsigned int	fractal_color(t_fractal *fractal, unsigned int iterations)
{
	unsigned int	color;

	if (iterations == fractal->graph.max_iterations)
	{
		return (0x0);
	}
	fractal->graph.color %= 3;
	if (fractal->graph.color == 0)
	{
		color = scheme_0(fractal, iterations);
	}
	else if (fractal->graph.color == 1)
	{
		color = scheme_1(fractal, iterations);
	}
	else
	{
		color = scheme_2(fractal, iterations);
	}
	return (color);
}
