/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalami <aalami@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 16:11:17 by aalami            #+#    #+#             */
/*   Updated: 2022/11/02 21:30:38 by aalami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "get_next_line.h"

size_t get_new_line(char *str)
{
        size_t i;
        i = 0;
        while(str[i] != '\n')
        i++;
    return(i);
}

char    *get_line(char *str,size_t index)
{
   char *line;

    line = malloc(sizeof(char) * (index+2));
    if(!line)
        return (NULL);
   line = ft_substr(str,0,index+1);
    return(line);
}

int check_new_line(char *str)
{
    if(strchr(str,'\n'))
        return 1;
    return 0;
}

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

char    *get_next_line(int fd)
{
    char *buf;
    static char *stash;
    size_t i;
    ssize_t rd;
    char *line;
    
    if(fd < 0 || BUFFER_SIZE <= 0)
        return (0);
    buf = calloc(BUFFER_SIZE+1, sizeof(char));
    buf = ft_strdup("");
    if(!stash)
        stash = ft_strdup("");
     rd = 1;
    while(!check_new_line(stash) && rd != 0)
    {
        rd = read(fd,buf,BUFFER_SIZE);
        if (rd == 0)
            break;
        stash = ft_strjoin(stash,buf);

    }
    if(rd == 0)
       { free(buf);
        return(stash);}
    else if(check_new_line(stash))
    {
    i = get_new_line(stash);
    line = get_line(stash,i);
    stash = stash + i + 1;
    free(buf);
    return (line);
    }
    else
        return (0);
}

int main()
{
    int fd = open("file1.txt", O_RDWR,077777);

    int i = 0;
    while(i< 20)
    {
            printf("%s",get_next_line(fd));
            i++;
    }

}