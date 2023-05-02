/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 11:17:33 by jgagnon           #+#    #+#             */
/*   Updated: 2022/03/08 18:16:13 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_lecture(int fd, char *buffer)
{
	int		r_read;
	char	*lecture;

	r_read = 1;
	lecture = malloc(sizeof(char *) * (BUFFER_SIZE + 1));
	if (!lecture)
	{
		free(lecture);
		return (0);
	}
	while (r_read > 0 && ft_findreturn(buffer) == 0)
	{
		r_read = read(fd, lecture, BUFFER_SIZE);
		lecture[r_read] = '\0';
		buffer = ft_buffconcatenate(buffer, lecture);
	}
	free(lecture);
	return (buffer);
}

char	*ft_bufdup(const char *s)
{
	int		j;
	int		len;
	char	*ptr;

	j = 0;
	len = 0;
	while (s[len] != '\0' && s[len] != '\n')
		len++;
	ptr = (char *)malloc(sizeof(*ptr) * (len + 2));
	if (!ptr || s[0] == '\0')
	{
		free(ptr);
		return (0);
	}
	while (j < len + 1)
	{
		ptr[j] = s[j];
		j++;
	}
	ptr[j] = '\0';
	return (ptr);
}

char	*ft_subbuf(const char *s)
{
	char	*ptr;
	int		i;
	int		j;

	if (!s)
		return (0);
	i = 0;
	while (s[i] != '\0' && s[i] != '\n')
		i++;
	j = ft_strlen(s) - i;
	ptr = (char *)malloc(sizeof(char *) * (j + 1));
	if (!ptr)
	{
		free(ptr);
		return (0);
	}
	j = 0;
	while (s[i + j] != '\0')
	{
		ptr[j] = s[i + 1 + j];
		j++;
	}
	ptr[j] = '\0';
	free((char *)s);
	return (ptr);
}

char	*get_next_line(int fd)
{
	char		*r_ligne;
	static char	*buffer;

	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, buffer, 0) < 0)
		return (0);
	buffer = ft_lecture(fd, buffer);
	if (ft_findreturn(buffer) > 0)
	{
		r_ligne = ft_bufdup(buffer);
		buffer = ft_subbuf(buffer);
		return (r_ligne);
	}
	else
	{
		r_ligne = ft_bufdup(buffer);
		free(buffer);
		buffer = NULL;
		return (r_ligne);
	}
	return (0);
}
