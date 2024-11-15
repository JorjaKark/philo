/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafferre <mafferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 14:30:43 by mafferre          #+#    #+#             */
/*   Updated: 2024/11/04 14:30:44 by mafferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	set_simulation_stopped(t_program *program)
{
	pthread_mutex_lock(&program->stop_mutex);
	program->stop_simulation = 1;
	pthread_mutex_unlock(&program->stop_mutex);
}

int	is_simulation_stopped(t_program *program)
{
	int	stopped;

	pthread_mutex_lock(&program->stop_mutex);
	stopped = program->stop_simulation;
	pthread_mutex_unlock(&program->stop_mutex);
	return (stopped);
}
