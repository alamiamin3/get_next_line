/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalami <aalami@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 12:43:08 by aalami            #+#    #+#             */
/*   Updated: 2022/11/07 13:22:51 by aalami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*stash_resize(char *saved)
{
	size_t	i;
	char	*tmp;

	i = 0;
	while (saved[i] && saved[i] != '\n')
		i++;
	if (saved[i] == '\n')
	{
		i++;
		tmp = ft_strdup(saved + i);
		free(saved);
		saved = tmp;
		if (!saved[0])
		{
			free (saved);
			saved = 0;
		}
	}
	else
	{
		free (saved);
		saved = NULL;
	}
	return (saved);
}

static char	*get_my_line(char *saved)
{
	size_t	i;
	char	*line;

	i = 0;
	if (!saved)
		return (0);
	while (saved[i] && saved[i] != '\n')
		i++;
	if (saved[i] == '\n')
	{
		line = ft_substr(saved, 0, i + 1);
		return (line);
	}
	else
	{
		line = ft_strdup(saved);
		return (line);
	}
}

static char	*ft_read(int fd, char *saved)
{
	char	*buf;
	char	*tmp;
	ssize_t	readed;

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (0);
	readed = read(fd, buf, BUFFER_SIZE);
	buf[readed] = 0;
	while (readed > 0)
	{
		if (!saved)
			saved = ft_strdup("");
		tmp = ft_strjoin(saved, buf);
		if (!tmp)
			return (0);
		free (saved);
		saved = tmp;
		if (ft_strchr(saved, '\n'))
			break ;
		readed = read(fd, buf, BUFFER_SIZE);
		buf[readed] = 0;
	}
	free (buf);
	return (saved);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*saved[10240];

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		if (*(saved + fd))
			free (*(saved + fd));
		saved[fd] = NULL;
		return (0);
	}
	saved[fd] = ft_read(fd, *(saved + fd));
	if (!*(saved + fd))
		return (0);
	line = get_my_line(*(saved + fd));
	saved[fd] = stash_resize(*(saved + fd));
	return (line);
}
