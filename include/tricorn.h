/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tricorn.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-oub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 10:39:07 by mait-oub          #+#    #+#             */
/*   Updated: 2025/03/04 07:11:05 by mait-oub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRICORN_H
# define TRICORN_H

# include "fractal.h"

/* mandelbrot: mandelbrot.c */

int	tricorn(char *title, t_complex *c);
int	tricorn_graph(t_fractal *fractal);

/* mandelbrot hooks: mandelbrot_hooks.c */

int	tricorn_key(int keysym, t_fractal *fractal);
int	tricorn_mouse(int keysym, int x, int y, t_fractal *fractal);

/* mandelbrot hooks: mandelbrot_hooks.c */

//int	get_color(t_fractal *fractal, int iterations);

#endif
