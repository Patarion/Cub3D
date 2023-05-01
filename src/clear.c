#include "../inc/Cub3D.h"

void clear_data(t_parse *data)
{
    if (data->NO != NULL)
        data->NO = xfree(data->NO);
    if (data->SO != NULL)
        data->SO = xfree(data->SO);
    if (data->WE != NULL)
        data->WE = xfree(data->WE);
    if (data->EA != NULL)
        data->EA = xfree(data->EA);
    data->FloorColor = 0;
    data->CeilingColor = 0;
}