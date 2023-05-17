/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjean <vjean@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 08:47:20 by vjean             #+#    #+#             */
/*   Updated: 2023/05/16 13:11:29 by vjean            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/Cub3D.h"

//change no in the map to add textures. If hit 2 -> texture N; hit 3 -> texture S
//hit 4 -> texture E; hit 5 -> texture W... not sure if it will work
//maybe not necessary

void	path_to_xpm(t_parse *data)
{
	data->xpm = malloc(sizeof(t_xpm) * 4);
	data->xpm->EA = mlx_load_xpm42(data->EA);
	if (!data->xpm->EA)
		exit(1);//need to better deal error and free stuff
	data->xpm->WE = mlx_load_xpm42(data->WE);
	if (!data->xpm->WE)
		exit(1);//need to better deal error and free stuff
	data->xpm->NO = mlx_load_xpm42(data->NO);
	if (!data->xpm->NO)
		exit(1);//need to better deal error and free stuff
	data->xpm->SO = mlx_load_xpm42(data->SO);
	if (!data->xpm->SO)
		exit(1);//need to better deal error and free stuff
	//for
}


int	**create_array_pixels(t_parse *data)
{
	data->map->array_textures = malloc(sizeof(int));
}

void	add_texture(t_parse *data)
{
	path_to_xpm(data);
}