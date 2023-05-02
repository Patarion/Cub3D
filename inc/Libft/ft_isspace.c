#include "libft.h"

int	ft_isspace(const char c)
{
    if (c == ' ' || c == '\n' || c == '\t'
        || c == '\v' || c == '\f' || c == '\r')
        return (0);
    return (1);
}