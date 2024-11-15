/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_program.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafferre <mafferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 14:30:34 by mafferre          #+#    #+#             */
/*   Updated: 2024/11/04 14:48:33 by mafferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	init_program_mutexes(t_program *program)
{
	pthread_mutex_init(&program->write_lock, NULL);
	pthread_mutex_init(&program->meal_lock, NULL);
	pthread_mutex_init(&program->dead_lock, NULL);
	pthread_mutex_init(&program->stop_mutex, NULL);
}

void	init_program(t_program *program, t_philo *philo, int num_philos,
		char **argv)
{
	ft_memset(program, 0, sizeof(t_program));
	ft_memset(philo, 0, sizeof(t_philo) * num_philos);
	program->stop_simulation = 0;
	program->nbr_philos = ft_atol(argv[1]);
}
