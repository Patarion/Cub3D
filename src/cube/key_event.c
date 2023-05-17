#include "../../inc/Cub3D.h"

void	rotate_cam(struct mlx_key_data key, t_raycast *ray)
{
	double	oldDirX;
	double	oldPlaneX;
	double	speed;

	oldDirX = ray->dir_playerX;
	oldPlaneX = ray->plane_X;
	speed = 0.06;
	if (key.key == 263)
	{
		//printf("ON TOURNE À GAUCH'!\n");
		ray->dir_playerX = ray->dir_playerX * cos(-speed) - ray->dir_playerY * sin(-speed);
		ray->dir_playerY = oldDirX * sin(-speed) + ray->dir_playerY * cos(-speed);
		ray->plane_X = ray->plane_X * cos(-speed) - ray->plane_Y * sin(-speed);
		ray->plane_Y = oldPlaneX * sin(-speed) + ray->plane_Y * cos(-speed);
	}
	else if (key.key == 262)
	{
		//printf("ON TOURNE À DROUAITE!\n");
		ray->dir_playerX = ray->dir_playerX * cos(speed) - ray->dir_playerY * sin(speed);
		ray->dir_playerY = oldDirX * sin(speed) + ray->dir_playerY * cos(speed);
		ray->plane_X = ray->plane_X * cos(speed) - ray->plane_Y * sin(speed);
		ray->plane_Y = oldPlaneX * sin(speed) + ray->plane_Y * cos(speed);
	}
}

void key_event(struct mlx_key_data key, void *data)
{
	t_parse *tmp;

	tmp = data;
	//printf("Key pressed : %d\n", key.key);
	if (key.key == 263 || key.key == 262)
		rotate_cam(key, tmp->ray);
//	tmp->image->pixels = ft_memset((void*)tmp->image->pixels, 0, ((h * w) * sizeof(int)));
	go_raycast(tmp);
}