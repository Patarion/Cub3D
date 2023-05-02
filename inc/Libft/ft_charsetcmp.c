#include "libft.h"

int ft_charsetcmp(char chr, char *set)
{
    int i;

    i = -1;
    while (set[++i] != '\0')
    {
        if (chr == set[i])
            return (0);
    }
    return (-1);
}