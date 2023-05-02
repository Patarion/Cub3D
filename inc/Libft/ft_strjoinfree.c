#include "libft.h"

char	*ft_strjoin_free(char *s1, char const *s2)
{
    int		c;
    int		i;
    char	*ptr;

    if (!s1 || !s2)
        return (0);
    c = ft_strlen((char *)s1) + ft_strlen((char *)s2);
    ptr = (char *)malloc(sizeof(*ptr) * (c + 1));
    if (!ptr)
        return (0);
    i = 0;
    c = 0;
    while (s1[i] != '\0')
    {
        ptr[i] = s1[i];
        i++;
    }
    while (s2[c] != '\0')
    {
        ptr[i + c] = s2[c];
        c++;
    }
    ptr[i + c] = '\0';
    s1 = xfree(s1);
    return (ptr);
}