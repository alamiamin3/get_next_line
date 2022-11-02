#ifndef GETNEXTLINE_H
#define GETNEXTLINE_H
#define BUFFER_SIZE 42
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

size_t get_new_line(char *str);
char    *get_line(char *str,size_t index);
int check_new_line(char *str);
char	*ft_strdup(const char *s1);
char    *get_next_line(int fd);
void	*ft_calloc(size_t count, size_t size);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);

#endif