/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafferre <mafferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 14:30:48 by mafferre          #+#    #+#             */
/*   Updated: 2024/11/11 13:28:56 by mafferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	handle_philo_death(t_program *program, int philo_index)
{
	if (does_simulation_stop_dead(&program->philo[philo_index]))
	{
		pthread_mutex_lock(&program->write_lock);
		if (!is_simulation_stopped(program))
		{
			set_simulation_stopped(program);
			printf("%zu %d died\n", get_time() - program->start_time,
				program->philo[philo_index].id);
		}
		pthread_mutex_unlock(&program->write_lock);
		return (1);
	}
	return (0);
}

int	handle_all_eaten(t_program *program, int philo_index, int num_philos)
{
	if (program->philo[philo_index].optional
		&& does_simulation_stop_eat(&program->philo[philo_index], num_philos))
	{
		pthread_mutex_lock(&program->write_lock);
		if (!is_simulation_stopped(program))
		{
			set_simulation_stopped(program);
		}
		pthread_mutex_unlock(&program->write_lock);
		return (1);
	}
	return (0);
}

int	monitor_philo_state(t_program *program, int philo_index)
{
	if (is_simulation_stopped(program))
		return (1);
	if (handle_philo_death(program, philo_index))
		return (1);
	if (handle_all_eaten(program, philo_index, program->nbr_philos))
		return (1);
	return (0);
}

void	*does_simulation_stop_at_all_thread(void *arg)
{
	int			i;
	int			num_philos;
	t_program	*program;

	program = (t_program *)arg;
	num_philos = program->nbr_philos;
	while (!is_simulation_stopped(program))
	{
		i = 0;
		while (i < num_philos)
		{
			if (monitor_philo_state(program, i))
				return (NULL);
			i++;
		}
	}
	return (NULL);
}
