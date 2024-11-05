/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libft_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafferre <mafferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 14:30:25 by mafferre          #+#    #+#             */
/*   Updated: 2024/11/04 14:30:26 by mafferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	skip_sign(const char *nbr, int i, int *sign)
{
	while ((nbr[i] >= 9 && nbr[i] <= 13) || nbr[i] == 32)
	{
		i++;
	}
	if (nbr[i] == '-')
	{
		*sign = -1;
		i++;
	}
	else if (nbr[i] == '+')
	{
		i++;
	}
	return (i);
}

int	while_loop_atol(const char *nbr, int i, long *n, int sign)
{
	while (ft_isdigit(nbr[i]))
	{
		if (*n > (LONG_MAX - (nbr[i] - '0')) / 10)
		{
			if (sign == 1)
				return (-2);
			return (-3);
		}
		*n = *n * 10 + (nbr[i] - '0');
		i++;
	}
	return (i);
}
