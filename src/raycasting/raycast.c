/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjean <vjean@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 13:15:04 by vjean             #+#    #+#             */
/*   Updated: 2023/05/12 10:43:10 by vjean            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/Cub3D.h"

void	init_struct(t_parse *data)
{
	data->image = mlx_new_image(data->mlx, w, h);
	data->ray = malloc(sizeof(t_raycast));
	data->ray->pos_playerX = data->map->player_x; //devrait peut-être aller chercher la position où est N dans la map
	data->ray->pos_playerY = data->map->player_y;
	data->ray->dir_playerX = -1; //devrait chercher si player est N, W, E or S
	data->ray->dir_playerY = 0;
	data->ray->plane_playX = 0;
	data->ray->plane_playY = 0.66;
	data->ray->hit = 0;
}

void	where_am_i(t_parse *data)
{
	data->map->player_x = (int)data->ray->pos_playerX;
	data->map->player_y = (int)data->ray->pos_playerY;
}

void	mesure_ray(t_parse *data)
{
	data->ray->furtherX_dist = fabs(1 / data->ray->ray_dirX);
	data->ray->furtherY_dist = fabs(1 / data->ray->ray_dirY);
}

//before DDA, need to calculate sideX_dist and sideY_dist as well as indicate
//we step forward or backward on x axis and y axis
void	prep_dda(t_parse *data)
{
	if (data->ray->ray_dirX < 0) //direction derrière??
	{
		data->ray->step_x = -1;
		data->ray->sideX_dist = (data->ray->pos_playerX - data->map->player_x) * data->ray->furtherX_dist;
	}
	else
	{
		data->ray->step_x = 1; //direction vers l'avant?
		data->ray->sideX_dist = (data->map->player_x + 1.0 - data->ray->pos_playerX) * data->ray->furtherX_dist;
	}
	if (data->ray->ray_dirY < 0) //direction derrière??
	{
		data->ray->step_y = -1;
		data->ray->sideY_dist = (data->ray->pos_playerY - data->map->player_y) * data->ray->furtherY_dist;
	}
	else
	{
		data->ray->step_y = 1;
		data->ray->sideY_dist = (data->map->player_y + 1.0 - data->ray->pos_playerY) * data->ray->furtherY_dist;
	}
}

void	dda_algo(t_parse *data)
{
	while (data->ray->hit == 0) //as long as we didn't hit a wall
	{
		//check for the next map square to jump; either x-dir or y-dir
		if (data->ray->sideX_dist < data->ray->sideY_dist)
		{
			data->ray->sideX_dist += data->ray->furtherX_dist;
			data->map->player_x += data->ray->step_x;
			data->ray->side = 0;
		}
		else
		{
			data->ray->sideY_dist += data->ray->furtherY_dist;
			data->map->player_y += data->ray->step_y;
			data->ray->side = 1;
		}
		//hit a wall or not??
		if (data->map->map[data->map->player_y][data->map->player_x] == '1')//or should I put > 0?? We know the wall is 1
			data->ray->hit = 1;
	}
	data->ray->hit = 0;
}

void	get_perpendicular(t_parse *data)
{
	if (data->ray->side == 0)
		data->ray->perpendicular_wallDist = data->ray->sideX_dist - data->ray->furtherX_dist;
	else
		data->ray->perpendicular_wallDist = data->ray->sideY_dist - data->ray->furtherY_dist;
}

void	draw_line(t_parse *data)
{
	//to calculate height of line to draw on screen
	data->ray->line_height = (int)(h / data->ray->perpendicular_wallDist);

	//calculate lowest and highest pixel to fill in current "stripe"
	data->ray->draw_start_pt = -data->ray->line_height / 2 + h / 2; //BEDMAS
	if (data->ray->draw_start_pt < 0)
		data->ray->draw_start_pt = 0;
	data->ray->draw_end_pt = data->ray->line_height / 2 + h / 2; //BEDMAS
	if (data->ray->draw_end_pt >= h)
		data->ray->draw_end_pt = h - 1;
}

void	add_some_colours(t_parse *data, int index)
{
	//mlx_put_pixel to draw the line or not??? and add colours?? Just need a uint32_t colours
	//while loop tant que start est plus petit ou egal a end. A voir si besoin du egal ou non
	int	i;

	i = 0;
	while (i < data->ray->draw_start_pt) //plafond
	{
		mlx_put_pixel(data->image, index, i, data->CeilingColor);
		i++;
	}
	while (i < data->ray->draw_end_pt) //add texture here for walls
	{
		//need texture coordinates: texture_y and texture_x. Int or double? INT
		//need to add a check to see side N, S, E, W to send the correct texture. In an if condition to set the position
		//then, we will add the pixel of our textures
		mlx_put_pixel(data->image, index, i, 0xFF00FFFF); //last arg will be int **array
		i++;
	}
	while (i < h - 1) //plancher
	{
		mlx_put_pixel(data->image, index, i, data->FloorColor);
		i++;
	}
}

void	go_raycast(t_parse *data)
{
	int	index;

	index = 0;
	mlx_image_to_window(data->mlx, data->image, 0, 0); //protect
	while (index < w)
	{
		//calculate ray position and direction
		data->ray->cameraX = (2 * index) / (double)w - 1; //x-coordinate in camera space
		data->ray->ray_dirX = data->ray->dir_playerX + (data->ray->plane_playX * data->ray->cameraX);
		data->ray->ray_dirY = data->ray->dir_playerY + (data->ray->plane_playY * data->ray->cameraX);
		where_am_i(data);
		mesure_ray(data);
		prep_dda(data);
		dda_algo(data);
		get_perpendicular(data);
		draw_line(data);
		add_some_colours(data, index);
		add_texture(data); //add it here or not??
		index++;
	}
}

void	start_raycast(t_parse *data)
{
	if (!(data->mlx = mlx_init(w, h, "cub3d", true)))
	{
		mlx_strerror(mlx_errno); //fonction a utiliser pour gerer les erreurs
		exit(EXIT_FAILURE);
	}
	init_struct(data);
	go_raycast(data);
	mlx_key_hook(data->mlx, key_event, (void*)data);
	mlx_loop(data->mlx); //add keypress avant loop
	mlx_terminate(data->mlx);
}
