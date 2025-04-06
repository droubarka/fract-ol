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

int	fractal_move(t_fractal *fractal, int x, int y)
{
	t_graph		*graph;
	t_ldouble	offset_x;
	t_ldouble	offset_y;

	graph = &fractal->graph;
	offset_x = map_value(x, WIDTH, graph->real) - graph->real[0];
	offset_y = map_value(y, HEIGHT, graph->imag) - graph->imag[0];
	graph->real[0] += offset_x;
	graph->real[1] += offset_x;
	graph->imag[0] += offset_y;
	graph->imag[1] += offset_y;
	return (1);
}

int	fractal_zoom(t_fractal *fractal, int x, int y, t_ldouble zoom)
{
	t_graph	*graph;
	t_ldouble	cx;
	t_ldouble	cy;

	graph = &fractal->graph;
	cx = map_value(x, WIDTH, graph->real);
	cy = map_value(y, HEIGHT, graph->imag);
	graph->real[0] = cx - (cx - graph->real[0]) * zoom;
	graph->real[1] = cx + (graph->real[1] - cx) * zoom;
	graph->imag[0] = cy - (cy - graph->imag[0]) * zoom;
	graph->imag[1] = cy + (graph->imag[1] - cy) * zoom;
	return (1);
}
