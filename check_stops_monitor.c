/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_stops_monitor.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafferre <mafferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 14:30:09 by mafferre          #+#    #+#             */
/*   Updated: 2024/11/11 13:40:44 by mafferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	does_simulation_stop_eat(t_philo *philo, int num_philos)
{
	int	i;

	if (!philo->optional)
		return (0);
	i = -1;
	while (++i < num_philos)
	{
		pthread_mutex_lock(&philo->program->meal_lock);
		if (philo->program->philo[i].count_meals
			< philo->program->philo[i].nbr_times_to_eat)
		{
			pthread_mutex_unlock(&philo->program->meal_lock);
			return (0);
		}
		pthread_mutex_unlock(&philo->program->meal_lock);
	}
	return (1);
}

int	does_simulation_stop_dead(t_philo *philo)
{
	size_t	current_time;
	size_t	time_since_last_meal;

	pthread_mutex_lock(&philo->last_meal_lock);
	current_time = get_time();
	time_since_last_meal = current_time - philo->last_meal;
	pthread_mutex_unlock(&philo->last_meal_lock);
	if (time_since_last_meal > (size_t)philo->time_to_die)
	{
		return (1);
	}
	return (0);
}
