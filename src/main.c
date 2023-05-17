/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjean <vjean@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 11:37:06 by vjean             #+#    #+#             */
/*   Updated: 2023/05/17 15:23:44 by vjean            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Cub3D.h"

int main(int argc, char **argv) {
	
	t_parse	*data;
	
	if (argc != 2)
	{
		printf("Veuillez fournir un fichier au format .cub");
		return (-1);
	}
	if ((data = ParseInfo(argv[1])) == NULL)
	{
		printf("La map n'est pas valide ou n'a pas toutes les bonnes info");
		return (-1);
	}
	add_texture(data);
  	if (data->error == GOOD)
		start_raycast(data); //start the "game"; open winden and have the map
	return 0;
}
