#include "get_next_line_bonus.h"

char    *stash_resize(char *saved)
{
    size_t i;
    size_t j;
    char *tmp;

    j = 0;
    i = 0;
    while(saved[i] && saved[i] != '\n')
        i++;
    if(saved[i] == '\n')
    {
        i++;
        tmp = ft_strdup(saved + i);
        free(saved);
        saved = tmp;
        if(!saved[0])
        {
            free(saved);
            saved = 0;
        }   
    }
    else
    {
        free(saved);
        saved = NULL;
    }
    return (saved);
}

char    *get_my_line(char *saved)
{
    size_t i;
    char *line;

    i = 0;
    if(!saved)
        return (0);
    while(saved[i] && saved[i] != '\n')
        i++;
    if(saved[i] == '\n')
    {
        line = ft_substr(saved,0,i + 1);
        return (line);
    }
    else
    {
        line = ft_strdup(saved);
        return(line);
    } 
}

char    *ft_read(int fd, char *saved)
{
    char buf[BUFFER_SIZE + 1];
    char *tmp;
    ssize_t readed;

    readed = read(fd,buf,BUFFER_SIZE);
    buf[readed] = 0;
    while(readed > 0)
    {
        if(!saved)
            saved = ft_strdup("");
        tmp = ft_strjoin(saved,buf);
        free(saved);
        saved = tmp;
        if(ft_strchr(saved,'\n'))
            break;
        readed = read(fd,buf,BUFFER_SIZE);
        buf[readed] = 0;
    }
    return (saved);
}

 char    *get_next_line(int fd)
{
    char *line;
    static char *saved[10240];
    
    if(fd < 0 || BUFFER_SIZE <= 0 || read(fd,0,0) < 0)
    { 
       if(*(saved+fd))
            free(*(saved+fd));
       *(saved+fd) = NULL;
       return(0);
    }
    saved[fd] = ft_read(fd, *(saved+fd));
    if(!*(saved+fd))
        return (0);
    line = get_my_line(*(saved+fd));
    saved[fd] = stash_resize(*(saved+fd));
    return (line);
}