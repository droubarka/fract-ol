/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-oub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 10:39:07 by mait-oub          #+#    #+#             */
/*   Updated: 2025/03/01 10:39:09 by mait-oub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MANDELBROT_H
# define MANDELBROT_H

# include "fractal.h"

/* mandelbrot: mandelbrot.c */

int	mandelbrot(char *title);
int	mandelbrot_graph(t_fractal *fractal);

/* mandelbrot hooks: mandelbrot_hooks.c */

int	mandelbrot_key(int keysym, t_fractal *fractal);
int	mandelbrot_mouse(int keysym, int x, int y, t_fractal *fractal);

/* mandelbrot hooks: mandelbrot_hooks.c */

//int	get_color(t_fractal *fractal, int iterations);

#endif
