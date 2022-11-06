/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   • get_next_line_bonus_utils.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalami <aalami@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 15:53:24 by aalami            #+#    #+#             */
/*   Updated: 2022/11/06 15:53:40 by aalami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strdup(const char *s1)
{
	char	*p;
	size_t	i;

	i = 0;
	p = malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (!p)
		return (NULL);
	while (*(s1 + i))
	{
		*(p + i) = *(s1 + i);
		i++;
	}
	*(p + i) = '\0';
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
	size_t	size;

	if (!s1 || !s2)
		return (NULL);
	size = (ft_strlen(s1) + ft_strlen(s2));
	p = (char *)malloc((size + 1) * sizeof(char));
	if (!p)
		return (NULL);
	while (*(s1))
			*p++ = *s1++;
	while (*(s2))
	{
		*p++ = *s2++;
	}
	*p = '\0';
	p = p - (size);
	return (p);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	if (c < 0)
		return (0);
	i = 0;
	while (s[i] && (char)s[i] != (char)c)
		i++;
	if ((char)s[i] == (char)c)
		return ((char *)s + i);
	else
		return (NULL);
}
