#include "philosophers.h"

void ft_putstr_fd(int fd, char *str) 
{
    if (!str)
        return;
    while (*str)
        write(fd, str++, 1);
}

int ft_fprintf(int fd, char *str) 
{
    if (!str)
        return -1;

    ft_putstr_fd(fd, str);
    return 0;
}
