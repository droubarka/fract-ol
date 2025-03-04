/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-oub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 10:39:07 by mait-oub          #+#    #+#             */
/*   Updated: 2025/03/03 12:21:42 by mait-oub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef JULIA_H
# define JULIA_H

# include "fractal.h"

/* mandelbrot: mandelbrot.c */

int	julia(char *title, t_complex *c);
int	julia_graph(t_fractal *fractal);

/* mandelbrot hooks: mandelbrot_hooks.c */

int	julia_key(int keysym, t_fractal *fractal);
int	julia_mouse(int keysym, int x, int y, t_fractal *fractal);

/* mandelbrot hooks: mandelbrot_hooks.c */

//int	get_color(t_fractal *fractal, int iterations);

#endif
