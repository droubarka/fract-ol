/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-oub <mait-oub@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 06:22:17 by mait-oub          #+#    #+#             */
/*   Updated: 2025/02/27 15:22:47 by mait-oub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

t_fractal	*fractal_init(int size_x, int size_y, char *title)
{
	t_fractal	*fractal;
	t_mlx		*mlx;
	t_data		*data;

	fractal = malloc(sizeof(t_fractal));
	if (fractal == NULL)
		return (NULL);
	mlx = &fractal->mlx;
	mlx->mlx_ptr = mlx_init();
	if (mlx->mlx_ptr == NULL)
	{
		free(fractal);
		return (NULL);
	}
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, size_x, size_y, title);
	mlx->img_ptr = mlx_new_image(mlx->mlx_ptr, size_x, size_y);
	if (mlx->win_ptr == NULL || mlx->img_ptr == NULL)
	{
		fractal_destroy(fractal);
		return (NULL);
	}
	data = &fractal->graph.data;
	data->ptr = mlx_get_data_addr(mlx->img_ptr,
			&data->bpp, &data->size_line, &data->endian);
	return (fractal);
}
