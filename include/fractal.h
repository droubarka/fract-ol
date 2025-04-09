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

# include <limits.h>
# include <stdlib.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include <unistd.h>

# define WIDTH  650
# define HEIGHT 650

# define KEY_PLUS  65451
# define KEY_MINUS 65453

# define DEF_REAL_RANGE_MIN -2.0
# define DEF_REAL_RANGE_MAX +2.0
# define DEF_IMAG_RANGE_MIN -2.0
# define DEF_IMAG_RANGE_MAX +2.0
# define DEF_MAX_ITERATIONS +32U

# define ITERATION_STEP 10U
# define ITERATION_MIN  10U

# define VIEW_SHIFT_PX 20

typedef long double			t_ldouble;

typedef struct s_fractal	t_fractal;
typedef struct s_mlx		t_mlx;
typedef struct s_graph		t_graph;
typedef struct s_data		t_data;

struct s_data
{
	char	*ptr;
	int		bpp;
	int		size_line;
	int		endian;
};

struct s_graph
{
	int				(*render)(t_fractal *);
	t_data			data;
	t_ldouble		real_range[2];
	t_ldouble		imag_range[2];
	unsigned int	max_iterations;
	unsigned int	color;
	t_complex		z0;
	t_complex		c;
};

struct s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
};

struct s_fractal
{
	t_mlx	mlx;
	t_graph	graph;
};

/* /src/fractal_init.c */
t_fractal		*fractal_init(int size_x, int size_y, char *title);

/* /src/fractal_destroy.c */
int				fractal_destroy(t_fractal *fractal);

/* /src/fractal_transform.c */
int				fractal_move(t_fractal *fractal, int offset_x, int offset_y);
int				fractal_zoom(t_fractal *fractal, int x, int y, t_ldouble zoom);

/* /src/fractal_runtime.c */
int				fractal_draw(t_fractal *fractal, \
	int x, int y, unsigned int (*get_iter)());
int				fractal_hook(t_fractal *fractal, \
	int (*keyboard)(), int (*mouse)());
int				fractal_update(t_fractal *fractal);
int				fractal_loop(t_fractal *fractal);
int				fractal_close(t_fractal *fractal);

/* /src/fractal_colors.c */
unsigned int	fractal_color(t_fractal *fractal, unsigned int iterations);

/* /src/fractal_hooks.c */
int				fractal_keyboard(int keysym, t_fractal *fractal);
int				fractal_mouse(int keysym, int x, int y, t_fractal *fractal);

/* /src/fractals/mandelbrot.c */
int				mandelbrot(char *title);
int				mandelbrot_render(t_fractal *fractal);

/* /src/fractals/julia.c */
int				julia(char *title, t_complex *c);
int				julia_render(t_fractal *fractal);

/* /src/fractals/tricorn.c */
int				tricorn(char *title);
int				tricorn_render(t_fractal *fractal);

/**/

#endif
