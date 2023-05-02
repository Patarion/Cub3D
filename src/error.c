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
    clear_data(data);
    data = xfree(data);
    exit(0);
}


void	check_ParseInfo(t_parse *data)
{
	if (data->NO == NULL || data->SO == NULL || data->WE == NULL\
		|| data->EA == NULL)
		data->error = PATH;
	else if (data->map->first_line == false || data->map->last_line == false)
		data->error = MAP;
	else if (data->treat_Ceiling == false || data->treat_Floor == false)
		data->error = COLOR;
	if (data->error != GOOD)
		error_handler(data);
}
