/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_transform.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-oub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 08:12:03 by mait-oub          #+#    #+#             */
/*   Updated: 2025/03/01 09:10:38 by mait-oub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int	fractal_move(t_fractal *fractal, int offset_x, int offset_y)
{
	t_graph		*graph;
	t_ldouble	real_span;
	t_ldouble	imag_span;
	t_ldouble	offset_cx;
	t_ldouble	offset_cy;

	graph = &fractal->graph;
	real_span = graph->real_range[1] - graph->real_range[0];
	imag_span = graph->imag_range[1] - graph->imag_range[0];
	offset_cx = offset_x * real_span / (WIDTH - 1);
	offset_cy = offset_y * imag_span / (HEIGHT - 1);
	graph->real_range[0] += offset_cx;
	graph->real_range[1] += offset_cx;
	graph->imag_range[0] += offset_cy;
	graph->imag_range[1] += offset_cy;
	return (1);
}

int	fractal_zoom(t_fractal *fractal, int x, int y, t_ldouble zoom)
{
	t_graph		*graph;
	t_ldouble	cx;
	t_ldouble	cy;

	graph = &fractal->graph;
	cx = map_value(x, WIDTH - 1, graph->real_range);
	cy = map_value(y, HEIGHT - 1, graph->imag_range);
	graph->real_range[0] = cx + (graph->real_range[0] - cx) * zoom;
	graph->real_range[1] = cx + (graph->real_range[1] - cx) * zoom;
	graph->imag_range[0] = cy + (graph->imag_range[0] - cy) * zoom;
	graph->imag_range[1] = cy + (graph->imag_range[1] - cy) * zoom;
	return (1);
}
