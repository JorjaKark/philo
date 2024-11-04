#include "philosophers.h"

void invalid_philo_nbr(int *ret) {
    ft_fprintf(2, "Invalid philosophers number.\n");
    *ret = 0;
}

void invalid_time_to_die(int *ret) {
    ft_fprintf(2, "Invalid time to die.\n");
    *ret = 0;
}

void invalid_time_to_eat(int *ret) {
    ft_fprintf(2, "Invalid time to eat.\n");
    *ret = 0;
}

void invalid_time_to_sleep(int *ret) {
    ft_fprintf(2, "Invalid time to sleep.\n");
    *ret = 0;
}

void invalid_nbr_of_meals_per_philo(int *ret) {
    ft_fprintf(2, "Invalid number of meals per philosopher.\n");
    *ret = 0;
}

