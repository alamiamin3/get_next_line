/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   • get_next_line_bonus.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalami <aalami@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 15:54:14 by aalami            #+#    #+#             */
/*   Updated: 2022/11/06 16:02:10 by aalami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GETNEXTLINE_BONUS_H
#define GETNEXTLINE_BONUS_H
// #define BUFFER_SIZE 42
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

char    *stash_resize(char *saved);
char    *get_my_line(char *saved);
char    *ft_read(int fd, char *saved);
char    *get_next_line(int fd);
char	*ft_strdup(const char *s1);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(const char *s, int c);

#endif