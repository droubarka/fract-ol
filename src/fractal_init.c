/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-oub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 06:22:17 by mait-oub          #+#    #+#             */
/*   Updated: 2025/02/27 15:22:47 by mait-oub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

static t_fractal	*fractal_new(void)
{
	t_fractal	*fractal;
	t_mlx		*mlx;

	fractal = malloc(sizeof(t_fractal));
	if (fractal == NULL)
	{
		return (NULL);
	}
	mlx = malloc(sizeof(t_mlx));
	if (mlx == NULL)
	{
		free(fractal);
		return (NULL);
	}
	mlx->mlx_ptr = mlx_init();
	mlx->win_ptr = NULL;
	mlx->img_ptr = NULL;
	if (mlx->mlx_ptr == NULL)
	{
		free(mlx);
		free(fractal);
		return (NULL);
	}
	fractal->mlx = mlx;
	return (fractal);
}

t_fractal	*fractal_init(int size_x, int size_y, char *title)
{
	t_fractal	*fractal;
	t_mlx		*mlx;
	t_data		*data;

	fractal = fractal_new();
	if (fractal != NULL)
	{
		mlx = fractal->mlx;
		mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, size_x, size_y, title);
		if (mlx->win_ptr != NULL)
		{
			mlx->img_ptr = mlx_new_image(mlx->mlx_ptr, size_x, size_y);
		}
		if (mlx->win_ptr == NULL || mlx->img_ptr == NULL)
		{
			fractal_destroy(fractal);
			return (NULL);
		}
		data = &fractal->graph.data;
		data->ptr = mlx_get_data_addr(mlx->img_ptr,
				&data->depth, &data->size_line, &data->endian);
	}
	return (fractal);
}

int	fractal_destroy(t_fractal *fractal)
{
	t_mlx	*mlx;

	mlx = fractal->mlx;
	if (mlx->img_ptr)
	{
		mlx_destroy_image(mlx->mlx_ptr, mlx->img_ptr);
	}
	if (mlx->win_ptr)
	{
		mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
	}
	if (mlx->mlx_ptr)
	{
		mlx_destroy_display(mlx->mlx_ptr);
		free(mlx->mlx_ptr);
	}
	free(mlx);
	free(fractal);
	return (1);
}

int	fractal_update(t_fractal *fractal)
{
	t_mlx	*mlx;

	mlx = fractal->mlx;
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img_ptr, 0, 0);
}
