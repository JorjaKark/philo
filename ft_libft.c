#include "philosophers.h"

int	ft_strlen(char *str)
{
	int	i;

	if (str == NULL)
		return (0);
	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int ft_isdigit(int c) 
{
    return (c >= '0' && c <= '9');
}

long ft_atol(const char *nbr)
{
    int i = 0;
    long n = 0;
    int sign = 1;
    int result;
    
    i = skip_sign(nbr, i, &sign);
    
    if (!ft_isdigit(nbr[i]))
    {
        return -1;
    }
    
    result = while_loop_atol(nbr, i, &n, sign);
    
    if (result == -2)
        return LONG_MAX;
    if (result == -3)
        return LONG_MIN;
    
    if (nbr[result] != '\0')
    {
        return -1;
    }
    
    return n * sign;
}

void *ft_memset(void *s, int c, size_t n)
{
    unsigned char *ptr = s;  
    unsigned char value = (unsigned char)c; 

    while (n--)
    {
        *ptr++ = value;  
    }

    return s;
}