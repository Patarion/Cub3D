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
	data->error = GOOD;
    data->map = malloc(sizeof(t_map));
    data->map->adj_line_len = ft_calloc(4, sizeof(int));
    data->map->player = 0;
    data->map->first_line = false;
    data->map->last_line = false;
    data->map->map_layout = NULL;
    data->map->player_x = 0;
    data->map->player_y = 0;
    data->map->direction = 0;
    return (data);
}
