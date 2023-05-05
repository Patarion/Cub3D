#include "../inc/Cub3D.h"

char	*GetPath(char *dir, char *line)
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

void	GetTmpMap(t_parse *data, int fd)
{
	char	*r_gnl;
	int		i;

	r_gnl = NULL;
	i = 0;
	if (!fd)
		return ;
	while (data->MapBeg > 1)
	{
		r_gnl = xfree(ez_gnl(fd));
		data->MapBeg--;
	}
	data->map->map_layout = malloc(sizeof(char *) * (data->map->nb_lines + 1));
	while ((r_gnl = ez_gnl(fd)) != NULL)
	{
		data->map->map_layout[i] = r_gnl;
		i++;
	}
	data->map->map_layout[i] = NULL;
	print_double_tab(data->map->map_layout);
}