/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat_sleep_think.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafferre <mafferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 14:25:48 by mafferre          #+#    #+#             */
/*   Updated: 2024/11/04 14:44:51 by mafferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->program->meal_lock);
	print_state(philo, "is eating");
	update_meal_state(philo);
	pthread_mutex_unlock(&philo->program->meal_lock);
	ft_usleep(philo->time_to_eat);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
	if (philo->optional && (philo->count_meals >= philo->nbr_times_to_eat))
		return (0);
	return (1);
}

int	sleeping(t_philo *philo)
{
	print_state(philo, "is sleeping");
	ft_usleep(philo->time_to_sleep);
	return (1);
}

int	think(t_philo *philo)
{
	print_state(philo, "is thinking");
	return (1);
}
