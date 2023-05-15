/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjean <vjean@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 13:15:04 by vjean             #+#    #+#             */
/*   Updated: 2023/05/15 15:12:17 by vjean            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/Cub3D.h"

void	init_player_pos(t_parse *data)
{
	if (data->map->player == 'N')
	{
		data->ray->dir_X = 0; //direction of the player on X
		data->ray->dir_Y = 1; //direction of the player on Y
	}
	else if (data->map->player == 'S')
	{
		data->ray->dir_X = 0;
		data->ray->dir_Y = -1;
	}
	else if (data->map->player == 'W')
	{
		data->ray->dir_X = -1;
		data->ray->dir_Y = 0;
	}
	else if (data->map->player == 'E')
	{
		data->ray->dir_X = 1;
		data->ray->dir_Y = 0;
	}
}

void	init_struct(t_parse *data)
{
	data->image = mlx_new_image(data->mlx, w, h);
	data->ray = malloc(sizeof(t_raycast));
	data->ray->pos_X = data->map->player_x; //start position of player on x
	data->ray->pos_Y = data->map->player_y; //start position of player on y
	//init_player_pos(data);
	data->ray->dir_X = -1; //devrait chercher si player est N, W, E or S. Voir init_player_pos (direction)
	data->ray->dir_Y = 0;
	data->ray->plane_X = 0;
	data->ray->plane_Y = 0.66;
	data->ray->hit = 0;
}

void	where_am_i(t_parse *data)
{
	data->ray->mapX = (int)data->ray->pos_X;
	data->ray->mapY = (int)data->ray->pos_Y;
}

void	mesure_ray(t_parse *data)
{
	if (data->ray->ray_dirX == 0)
		data->ray->deltaX_dist = 1e30;
	else
		data->ray->deltaX_dist = fabs(1 / data->ray->ray_dirX);
	if (data->ray->ray_dirY == 0)
		data->ray->deltaY_dist = 1e30;
	else
		data->ray->deltaY_dist = fabs(1 / data->ray->ray_dirY);
}

//before DDA, need to calculate sideX_dist and sideY_dist as well as indicate
//we step forward or backward on x axis and y axis
void	prep_dda(t_parse *data)
{
	if (data->ray->ray_dirX < 0) //vers la gauche??
	{
		data->ray->step_x = -1;
		data->ray->sideX_dist = (data->ray->pos_X - data->ray->mapX) * data->ray->deltaX_dist;
	}
	else
	{
		data->ray->step_x = 1; //vers la droite??
		data->ray->sideX_dist = (data->ray->mapX + 1.0 - data->ray->pos_X) * data->ray->deltaX_dist;
	}
	if (data->ray->ray_dirY < 0) //vers le bas?
	{
		data->ray->step_y = -1;
		data->ray->sideY_dist = (data->ray->pos_Y - data->ray->mapY) * data->ray->deltaY_dist;
	}
	else
	{
		data->ray->step_y = 1; //vers le haut??
		data->ray->sideY_dist = (data->ray->mapY + 1.0 - data->ray->pos_Y) * data->ray->deltaY_dist;
	}
}

void	dda_algo(t_parse *data)
{
	while (data->ray->hit == 0) //as long as we didn't hit a wall
	{
		//check for the next map square to jump; either x-dir or y-dir
		if (data->ray->sideX_dist < data->ray->sideY_dist)
		{
			data->ray->sideX_dist += data->ray->deltaX_dist;
			data->ray->mapX += data->ray->step_x;
			data->ray->side = 0;
		}
		else
		{
			data->ray->sideY_dist += data->ray->deltaY_dist;
			data->ray->mapY += data->ray->step_y;
			data->ray->side = 1;
		}
		//hit a wall or not??
		if (data->map->map[data->ray->mapX][data->ray->mapY] == '1') //maybe switch x and y
			data->ray->hit = 1;
	}
	data->ray->hit = 0;
}

void	get_perpendicular(t_parse *data)
{
	if (data->ray->side == 0)
		data->ray->perpendicular_wallDist = data->ray->sideX_dist - data->ray->deltaX_dist;
	else
		data->ray->perpendicular_wallDist = data->ray->sideY_dist - data->ray->deltaY_dist;
}

void	draw_line(t_parse *data)
{
	//to calculate height of line to draw on screen
	data->ray->line_height = (int)(h / data->ray->perpendicular_wallDist);

	//calculate lowest and highest pixel to fill in current "stripe"
	data->ray->draw_start_pt = -data->ray->line_height / 2 + h / 2;
	if (data->ray->draw_start_pt < 0)
		data->ray->draw_start_pt = 0;
	data->ray->draw_end_pt = data->ray->line_height / 2 + h / 2;
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
		//step 1: which orientation? N, S, E or W. look at my raycast. Which orientation in my grid
		//step 2: raycast where am I? left to right and up and down. print data->xpm->EA (for example)
//		if(side == 0 && rayDirX > 0) texX = texWidth - texX - 1;
//      if(side == 1 && rayDirY < 0) texX = texWidth - texX - 1;
		//need texture coordinates: texture_y and texture_x. Int or double? INT
		//need to add a check to see side N, S, E, W to send the correct texture. In an if condition to set the position
		//then, we will add the pixel of our textures
		if (data->ray->side == 1)
		{
			if (data->ray->ray_dirY < 0)
				mlx_put_pixel(data->image, index, i, 0xFF6F00FF); //orange
			else
				mlx_put_pixel(data->image, index, i, 0x870000FF); //red
		}
		else if (data->ray->side == 0)
		{
			if(data->ray->ray_dirX > 0)
				mlx_put_pixel(data->image, index, i, 0xFF00FFFF); //pink; last arg will be int **array
			else
				mlx_put_pixel(data->image, index, i, 0xF4D800FF); //yellow
		}
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
		data->ray->cameraX = (2 * index) / (double)w - 1; //x-coordinate in camera space //good
		data->ray->ray_dirX = data->ray->dir_X + data->ray->plane_X * data->ray->cameraX; //good
		data->ray->ray_dirY = data->ray->dir_Y + data->ray->plane_Y * data->ray->cameraX; //good
		where_am_i(data); //good
		mesure_ray(data); //reviewed
		prep_dda(data); //reviewed
		dda_algo(data); //reviewed
		get_perpendicular(data); //reviewed
		draw_line(data); //good
		add_some_colours(data, index); //good
		//add_texture(data); //add it here or not??
		index++;
	}
}

void	start_raycast(t_parse *data)
{
	if (!(data->mlx = mlx_init(w, h, "cub3d", true)))
	{
		mlx_strerror(mlx_errno); //fonction a utiliser pour gerer les erreurs
		exit(EXIT_FAILURE); //do we need to change the error message? to make sure stuff is free?
	}
	init_struct(data);
	go_raycast(data);
	mlx_key_hook(data->mlx, key_event, (void*)data);
	mlx_loop(data->mlx); //add keypress avant loop
	mlx_terminate(data->mlx);
}
