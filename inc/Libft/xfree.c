#include "libft.h"

void *xfree(void *ptr)
{
    if (ptr != NULL)
        free(ptr);
    return (ptr = NULL);
}