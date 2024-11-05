/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafferre <mafferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 14:30:19 by mafferre          #+#    #+#             */
/*   Updated: 2024/11/04 14:45:01 by mafferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	alloc_fork_array(t_program *program, t_philo *philo)
{
	pthread_mutex_t	*forks;

	forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t)
			* program->nbr_philos);
	if (!forks)
		return ;
	philo->forks = forks;
}

void	create_fork_mutexes(t_program *program, t_philo *philo, int i)
{
	while (i < program->nbr_philos)
	{
		pthread_mutex_init(&philo->forks[i], NULL);
		i++;
	}
}

void	give_fork_to_philos(t_program *program, t_philo *philo, int i)
{
	while (i < program->nbr_philos)
	{
		philo[i].left_fork = &philo->forks[i];
		philo[i].right_fork = &philo->forks[(i + 1) % program->nbr_philos];
		i++;
	}
}

void	call_forks(t_program *program, t_philo *philo)
{
	if (program->nbr_philos == 1)
		program->one = 1;
	program->philo = philo;
	alloc_fork_array(program, philo);
	create_fork_mutexes(program, philo, 0);
	give_fork_to_philos(program, philo, 0);
}
