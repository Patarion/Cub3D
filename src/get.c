/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjean <vjean@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 14:29:56 by vjean             #+#    #+#             */
/*   Updated: 2023/05/04 14:30:00 by vjean            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Cub3D.h"

char	*GetPath(char *dir, char *line)
{
	char	*r_get;
	char	*path;
	int		i;

	r_get = NULL;
	path = NULL;
	i = 0;
	while (ft_isspace(line[i]) != 0 && line[i] != '\0')
		i++;
	path = ft_substr(line, 0, i);
	r_get = ft_strjoin(dir, path);
	path = xfree(path);
	return (r_get);
}

void	GetPlayerPoint(t_map *map_data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (map_data->map[y] != NULL)
	{
		while (map_data->map[y][x] != '\0')
		{
			if (ft_charsetcmp(map_data->map[y][x], "NSEW") == 0)
			{
				map_data->player_x = x;
				map_data->player_y = y;
				return ;
			}
			x++;
		}
		x = 0;
		y++;
	}
}


static void change_space(char *map)
{
	int	i;

	i = 0;
	while (map[i] != '\0')
	{
		if (map[i] == 32)
			map[i] = '1';
		i++;
	}
}

void	GetTmpMap(t_parse *data, int fd)
{
	char	*r_gnl;
	int		i;

	r_gnl = NULL;
	i = 0;
	if (!fd)
		return ;
	while (data->MapBeg > 1)
	{
		r_gnl = xfree(ez_gnl(fd));
		data->MapBeg--;
	}
	data->map->map = malloc(sizeof(char *) * (data->map->nb_lines + 1));
	while ((r_gnl = ez_gnl(fd)) != NULL)
	{
		data->map->map[i] = r_gnl;
		change_space(data->map->map[i]);
		i++;
	}
	data->map->map[i] = NULL;
	print_double_tab(data->map->map);
	GetPlayerPoint(data->map);
	printf("Le joueur est à la position Y : %d et X : %d\n", data->map->player_y, data->map->player_x);
}