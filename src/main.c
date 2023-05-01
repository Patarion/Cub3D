#include "../inc/Cub3D.h"

int main(int argc, char **argv) {
    if (argc != 2)
    {
        printf("Veuillez fournir un fichier au format .cub");
        return (-1);
    }
    if (ParseInfo(argv[1]) != 0)
        printf("La map n'est pas valide ou n'a pas toute les bonnes info");
    return 0;
}
