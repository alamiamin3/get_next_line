/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalami <aalami@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 20:22:12 by aalami            #+#    #+#             */
/*   Updated: 2022/11/02 20:49:06 by aalami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*p;
	size_t			i;
	
	p = malloc(size * count);
	if (!p)
		return (NULL);
	i = 0;
	while (i < size)
	{
		*(unsigned char *)(p + i) = 0;
		i++;
	}
	return (p);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	unsigned int	j;
	char			*p;

	j = 0;
	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	if (len > (ft_strlen(s) - start))
		len = ft_strlen(s) - start;
	i = start;
	p = malloc(sizeof(char) * (len + 1));
	if (!p)
		return (NULL);
	while (len > 0 && s[i])
	{
		p[j] = s[i];
		i++;
		j++;
		len--;
	}
	p[j] = '\0';
	return (p);
}

size_t	ft_strlen(const char *s)
{
	size_t	n;

	n = 0;
	while (s[n])
		n++;
	return (n);
}


char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*p;
	size_t	i;
	size_t	j;
	size_t size;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	j = 0;
	size = (ft_strlen(s1) + ft_strlen(s2));
	
	p = (char *)malloc(sizeof(char) * (size + 1));
	
	if (!p)
		return (NULL);
	while (*(s1 + i))
	{
		p[i] = s1[i];
		i++;
	}
	while (*(s2 + j))
	{
		p[i] = s2[j];
		i++;
		j++;
	}
	p[i] = '\0';
	return (p);
}
