#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <limits.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_philo	t_philo;

typedef struct s_program
{
	size_t				start_time;
	int					stop_simulation;
	int					nbr_philos;
	int					one;
	pthread_mutex_t		stop_mutex;
	pthread_mutex_t		dead_lock;
	pthread_mutex_t		meal_lock;
	pthread_mutex_t		write_lock;
	int					*stop_simulation_lock;
	t_philo				*philo;

}						t_program;

struct					s_philo
{
	pthread_t			thread;
	int					id;
	pthread_mutex_t		*forks;
	int					eating;
	pthread_mutex_t		last_meal_lock;
	pthread_mutex_t		count_meals_lock;
	size_t				last_meal;
	size_t				start_time;
	long				time_to_die;
	long				time_to_eat;
	long				time_to_sleep;
	int					count_meals;
	int					optional;
	int					nbr_times_to_eat;
	int					*dead;
	int					nbr_args;
	int					stop_simulation;
	pthread_mutex_t		*right_fork;
	pthread_mutex_t		*left_fork;
	t_program			*program;
};


//main


// checkers.c
int						is_positive_number(char *str);
int						is_valid_int_max_min(long nbr);

// forks.c
void					alloc_fork_array(t_program *program, t_philo *philo);
void					create_fork_mutexes(t_program *program, t_philo *philo,
							int i);
void					give_fork_to_philos(t_program *program, t_philo *philo,
							int i);
void	call_forks(t_program *program, t_philo *philo);

// ft_fprintf.c
void					ft_putstr_fd(int fd, char *str);
int						ft_fprintf(int fd, char *str);

// ft_libft.c
int						ft_strlen(char *str);
int						ft_isdigit(int c);
long					ft_atol(const char *nbr);
void *ft_memset(void *s, int c, size_t n);
void params_mutexes_main_thread(t_program *program, t_philo *philo, int argc, char **argv);
void    monitor_thread_and_join(t_program *program, t_philo *philo, pthread_t *monitor);
//ft_libft_utils.c
int						skip_sign(const char *nbr, int i, int *sign);
int						while_loop_atol(const char *nbr, int i, long *n,
							int sign);

// invalid_params.c
void					invalid_nbr_of_parameters(int *ret);
void					invalid_philo_nbr(int *ret);
void					invalid_time_to_die(int *ret);
void					invalid_time_to_eat(int *ret);
void					invalid_time_to_sleep(int *ret);
void					invalid_nbr_of_meals_per_philo(int *ret);
void					invalid_integer(int *ret);

// main.c
void					init_program_mutexes(t_program *program);
void					init_philo_mutexes(t_philo *philo);
void					set_philo_params(t_philo *philo, char **argv, int id);
void					set_philo_optional_params(t_philo *philo, char **argv,
							int argc);
void					init_philo_thread(t_philo *philo, t_program *program);
void					while_loop(t_program *program, t_philo *philo, int argc,
							char **argv);
void					init_program(t_program *program, t_philo *philo,
							int num_philos, char **argv);
void					manage_threads(t_program *program, t_philo *philo,
							pthread_t *monitor);
int						main(int argc, char **argv);

// monitor.c
void					set_simulation_stopped(t_program *program);
int						is_simulation_stopped(t_program *program);
int						does_simulation_stop_eat(t_philo *philo,
							int num_philos);
int						does_simulation_stop_dead(t_philo *philo);
int						handle_philo_death(t_program *program, int philo_index);
int						handle_all_eaten(t_program *program, int philo_index,
							int num_philos);
int						monitor_philo_state(t_program *program,
							int philo_index);
void					*does_simulation_stop_at_all_thread(void *arg);

// routine.c
int						try_take_right_fork(t_philo *philo, size_t start_time);
int						take_forks(t_philo *philo);
void					update_meal_state(t_philo *philo);
int						eat(t_philo *philo);
int						sleeping(t_philo *philo);
int						think(t_philo *philo);
int						check_meals_completed(t_philo *philo);
void					*philo_dinner_thread(void *arg);

// utils.c
size_t					get_time(void);
int						ft_usleep(size_t milliseconds);
void					print_state(t_philo *philo, char *state);
void					*ft_free(void *ptr);
int						clean_exit(t_program *program, t_philo *philo);

// validate_input.c
int						validate_negative_times(t_philo *philo, int *ret);
int						validate_limits(t_philo *philo);
int						validate_philo(t_program *program, t_philo *philo);
int						validate_input(t_program *program, t_philo *philo,
							int argc, char **argv);

#endif // PHILOSOPHERS_H
