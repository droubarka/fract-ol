/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-oub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 08:10:45 by mait-oub          #+#    #+#             */
/*   Updated: 2025/02/26 08:10:52 by mait-oub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTAL_H
# define FRACTAL_H

# include "mlx.h"
# include "utils.h"

# include <stdlib.h>
# include <X11/keysym.h>
# include <unistd.h>

# include <stdio.h> //?

# define WIDTH  900
# define HEIGHT 900

typedef struct s_fractal	t_fractal;
typedef struct s_mlx		t_mlx;
typedef struct s_graph		t_graph;
typedef struct s_data		t_data;

struct s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
};

struct s_data
{
	char	*ptr;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
};

struct s_graph
{
	double	real[2];
	double	imag[2];
	t_data	data;
};

struct s_fractal
{
	t_mlx	*mlx;
	t_graph	graph;
};

/* fractal_init.c */
t_fractal	*fractal_init(int size_x, int size_y, char *title);
int			fractal_destroy(t_fractal *fractal);
int			xclose(t_fractal *fractal);

/* fractals */
int			mandelbrot(char *title);

#endif
