/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_loop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-oub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 17:13:42 by mait-oub          #+#    #+#             */
/*   Updated: 2025/02/28 02:56:12 by mait-oub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int	fractal_hook(t_fractal *fractal, int (*key)(), int (*mouse)(), int (*xc)())
{
	t_mlx	*mlx;

	mlx = fractal->mlx;
	mlx_hook(mlx->win_ptr, 2, 1, key, fractal);
	mlx_mouse_hook(mlx->win_ptr, mouse, fractal);
	mlx_hook(mlx->win_ptr, 17, 0, xc, fractal);
	return (1);
}

int	fractal_loop(t_fractal *fractal)
{
	mlx_loop(fractal->mlx->mlx_ptr);
	return (1);
}

int	fractal_xclose(t_fractal *fractal)
{
	fractal_destroy(fractal);
	exit(EXIT_SUCCESS);
	return (1);
}
