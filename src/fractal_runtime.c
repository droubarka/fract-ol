/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_runtime.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-oub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 17:13:42 by mait-oub          #+#    #+#             */
/*   Updated: 2025/02/28 02:56:12 by mait-oub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int	fractal_draw(t_fractal *fractal, int x, int y, unsigned int (*get_iter)())
{
	t_data			*data;
	unsigned int	color;
	unsigned int	iterations;
	size_t			offset;

	iterations = get_iter(fractal);
	color = fractal_color(fractal, iterations);
	data = &fractal->graph.data;
	offset = (y * data->size_line + x * (data->bpp / 8));
	*((unsigned int *) (data->ptr + offset)) = color;
	return (1);
}

int	fractal_hook(t_fractal *fractal, int (*keyboard)(), int (*mouse)())
{
	t_mlx	*mlx;

	mlx = &fractal->mlx;
	mlx_mouse_hook(mlx->win_ptr, mouse, fractal);
	mlx_hook(mlx->win_ptr, 2, 1, keyboard, fractal);
	mlx_hook(mlx->win_ptr, 17, 0, fractal_close, fractal);
	return (1);
}

int	fractal_update(t_fractal *fractal)
{
	t_mlx	*mlx;

	mlx = &fractal->mlx;
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img_ptr, 0, 0);
	return (1);
}

int	fractal_loop(t_fractal *fractal)
{
	mlx_loop(fractal->mlx.mlx_ptr);
	return (1);
}

int	fractal_close(t_fractal *fractal)
{
	fractal_destroy(fractal);
	exit(EXIT_SUCCESS);
	return (0);
}
