/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjean <vjean@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 14:26:19 by vjean             #+#    #+#             */
/*   Updated: 2023/05/04 14:26:22 by vjean            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Cub3D.h"

t_parse *InitCheck()
{
    t_parse *data;

    data = malloc(sizeof(t_parse));
    data->NO = NULL;
    data->SO = NULL;
    data->EA = NULL;
    data->WE = NULL;
    data->FloorColor = 0;
    data->CeilingColor = 0;
	data->treat_Floor = false;
	data->treat_Ceiling = false;
	data->error = GOOD;
	data->MapBeg = 0;
    data->map = malloc(sizeof(t_map));
    data->map->player = 0;
    data->map->first_line = false;
    data->map->last_line = false;
    data->map->map_layout = NULL;
    data->map->player_x = 0;
    data->map->player_y = 0;
    data->map->direction = 0;
	data->map->nb_lines = 0;
    return (data);
}
