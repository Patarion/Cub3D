/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjean <vjean@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 13:15:04 by vjean             #+#    #+#             */
/*   Updated: 2023/05/08 09:28:42 by vjean            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/Cub3D.h"

void	init_struct(t_parse *data)
{
	data->ray->pos_playerX = 22; //devrait peut-être aller chercher la position où est N dans la map
	data->ray->pos_playerY = 12;
	data->ray->dir_playerX = -1; //devrait chercher si player est N, W, E or S
	data->ray->dir_playerY = 0;
	data->ray->plane_playX = 0;
	data->ray->plane_playY = 0.66;
}

void	go_raycast(t_parse *data)
{
	int	index;

	index = 0;
	while (index < w)
	{
		//calculate ray position and direction
		data->ray->cameraX = (2 * index) / (double)w - 1; //x-coordinate in camera space
		data->ray->ray_dirX = (data->ray->dir_playerX + data->ray->plane_playX) * data->ray->cameraX; //COMMENT might need to delete or change brackets... **to change priority of operation. below too
		data->ray->ray_dirY = (data->ray->dir_playerY + data->ray->plane_playY) * data->ray->cameraX;
		where_am_i(data, index);


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
	mlx_loop(data->mlx);
	mlx_terminate(data->mlx);
}