#include "philosophers.h"

size_t get_time(void)
{
    struct timeval time;

    gettimeofday(&time, NULL);
    return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

int ft_usleep(size_t milliseconds)
{
    size_t  start;

    start = get_time();
    while ((get_time() - start) < milliseconds)
        usleep(500);
    return (0);
}

void print_state(t_philo *philo, char *state)
{
    size_t time;

    pthread_mutex_lock(&philo->program->write_lock);
    time = get_time() - philo->program->start_time;
    if (!philo->program->stop_simulation)
        printf("%zu %d %s\n", time, philo->id, state);
    pthread_mutex_unlock(&philo->program->write_lock);
}

void    *ft_free(void *ptr)
{
    if (ptr)
    {
        free(ptr);
        ptr = NULL;
    }
    return (NULL);
}

int clean_exit(t_program *program, t_philo *philo)
{   
    (void)philo;
    int i;
  
        i = -1;
        while (++i < program->nbr_philos)
        {
            pthread_mutex_destroy(&program->philo->forks[i]);
            pthread_mutex_destroy(&philo->last_meal_lock);
            pthread_mutex_destroy(&philo->count_meals_lock);
        }
        ft_usleep(1);
        pthread_mutex_destroy(&program->write_lock);
        pthread_mutex_destroy(&program->meal_lock); 
        pthread_mutex_destroy(&program->dead_lock);
        
        ft_free(program->philo->forks);
        ft_free(program->philo);
        ft_free(program);


    return (0);
}


