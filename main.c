/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafferre <mafferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 14:24:45 by mafferre          #+#    #+#             */
/*   Updated: 2024/11/04 16:50:52 by mafferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	init_philo_thread(t_philo *philo, t_program *program)
{
	pthread_mutex_lock(&philo->last_meal_lock);
	philo->last_meal = program->start_time;
	pthread_mutex_unlock(&philo->last_meal_lock);
	pthread_create(&philo->thread, NULL, philo_dinner_thread, philo);
}

void	params_mutexes_main_thread(t_program *program, t_philo *philo, int argc,
		char **argv)
{
	int	i;

	i = 0;
	init_program_mutexes(program);
	program->start_time = get_time();
	while (i < program->nbr_philos)
	{
		set_philo_params(&philo[i], argv, i);
		philo[i].program = program;
		set_philo_optional_params(&philo[i], argv, argc);
		init_philo_mutexes(&philo[i]);
		init_philo_thread(&philo[i], program);
		i++;
	}
}

void	monitor_thread_and_join(t_program *program, t_philo *philo,
		pthread_t *monitor)
{
	int	i;

	i = 0;
	pthread_create(monitor, NULL, does_simulation_stop_at_all_thread, program);
	pthread_join(*monitor, NULL);
	while (i < program->nbr_philos)
	{
		pthread_join(philo[i].thread, NULL);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_program	*program;
	t_philo		temp;
	int			num_philos;
	t_philo		*philo;
	pthread_t	monitor;

	if ((argc >= 1 && argc <= 4) || argc > 6)
	{
		invalid_nbr_of_parameters();
		return (0);
	}
	num_philos = ft_atol(argv[1]);
	if (!validate_input(NULL, &temp, argv))
		return (1);
	philo = (t_philo *)malloc(sizeof(t_philo) * num_philos);
	program = (t_program *)malloc(sizeof(t_program));
	init_program(program, philo, num_philos, argv);
	call_forks(program, philo);
	params_mutexes_main_thread(program, philo, argc, argv);
	monitor_thread_and_join(program, philo, &monitor);
	clean_exit(program, program->philo);
	return (0);
}
