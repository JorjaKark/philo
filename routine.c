/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafferre <mafferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 14:30:52 by mafferre          #+#    #+#             */
/*   Updated: 2024/11/04 14:30:53 by mafferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	update_meal_state(t_philo *philo)
{
	pthread_mutex_lock(&philo->last_meal_lock);
	philo->last_meal = get_time();
	pthread_mutex_unlock(&philo->last_meal_lock);
	pthread_mutex_lock(&philo->count_meals_lock);
	philo->count_meals++;
	pthread_mutex_unlock(&philo->count_meals_lock);
}

int	check_meals_completed(t_philo *philo)
{
	if (philo->optional)
	{
		pthread_mutex_lock(&philo->program->meal_lock);
		pthread_mutex_lock(&philo->count_meals_lock);
		if (philo->count_meals >= philo->nbr_times_to_eat)
		{
			pthread_mutex_unlock(&philo->program->meal_lock);
			return (1);
		}
		pthread_mutex_unlock(&philo->program->meal_lock);
		pthread_mutex_unlock(&philo->count_meals_lock);
	}
	return (0);
}

void	*philo_dinner_thread(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->id % 2)
		ft_usleep(3);
	while (!is_simulation_stopped(philo->program))
	{
		if (check_meals_completed(philo))
			break ;
		if (!take_forks(philo))
			break ;
		if (!eat(philo))
			break ;
		if (!sleeping(philo))
			break ;
		if (!think(philo))
			break ;
	}
	return (NULL);
}
