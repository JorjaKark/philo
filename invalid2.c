/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   invalid2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafferre <mafferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 14:25:41 by mafferre          #+#    #+#             */
/*   Updated: 2024/11/04 14:48:48 by mafferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	invalid_nbr_of_parameters(void)
{
	ft_fprintf(2, "Invalid number of parameters.\n");
}

void	invalid_integer(int *ret)
{
	ft_fprintf(2, "Invalid integer: out of range.\n");
	*ret = 0;
}
