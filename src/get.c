#include "../inc/Cub3D.h"

char *GetPath(char *dir, char *line)
{
	char	*r_get;
	char	*path;
	int		i;

	r_get = NULL;
	path = NULL;
	i = 0;
	while (ft_isspace(line[i]) != 0 && line[i] != '\0')
		i++;
	path = ft_substr(line, 0, i);
	r_get = ft_strjoin(dir, path);
	path = xfree(path);
	return (r_get);
}
