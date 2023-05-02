#include "../MLX42/include/MLX42/MLX42.h"
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include "../inc/Cub3D.h"

int main(void)
{
	mlx_t				*mlx;
	static	mlx_image_t	*image;
	int					y;
	int					x;

	y = 0;
	x = 0;
	if (!(mlx = mlx_init(1920, 1080, "P'tit carré cheap", true)))
	{
		mlx_strerror(mlx_errno); //fonction a utiliser pour gerer les erreurs
		return(EXIT_FAILURE);
	}
	if(!(image = mlx_new_image(mlx, 100, 100)))
	{
		mlx_close_window(mlx);//ferme la fenetre
		return(EXIT_FAILURE);
	}
	while (y <= 99)
	{
		while (x <= 99)
		{
			if ((x % 2) == 0)
				mlx_put_pixel(image, x, y, 0xff0000ff);
			else if ((x % 2) == 1)
				mlx_put_pixel(image, x, y, 0x0000ffff);
			x++;
		}
		x = 0;
		y++;
	}
	if (mlx_image_to_window(mlx, image, 0, 0) == -1)
	{
		mlx_delete_image(mlx, image);
		mlx_close_window(mlx);
		return (EXIT_FAILURE);
	}
	mlx_loop(mlx);
	mlx_terminate(mlx);
}