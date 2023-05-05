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

int ParseInfo(char *map)
{
    t_parse *MapCheck;
    int     fd;

    fd = 0;
    if (ParseName(map)  != 0)
        return (-1);
    MapCheck = InitCheck();
    fd = open(map, O_RDONLY);
    if (fd < 0)
        return (-1);
    while ((first_parse(fd, MapCheck)) > 0 && MapCheck->error == GOOD)
		;
    printf("%s\n%s\n%s\n%s\n%u\n%u\n%c\n%d\n", MapCheck->NO, MapCheck->SO, MapCheck->WE,\
        MapCheck->EA, MapCheck->FloorColor, MapCheck->CeilingColor, MapCheck->map->player,\
		MapCheck->MapBeg);
    close(fd);
	check_ParseInfo(MapCheck);
	if (MapCheck->error == GOOD)
		fd = open(map, O_RDONLY);
	GetTmpMap(MapCheck, fd);
    return (0);
}

void ParsePath(t_parse* MapCheck, char *line, int j)
{
    int     i;
    char    *dir;

    i = 0;
    while (ft_isspace(line[i]) == 0)
        i++;
    dir = ft_calloc(3, sizeof(char));
    ft_strlcpy(dir, &line[i], 3);
    dir = ft_charjoinfree(dir, ' ');
    i += 2;
    while (ft_isspace(line[++i]) == 0)
        ;
    if (j == 0 && MapCheck->NO == NULL)
		MapCheck->NO = GetPath(dir, &line[i]);
    else if (j == 1 && MapCheck->SO == NULL)
        MapCheck->SO = GetPath(dir, &line[i]);
    else if (j == 2 && MapCheck->WE == NULL)
        MapCheck->WE = GetPath(dir, &line[i]);
    else if (j == 3 && MapCheck->EA == NULL)
        MapCheck->EA = GetPath(dir, &line[i]);
    dir = xfree(dir);
    dir = NULL;
}
