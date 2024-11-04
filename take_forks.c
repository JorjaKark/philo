/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_forks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafferre <mafferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 14:36:14 by mafferre          #+#    #+#             */
/*   Updated: 2024/11/04 14:56:16 by mafferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	take_first_fork(t_philo *philo, pthread_mutex_t **first_fork,
		pthread_mutex_t **second_fork)
{
	if (philo->id % 2 == 0)
	{
		*first_fork = philo->right_fork;
		*second_fork = philo->left_fork;
	}
	else
	{
		*first_fork = philo->left_fork;
		*second_fork = philo->right_fork;
	}
	pthread_mutex_lock(*first_fork);
	print_state(philo, "has taken a fork");
	if (philo->program->one)
	{
		pthread_mutex_unlock(*first_fork);
		return (0);
	}
	return (1);
}

int	take_second_fork(t_philo *philo, pthread_mutex_t *first_fork,
		pthread_mutex_t *second_fork)
{
	size_t	start_time;

	start_time = get_time();
	while (1)
	{
		if (pthread_mutex_lock(second_fork) == 0)
		{
			print_state(philo, "has taken a fork");
			return (1);
		}
		if (is_simulation_stopped(philo->program) || get_time()
			- start_time >= 1000)
		{
			pthread_mutex_unlock(first_fork);
			return (0);
		}
		ft_usleep((int)0.1);
	}
}

int	take_forks(t_philo *philo)
{
	pthread_mutex_t	*first_fork;
	pthread_mutex_t	*second_fork;

	if (!take_first_fork(philo, &first_fork, &second_fork))
		return (0);
	return (take_second_fork(philo, first_fork, second_fork));
}
