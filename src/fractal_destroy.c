
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
