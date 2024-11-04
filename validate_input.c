#include "philosophers.h"

int validate_negative_times(t_philo *philo, int *ret)
{
    if (philo->time_to_die < 0)
    {
        invalid_time_to_die(ret);
        return 0;
    }
    if (philo->time_to_eat < 0)
    {
        invalid_time_to_eat(ret);
        return 0;
    }
    if (philo->time_to_sleep < 0)
    {
        invalid_time_to_sleep(ret);
        return 0;
    }
    if (philo->optional && philo->nbr_times_to_eat < 0)
    {
        invalid_nbr_of_meals_per_philo(ret);
        return 0;
    }
    return 1;
}

int validate_limits(t_philo *philo)
{
    return (is_valid_int_max_min(philo->time_to_die) && 
            is_valid_int_max_min(philo->time_to_eat) && 
            is_valid_int_max_min(philo->time_to_sleep) &&
            (!philo->optional || 
             is_valid_int_max_min(philo->nbr_times_to_eat)));
}

int validate_philo(t_program *program, t_philo *philo)
{
    int ret;

    ret = 1;
    if (program != NULL && program->nbr_philos < 0 )
    {
        free(program);
        invalid_philo_nbr(&ret);
        return ret;
    }
    if (!validate_limits(philo))
    {
        free(program);
        invalid_integer(&ret);
        return ret;
    }
    if (!validate_negative_times(philo, &ret))
    {
        free(program);
        return ret;
    }
        
    return ret;
}

int validate_input(t_program *program, t_philo *philo, int argc, char **argv)
{
    (void)argc;
	program = malloc(sizeof(t_program));
	program->nbr_philos = ft_atol(argv[1]);
	philo->time_to_die = ft_atol(argv[2]);
	philo->time_to_eat = ft_atol(argv[3]);
	philo->time_to_sleep = ft_atol(argv[4]);
	if (argv[5])
	{
		philo->nbr_times_to_eat = ft_atol(argv[5]);
		philo->optional = 1;
	}
	else
	{
		philo->nbr_times_to_eat = -2;
		philo->optional = 0;
	}
    int validation_result = validate_philo(program, philo);
    if (!validation_result)
    {
        free(program);
        return 0;
    }
    return validation_result;
}

