/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjean <vjean@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 14:29:42 by vjean             #+#    #+#             */
/*   Updated: 2023/05/04 14:29:46 by vjean            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Cub3D.h"

void error_handler(t_parse *data)
{
	printf("Error\n");
    if (data->error == PATH)
        printf("L'un des chemin des textures est invalide\n");
    else if (data->error == COLOR)
        printf("L'une des couleur fournise a une erreur ou est manquante\n");
    else if (data->error == MAP)
        printf("La carte fournise a une erreur de format\n");
	else if (data->error == CUB_FILE)
		printf("Le fichier a une erreur de format ou de code 18\n");
	else if (data->error == PLAYER)
		printf("La position du joueur est soit manquante ou multiple\n");
    clear_data(data);
    data = xfree(data);
    exit(0);
}


void	check_ParseInfo(t_parse *data)
{
	if (data->error != GOOD)
		;
	else if (data->NO == NULL || data->SO == NULL || data->WE == NULL\
		|| data->EA == NULL)
		data->error = PATH;
	else if (data->map->first_line == false || data->map->last_line == false)
		data->error = MAP;
	else if (data->treat_Ceiling == false || data->treat_Floor == false)
		data->error = COLOR;
	else if (data->map->player == 0 || data->map->player == 'Z')
		data->error = PLAYER;
	if (data->error != GOOD)
		error_handler(data);
}

void	print_info(t_parse *data)
{
	printf("%s\n%s\n%s\n%s\n%u\n%u\n%c\n%d\n", data->NO, data->SO, data->WE,\
    data->EA, data->FloorColor, data->CeilingColor, data->map->player,\
	data->MapBeg);
	print_double_tab(data->map->map);
}
