/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_zoom.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-oub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 08:12:03 by mait-oub          #+#    #+#             */
/*   Updated: 2025/03/01 09:10:38 by mait-oub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int	fractal_move(t_fractal *fractal, int x, int y)
{
	t_graph	*graph;
	t_ldouble	offset_x;
	t_ldouble	offset_y;

	graph = &fractal->graph;
	offset_x = remap2(WIDTH, graph->real, x) - graph->real[0];
	offset_y = remap2(HEIGHT, graph->imag, y) - graph->imag[0];
	graph->real[0] += offset_x;
	graph->real[1] += offset_x;
	graph->imag[0] += offset_y;
	graph->imag[1] += offset_y;
	return (1);
}

int	fractal_zoom(t_fractal *fractal, int x, int y, t_ldouble zoom)
{
	t_graph	*graph;
	t_ldouble	sx;
	t_ldouble	sy;

	graph = &fractal->graph;
	sx = remap2(WIDTH, graph->real, x);
	sy = remap2(HEIGHT, graph->imag, y);
	graph->real[0] = sx - (sx - graph->real[0]) * zoom;
	graph->real[1] = sx + (graph->real[1] - sx) * zoom;
	graph->imag[0] = sy - (sy - graph->imag[0]) * zoom;
	graph->imag[1] = sy + (graph->imag[1] - sy) * zoom;
	return (1);
}
