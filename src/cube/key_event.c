#include "../../inc/Cub3D.h"

void	rotate_cam(struct mlx_key_data key, t_raycast *ray)
{
	double	oldDirx;
	double	oldPlaneX;
	double	speed;

	oldDirx = ray->dir_playerX;
	oldPlaneX = ray->plane_playX;
	speed = 0.06;
	if (key.key == 262)
	{
		printf("JE TOURNE À DROUAITE!\n");
		ray->dir_playerX = ray->dir_playerX * cos(-speed) - ray->dir_playerY * sin(-speed);
		ray->dir_playerY = oldDirx * sin(-speed) + ray->dir_playerY * cos(-speed);
		ray->plane_playX = ray->plane_playX * cos(-speed) - ray->plane_playY * sin(-speed);
		ray->plane_playY = oldPlaneX * sin(-speed) + ray->plane_playY * cos(-speed);
	}
	else if (key.key == 263)
	{
		printf("JE TOURNE À GAUCHE!\n");
		ray->dir_playerX = ray->dir_playerX * cos(speed) - ray->dir_playerY * sin(speed);
		ray->dir_playerY = oldDirx * sin(speed) + ray->dir_playerY * cos(speed);
		ray->plane_playX = ray->plane_playX * cos(speed) - ray->plane_playY * sin(speed);
		ray->plane_playY = oldPlaneX * sin(speed) + ray->plane_playY * cos(speed);
	}
}

void	move_event(struct mlx_key_data key, t_parse *data)
{
	
}

void key_event(struct mlx_key_data key, void *data)
{
	t_parse *tmp;

	tmp = data;
	if (key.key == 263 || key.key == 262)
		rotate_cam(key, tmp->ray);
	if (key.key == 87 || key.key == 65 || key.key == 68 || key.key == 83)
		move_event(key, tmp);
	printf("La touche appuyée est %d\n", key.key);
	go_raycast(tmp);
}

// 87 == w | 65 == a | 68 == d | 83 == s