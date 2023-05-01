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
    if (line[++i] == '1' || line[i] == '0')
    {
        while (line[++i] == '1')
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
    while (line[++i] == '1')
        ;
    while (line[i] == '0' || ft_charsetcmp(line[i], "NESW") == 0)
    {
        if (ft_charsetcmp(line[i], "NESW") == 0 && parse->map->player == false)
            parse->map->player = true;
        else if (ft_charsetcmp(line[i], "NESW") == 0 && parse->map->player == true)
        {
            parse->error = MAP;
            return ;
        }
        i++;
        while (line[i] == '1')
            i++;
    }
    if (line[i] != '\0')
        parse->error = MAP;
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
}