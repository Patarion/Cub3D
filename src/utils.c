#include "../inc/Cub3D.h"

int first_parse(int fd, t_parse *data)
{
    char    	*line;
    char    	read_ret[2];
    int     	r_read;
	static int	nb_line;

    line = NULL;
    r_read = 0;
    while ((r_read = read(fd, &read_ret, 1)) > 0)
    {
        if (read_ret[0] == '\n')
            break ;
        if (line == NULL)
            line = ft_strdup(read_ret);
        else
            line = ft_strjoin_free(line, read_ret);
    }
	nb_line++;
	if ((data->map->first_line == true && data->map->last_line == true)\
		&& (read_ret[0] == '\n' || line != NULL))
		data->error = CUB_FILE;
	if (line != NULL && data->error == GOOD)
    	ParseLine(line, data);
    line = xfree(line);
	if (data->map->first_line == true && data->MapBeg == 0) 
		data->MapBeg = nb_line;
    return (r_read);
}

unsigned int	ft_Uatoi(const char *str, t_parse *data)
{
    unsigned int	nb;
    int				i;

    nb = 0;
    i = 0;
    while (str[i] >= 0x09 && (str[i] <= 0x0d || str[i] == 0x20))
        i++;
    while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
    {
        if (str[i] == '-' || str[i] == '+' ||
            ft_isalpha(str[i]) == 1)
        {
            data->error = COLOR;
            return (0);
        }
        nb = (nb * 10) + (str[i] - 0x30);
        i++;
    }
    if (nb > 255)
        data->error = COLOR;
    return (nb);
}

void	print_double_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i] != NULL)
	{
		printf("%s", tab[i]);
		i++;
	}
}

char	*ez_gnl(int fd)
{
	char    	*line;
    char    	read_ret[2];
    int     	r_read;

	line = NULL;
	r_read = 0;
	read_ret[1] = '\0';
	while ((r_read = read(fd, &read_ret, 1)) > 0)
	{
        if (line == NULL)
            line = ft_strdup(read_ret);
        else
            line = ft_strjoin_free(line, read_ret);
		if (read_ret[0] == '\n')
            break ;
    }
	return (line);
}