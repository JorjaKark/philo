#include "philosophers.h"

int	is_positive_number(char *str)
{
	if (!str || *str == '\0')
		return (0);
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}
int	is_valid_int_max_min(long nbr)
{
	if (nbr > INT_MAX )
		return (0);
	return (1);
}
