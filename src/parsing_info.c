/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjean <vjean@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 14:25:05 by vjean             #+#    #+#             */
/*   Updated: 2023/05/10 08:09:48 by vjean            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "../inc/Cub3D.h"

void ParseLine(char *line, t_parse* MapCheck)
{
    int				i;
    int				j;
    static  bool		treat_map;
    int				r_cmp;

    i = -1;
    j = 0;
    r_cmp = -1;
    while (ft_isspace(line[++i]) == 0)
        ;
    if (treat_map == false && ft_isdigit(line[i]))
        treat_map = true;
    if (treat_map == true)
    {
        ParseMap(line, MapCheck);
        return ;
    }
    while ((r_cmp = (ft_strncmp(&line[i], g_side_tab[j], 3))) != 0 && j < 4)
        j++;
    if (j < 4 && r_cmp == 0)
        ParsePath(MapCheck, &line[i], j);
    while (j < 6 && (r_cmp = ft_strncmp(&line[i], g_side_tab[j], 2)) != 0)
        j++;
	if (j < 6 && j >= 4 && r_cmp == 0)
		ParseColor(MapCheck, &line[i], j);
}

void	ParseColor(t_parse *data, char *line, int j)
{
	int				i;
	int				k;
	unsigned int	id_color;
    int             nb_bits;
	char			*hex;

	i = 1;
	id_color = 0;
	hex = NULL;
    nb_bits = 24;
	while (line[i] != '\0' && nb_bits > 0)
	{
		k = 0;
		while (line[i] != '\0' && (ft_isspace(line[i]) == 0 || line[i] == ','))
            i++;
		while (line[i + k] != '\0' && ft_isdigit(line[i + k]) == 1)
			k++;
		if (ft_isalpha(line[i + k]) == 1)
			data->error = COLOR;
        hex = ft_substr(&line[i], 0, k);
        id_color = (ft_Uatoi(hex, data)) << nb_bits;
        if (data->error == GOOD && j == 4)
            data->FloorColor |= id_color;
        else if (data->error == GOOD && j == 5)
            data->CeilingColor |= id_color;
        nb_bits -= 8;
		i += k;
		hex = xfree(hex);
	}
	if (j == 4)
		data->treat_Floor = true;
	else if (j == 5)
		data->treat_Ceiling = true;
}

int ParseName(char *map)
{
    int i;

    i = 0;
    while (map[i] != '\0' && map[i] != '.')
        i++;
    if (map[i] == '.')
    {
       if (ft_strncmp(&map[i], ".cub", 5) == 0)
           return (0);
       return (-1);
    }
    return (-1);
}

t_parse *ParseInfo(char *map)
{
    t_parse *MapCheck;
    int     fd;

    fd = 0;
    if (ParseName(map)  != 0)
        return (NULL);
    MapCheck = InitCheck();
    fd = open(map, O_RDONLY);
    if (fd < 0)
        return (NULL);
    while ((first_parse(fd, MapCheck)) > 0 && MapCheck->error == GOOD)
		;
    close(fd);
	check_ParseInfo(MapCheck);
	if (MapCheck->error == GOOD)
		fd = open(map, O_RDONLY);
	GetTmpMap(MapCheck, fd);
	flood_fill(MapCheck, MapCheck->map->player_y, MapCheck->map->player_x);
	if (MapCheck->error != GOOD)
		error_handler(MapCheck);
	print_info(MapCheck);
    return (MapCheck);
}

void ParsePath(t_parse* MapCheck, char *line, int j)
{
    int     i;
    char    *dir;

    i = 0;
	dir = NULL;
    while (ft_isspace(line[i]) == 0)
        i++;
//    dir = ft_calloc(3, sizeof(char));
//    ft_strlcpy(dir, &line[i], 3);
//    dir = ft_charjoinfree(dir, ' ');
    i += 2;
    while (ft_isspace(line[++i]) == 0)
        ;
    if (j == 0 && MapCheck->NO == NULL)
		MapCheck->NO = GetPath(&line[i]);
    else if (j == 1 && MapCheck->SO == NULL)
        MapCheck->SO = GetPath(&line[i]);
    else if (j == 2 && MapCheck->WE == NULL)
        MapCheck->WE = GetPath(&line[i]);
    else if (j == 3 && MapCheck->EA == NULL)
        MapCheck->EA = GetPath(&line[i]);
//    dir = xfree(dir);
//    dir = NULL;
}
