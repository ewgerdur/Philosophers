NAME	   = philo

SRCS	   = main.c ft_libft.c ft_init.c ft_time.c ft_start.c ft_start2.c

OBJS	   =  ${SRCS:.c=.o}

FLAGS	   = -Wall -Wextra -Werror -pthread

CC         = gcc

$(NAME):     $(OBJS)
				$(CC) $(FLAGS) $(OBJS) -o $(NAME)

all:        $(NAME)

clean:
			rm -f ${OBJS}

fclean:		clean
			rm -f ${NAME}

re:			fclean all