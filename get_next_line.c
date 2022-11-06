/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalami <aalami@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 16:11:17 by aalami            #+#    #+#             */
/*   Updated: 2022/11/06 17:55:40 by aalami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
            if(readed == -1)
        {
             printf("return %zu\n",readed);
            if(saved)
                free(saved);
            return(0);
        }
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
    //  printf("this is : %lu\n",readed);
    // printf("this is : %s\n",saved);
    return (saved);
}

 char    *get_next_line(int fd)
{
    char *line;
    static char *saved;
    if(fd < 0 || BUFFER_SIZE <= 0 || read(fd,0,0) < 0)
    { 
       if(saved)
            free(saved);
       saved = NULL;
       return(0);
    }
    saved = ft_read(fd, saved);
    if(!saved )
        return (0);
    line = get_my_line(saved);
    saved = stash_resize(saved);
    return (line);
}

// void f()
// {
//     system("leaks a.out");
// }

// // int main()
// // {
// //     // atexit(f);
// //     int fd = open("file1.txt", O_RDWR,077777);
// //     close(fd);
// //     printf("%zd",read(fd,0,0));

// //     // int i = 0;
// //     // printf("\t\t---------------------------------------------BEFORE CLOSE-------------------------------------------------\t\t\n\n");
// //     // while(i++ < 2)
// //     //  printf("%s",get_next_line(fd));
     
// //     //  close(open("file1.txt", O_RDWR,077777));
// //     // printf("\n\n\t\t---------------------------------------------AFTER CLOSE-------------------------------------------------\t\t\n\n");
    
// //     // //  fd = open("file1.txt", O_RDWR,077777);
// //     //  i = 0;
// //     //     while(i++ < 4)
// //     //  printf("%s",get_next_line(open("file1.txt", O_RDWR,077777)));
// // }