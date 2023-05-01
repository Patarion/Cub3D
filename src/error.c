#include "../inc/Cub3D.h"

void error_handler(t_parse *data)
{
    if (data->error == PATH)
        printf("L'un des chemin des textures est invalide\n");
    else if (data->error == COLOR)
        printf("L'une des couleur fournise a une erreur ou est manquante\n");
    else if (data->error == MAP)
        printf("La carte fournise a une erreur de format\n");
    clear_data(data);
    data = xfree(data);
    exit(0);
}
