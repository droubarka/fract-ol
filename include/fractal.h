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

# include <math.h>
# include <stdlib.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include <unistd.h>

# include <stdio.h> //?

# define WIDTH  650
# define HEIGHT 650

# define MOUSE_UP   4
# define MOUSE_DOWN 5
#define KEY_PLUS  65451
#define KEY_MINUS 65453

typedef struct s_complex	t_complex;

struct s_complex
{
	long double real;
	long double imag;
};

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
	int	*ptr;
	int	depth;
	int	size_line;
	int	endian;
};

struct s_graph
{
	long double	real[2];
	long double	imag[2];
	int			iterations;
	int			color;
	t_complex	position;
	t_complex	*c;
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
int			fractal_xclose(t_fractal *fractal);
int fractal_update(t_fractal *fractal);

/* fractal_zoom.c */
int	fractal_move(t_fractal *fractal, int x, int y);
int	fractal_zoom(t_fractal *fractal, int x, int y, double zoom);

/* fractal_loop.c */
int	fractal_hook(t_fractal *fractal, int (*key)(), int (*mouse)(), int (*xclose)());
int	fractal_loop(t_fractal *fractal);

/* fractals */
int			mandelbrot(char *title);
int			julia(char *title, t_complex *c);
int			tricorn(char *title, t_complex *c);

/* others */
int	get_color(t_fractal *fractal, int iter);

#endif
