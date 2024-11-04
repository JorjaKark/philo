#include "philosophers.h"

int take_forks(t_philo *philo) {
    size_t start_time = get_time();
    pthread_mutex_t *first_fork;
    pthread_mutex_t *second_fork;

    // Even philosophers take right fork first, odd take left fork first
    if (philo->id % 2 == 0) {
        first_fork = philo->right_fork;
        second_fork = philo->left_fork;
    } else {
        first_fork = philo->left_fork;
        second_fork = philo->right_fork;
    }

    pthread_mutex_lock(first_fork);
    print_state(philo, "has taken a fork");

    if (philo->program->one) {
        pthread_mutex_unlock(first_fork);
        return 0;
    }

    // Try to take second fork
    while (1) {
        if (pthread_mutex_lock(second_fork) == 0) {
            print_state(philo, "has taken a fork");
            return 1;
        }
        
        if (is_simulation_stopped(philo->program) || 
            get_time() - start_time >= 1000) {
            pthread_mutex_unlock(first_fork);
            return 0;
        }
        ft_usleep((int)0.1);
    }
}

int eat(t_philo *philo)
{
    pthread_mutex_lock(&philo->program->meal_lock);
    print_state(philo, "is eating");
    update_meal_state(philo);
    pthread_mutex_unlock(&philo->program->meal_lock);
    
    ft_usleep(philo->time_to_eat);
    pthread_mutex_unlock(philo->left_fork);
    pthread_mutex_unlock(philo->right_fork);
    
    if (philo->optional && (philo->count_meals >= philo->nbr_times_to_eat))
        return 0;
    return 1;
}
int sleeping(t_philo *philo)
{
    print_state(philo, "is sleeping");
    ft_usleep(philo->time_to_sleep);
    return 1;
}


int think(t_philo *philo)
{
    print_state(philo, "is thinking");
    return 1;
}