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

typedef long double t_ldouble;

# define WIDTH  650
# define HEIGHT 650
# define MOVE_PX 32

# define MOUSE_UP   4
# define MOUSE_DOWN 5
#define KEY_PLUS  65451
#define KEY_MINUS 65453

typedef struct s_fractal	t_fractal;
typedef struct s_mlx		t_mlx;
typedef struct s_graph		t_graph;
typedef struct s_data		t_data;

struct s_data					// done
{
	int	*ptr;					// done
	int	bpp;					// done
	int	size_line;				// done
	int	endian;					// done
};

struct s_graph
{
	t_data		data;			// done
	t_ldouble	real[2];		// done
	t_ldouble	imag[2];		// done
	int			iterations;		// done

	int			color_theme;

	int			(*render)(t_fractal *);			// done

	t_complex	position;
	t_complex	*c;
};

struct s_mlx					// done
{
	void	*mlx_ptr;			// done
	void	*win_ptr;			// done
	void	*img_ptr;			// done
};

struct s_fractal				// done
{
	t_mlx	mlx;				// done
	t_graph	graph;				// done
};

////////////////////////////////////////////////////////////////

/* /src/fractal_init.c */
t_fractal	*fractal_init(int size_x, int size_y, char *title);

/* /src/fractal_destroy.c */
int	fractal_destroy(t_fractal *fractal);

/* /src/fractal_transform.c */
int	fractal_move(t_fractal *fractal, int x, int y);
int	fractal_zoom(t_fractal *fractal, int x, int y, t_ldouble zoom);

/* /src/fractal_runtime.c */
int	fractal_hook(t_fractal *fractal, int (*keyboard)(), int (*mouse)());
int fractal_update(t_fractal *fractal);
int	fractal_loop(t_fractal *fractal);
int	fractal_close(t_fractal *fractal);

/* /src/fractal_colors.c */

/* /src/fractal_hooks.c */

int	fractal_mouse(int keysym, int x, int y, t_fractal *fractal);

/* /src/fractals/mandelbrot.c */
/* /src/fractals/julia.c */
int	julia(char *title, t_complex *c);

/* /src/fractals/x.c */

#endif
