/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjean <vjean@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 14:53:34 by vjean             #+#    #+#             */
/*   Updated: 2023/05/04 14:53:37 by vjean            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Cub3D.h"

int     len_till_wall(char *line, t_parse *parse)
{
    int     i;
    int     j;

    i = -1;
    j = 0;
    while (ft_isspace(line[++i]) == 0)
        ;
    if (line[i] == '1')
    {
        j++;
        while (ft_isspace(line[i]) == 0)
            i++;
        while (line[++i] != '\0' && (line[i] == '0' || ft_charsetcmp(line[i], "NESW") == 0))
        {
            if (ft_charsetcmp(line[i], "NESW") == 0 && parse->map->player == false)
                parse->map->player = true;
            if (parse->map->player == true && ft_charsetcmp(line[i], "NESW") == 0)
                return (-1);
            j++;
        }
        if (line[i] == '1')
            return (j + 1);
        else if (line[i] != '1')
            return (-1);
    }
    return (j);
}

int    First_Last_Line(char *line, t_parse *parse)
{
    int     i;

    i = -1;
	while (line[++i] == 32)
		;
    if (line[i] == '1' || line[i] == '0')
    {
        while (line[++i] == '1' || ft_isspace(line[i]) == 0)
            ;
        if ((line[i] == '0' && line[i + 1] == '\0') || line[i] == '\0')
        {
            if (parse->map->first_line == false)
                parse->map->first_line = true;
            else if (parse->map->last_line == false)
                parse->map->last_line = true;
            return (0);
        }
    }
    return (1);
}

void    Middle_Line(char *line, t_parse *parse)
{
    int i;

    i = -1;
    while (line[++i] == '1' || line[i] == 32)
        ;
    while (line[i] != '\0')
    {
        if (ft_charsetcmp(line[i], "NESW") == 0 && parse->map->player == 0)
            parse->map->player = line[i];
        else if (ft_charsetcmp(line[i], "NESW") == 0 && parse->map->player != 0)
        {
            parse->error = MAP;
            return ;
        }
		map_space_handler(line, &i, parse);
    }
}

void ParseMap(char *line, t_parse *parse)
{
    static int  nb_line;

    if ((parse->map->first_line == false || parse->map->last_line == false)
           && parse->error == GOOD)
    {
        if (First_Last_Line(line, parse) == 1)
            Middle_Line(line, parse);
        nb_line ++;
    }
	if (parse->map->last_line == true)
		parse->map->nb_lines = nb_line;
	printf("\n%d\n", nb_line);
}

void	map_space_handler(char *line, int *i, t_parse *parse)
{
	int	k;

	k = *i;
	if (line[k] == '1' && ft_isspace(line[k + 1]) == 0)
	{
			while (ft_isspace(line[++k]) == 0)
				;
			if (line[k] == '1' || line[k] == '\0')
				*i = k;
	}
	else if (line[k] == '0' && ft_isspace(line[k + 1]) == 0)
	{
		while (ft_isspace(line[++k]) == 0)
			;
		if (line[k] == '\0')
			parse->error = MAP;
		*i = k;
		return ;
	}
	else
		(*i)++;
}