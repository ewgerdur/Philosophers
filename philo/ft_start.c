/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgerdur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 16:33:24 by wgerdur           #+#    #+#             */
/*   Updated: 2021/08/05 16:50:47 by wgerdur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	*ft_cycle_go(void *arg)
{
	t_philo	*p_s;

	p_s = (t_philo *)arg;
	if (p_s->i_f == 1)
	{
		my_usleep(p_s->eat_time);
	}
	while (1)
	{
		ft_forks(p_s);
		ft_eat(p_s);
		ft_lock_sleep(p_s);
	}
}

static void	ft_create_ph(t_buba *buba)
{
	int	i;

	i = 0;
	while (i < buba->n_philo)
	{
		buba->p_a[i].go_time = g_t(0);
		buba->p_a[i].time_end_eat = g_t(0);
		pthread_create(&buba->p_a[i].thread, NULL, ft_cycle_go, &buba->p_a[i]);
		i++;
	}
}

void	ft_die(int j, t_buba *buba)
{
	pthread_mutex_lock(buba->p_a[j].print);
	printf("%llums "CYAN" %d "RESET" "RED" died "RESET"\n", \
	g_t(buba->p_a[j].go_time), buba->p_a[j].number);
}

int	ft_start(t_buba *buba)
{
	int	j;

	ft_create_ph(buba);
	while (1)
	{
		j = 0;
		while (j < buba->n_philo)
		{
			if (g_t(0) - buba->p_a[j].time_end_eat \
			>= buba->p_a[j].die_time && buba->p_a[j].count_eat != 0)
			{
				ft_die(j, buba);
				return (0);
			}
			else if (check_philos(buba))
				return (0);
			j++;
		}
		my_usleep(1);
	}
	return (0);
}
