NAME = philo

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = main.c check_stops_monitor.c checkers.c forks.c ft_fprintf.c ft_libft.c \
ft_libft_utils.c invalid1.c invalid2.c monitor_utils.c monitor.c routine.c utils.c validate_input.c\
eat_sleep_think.c init_philos.c init_program.c take_forks.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
