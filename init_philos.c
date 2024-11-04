#include "philosophers.h"

void init_philo_mutexes(t_philo *philo)
{
    pthread_mutex_init(&philo->last_meal_lock, NULL);
    pthread_mutex_init(&philo->count_meals_lock, NULL);
}

void set_philo_params(t_philo *philo, char **argv, int id)
{
    philo->id = id + 1;
    philo->time_to_die = ft_atol(argv[2]);
    philo->time_to_eat = ft_atol(argv[3]);
    philo->time_to_sleep = ft_atol(argv[4]);
}
void set_philo_optional_params(t_philo *philo, char **argv, int argc)
{
    if (argc == 6)
    {
        philo->nbr_times_to_eat = ft_atol(argv[5]);
        philo->optional = 1;
        philo->count_meals = 0;
    }
    else
    {
        philo->nbr_times_to_eat = -1;
        philo->optional = 0;
    }
    
}