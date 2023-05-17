#include "../MLX42/include/MLX42/MLX42.h"
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include "../inc/Cub3D.h"

int create_color(int red, int green, int blue, int trans)
{
	return (red << 24 | green << 16 | blue << 8 | trans);
}

int main(void)
{
	mlx_t				*mlx;
	static	mlx_image_t	*image;
	xpm_t				*wall;
	int					**tab;
	uint32_t			y;
	uint32_t			x;
	int					count;

	y = 0;
	x = 0;
	count = 0;
	if (!(mlx = mlx_init(1920, 1080, "P'tit carré cheap", true)))
	{
		mlx_strerror(mlx_errno); //fonction a utiliser pour gerer les erreurs
		return(EXIT_FAILURE);
	}
	if(!(image = mlx_new_image(mlx, 800, 800)))
	{
		mlx_close_window(mlx);//ferme la fenetre
		return(EXIT_FAILURE);
	}
	wall = malloc(sizeof(xpm_t));
	tab = malloc(sizeof(int) * (wall->texture.height + 1));
	wall = mlx_load_xpm42("/Users/vjean/Desktop/Cub3D/textures/Stardew-Brick-Wall-Multi-Colored.xpm42");
	while (y < wall->texture.height)
	{
		tab[y] = malloc(sizeof(int) * (wall->texture.width + 1));
		while (x < wall->texture.width)
		{
			tab[y][x] = create_color(wall->texture.pixels[count + 0], \
			wall->texture.pixels[count + 1], wall->texture.pixels[count + 2],\
			wall->texture.pixels[count + 3]);
			x++;
			count += 4;
		}
		tab[y][x] = '\0';
		x = 0;
		y++;
	}
	tab[y] = NULL;
	x = 0;
	y = 0;
	while (y < wall->texture.height)
	{
		while (x < wall->texture.width)
		{
			mlx_put_pixel(image, x, y, tab[y][x]);
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

if (data->ray->ray_dirY < 0)
{
	put_pixel(data->, index, i, image[i % tex->height][index % tex->width]);
}