/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjean <vjean@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 11:37:06 by vjean             #+#    #+#             */
/*   Updated: 2023/05/04 14:02:42 by vjean            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Cub3D.h"

int main(int argc, char **argv) {
	
//	t_parse	data;
	
	if (argc != 2)
	{
		printf("Veuillez fournir un fichier au format .cub");
		return (-1);
	}
	if (ParseInfo(argv[1]) != 0)
		printf("La map n'est pas valide ou n'a pas toutes les bonnes info");
//	else
//		start_mlx(&data); //start the "game"; open winden and have the map
	return 0;
}
