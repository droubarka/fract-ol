/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_destroy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-oub <mait-oub@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 07:58:43 by mait-oub          #+#    #+#             */
/*   Updated: 2025/04/08 07:58:45 by mait-oub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int	fractal_destroy(t_fractal *fractal)
{
	t_mlx	*mlx;

	mlx = &fractal->mlx;
	if (mlx->img_ptr != NULL)
	{
		mlx_destroy_image(mlx->mlx_ptr, mlx->img_ptr);
	}
	if (mlx->win_ptr != NULL)
	{
		mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
	}
	if (mlx->mlx_ptr != NULL)
	{
		mlx_destroy_display(mlx->mlx_ptr);
		free(mlx->mlx_ptr);
	}
	free(fractal);
	return (1);
}
