/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgerdur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 12:18:09 by wgerdur           #+#    #+#             */
/*   Updated: 2021/08/06 12:18:14 by wgerdur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# define RESET		"\033[0m"
# define RED		"\x1b[31m"
# define GREEN		"\x1b[32m"
# define YELLOW		"\x1b[33m"
# define BLUE		"\033[34m"
# define MAGENTA	"\033[35m"
# define WHITE		"\033[37m"
# define CYAN		"\033[36m"

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_philo
{
	int				count_eat;
	int				f_6;
	int				number;
	int				i_f;
	uint64_t		die_time;
	uint64_t		eat_time;
	uint64_t		time_end_eat;
	uint64_t		sleep_time;
	uint64_t		go_time;
	pthread_t		thread;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*print;
}					t_philo;

typedef struct s_buba
{
	int				n_philo;
	t_philo			*p_a;
	pthread_mutex_t	print;
	pthread_mutex_t	*forks;
}					t_buba;

int			ft_atoi(const char *str);
int			ft_check_digit(char *argv);
uint64_t	g_t(uint64_t start);
void		my_usleep(uint64_t time);
int			ft_start(t_buba *buba);
int			check_philos(t_buba *buba);
int			ft_init1(char **argv, int argc, t_buba *buba);
void		ft_forks(t_philo *p_s);
void		ft_eat(t_philo *p_s);
void		ft_lock_sleep(t_philo *p_s);

#endif
