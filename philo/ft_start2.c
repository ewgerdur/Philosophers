/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgerdur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 16:32:59 by wgerdur           #+#    #+#             */
/*   Updated: 2021/08/05 16:52:35 by wgerdur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_forks(t_philo *p_s)
{
	pthread_mutex_lock(p_s->print);
	printf("%llums "CYAN" %d "RESET" "BLUE" is thinking "RESET"\n", \
	g_t(p_s->go_time), p_s->number);
	pthread_mutex_unlock(p_s->print);
	pthread_mutex_lock(p_s->l_fork);
	pthread_mutex_lock(p_s->print);
	printf("%llums "CYAN" %d "RESET" "YELLOW" has taken a fork "RESET"\n", \
	g_t(p_s->go_time), p_s->number);
	pthread_mutex_unlock(p_s->print);
	pthread_mutex_lock(p_s->r_fork);
	pthread_mutex_lock(p_s->print);
	printf("%llums "CYAN" %d "RESET" "YELLOW" has taken a fork "RESET"\n", \
	g_t(p_s->go_time), p_s->number);
	pthread_mutex_unlock(p_s->print);
	p_s->time_end_eat = g_t(0);
}

void	ft_eat(t_philo *p_s)
{
	pthread_mutex_lock(p_s->print);
	printf("%llums "CYAN" %d "RESET" "GREEN" is eating "RESET"\n", \
	g_t(p_s->go_time), p_s->number);
	pthread_mutex_unlock(p_s->print);
	my_usleep(p_s->eat_time);
}

void	ft_lock_sleep(t_philo *p_s)
{
	pthread_mutex_unlock(p_s->l_fork);
	pthread_mutex_unlock(p_s->r_fork);
	pthread_mutex_lock(p_s->print);
	printf("%llums "CYAN" %d "RESET" "MAGENTA" is sleeping "RESET"\n", \
	g_t(p_s->go_time), p_s->number);
	pthread_mutex_unlock(p_s->print);
	my_usleep(p_s->sleep_time);
	if (p_s->count_eat != -1)
		p_s->count_eat -= 1;
	if (p_s->count_eat == 0)
	{
		p_s->f_6 = -1;
		return ;
	}
}
