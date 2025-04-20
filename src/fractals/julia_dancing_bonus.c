/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia_dancing_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-oub <mait-oub@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 08:12:03 by mait-oub          #+#    #+#             */
/*   Updated: 2025/04/09 20:42:51 by mait-oub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

static int	julia_dancing_loop(t_fractal *fractal)
{
	static long double	a;

	fractal->graph.c.real = .7885 * cosl(a);
	fractal->graph.c.imag = .7885 * sinl(a);
	if (2 * M_PI <= -a)
	{
		fractal->graph.color += 1;
		fractal->graph.color %= 2;
		a = 0;
	}
	fractal->graph.render(fractal);
//	usleep(100);
	a -= .10;
	return (1);
}

int	julia_dancing(char *title)
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
		fractal->graph.c = (t_complex){0, 0};
		fractal_hook(fractal, fractal_keyboard, fractal_mouse);
		fractal_loop(fractal, &julia_dancing_loop);
	}
	return (EXIT_FAILURE);
}
