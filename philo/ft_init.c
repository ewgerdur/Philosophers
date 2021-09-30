/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgerdur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 16:02:22 by wgerdur           #+#    #+#             */
/*   Updated: 2021/08/03 16:02:26 by wgerdur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_init2(char **argv, int argc, int i, t_buba *buba)
{
	buba->p_a[i].number = i + 1;
	if (buba->p_a[i].number % 2 == 0)
		buba->p_a[i].i_f = 1;
	else
		buba->p_a[i].i_f = 0;
	buba->p_a[i].time_end_eat = 0;
	buba->p_a[i].die_time = ft_atoi(argv[2]);
	buba->p_a[i].eat_time = ft_atoi(argv[3]);
	buba->p_a[i].sleep_time = ft_atoi(argv[4]);
	if (argc == 6)
	{
		buba->p_a[i].count_eat = ft_atoi(argv[5]);
		buba->p_a[i].f_6 = 0;
	}
	else
		buba->p_a[i].count_eat = -1;
	buba->p_a[i].l_fork = &buba->forks[i];
	buba->p_a[i].r_fork = &buba->forks[(i + 1) % buba->n_philo];
	buba->p_a[i].print = &buba->print;
	buba->p_a[i].go_time = 0;
}

int	ft_init1(char **argv, int argc, t_buba *buba)
{
	int	i;

	i = 0;
	buba->n_philo = ft_atoi(argv[1]);
	buba->p_a = (t_philo *)malloc(sizeof(t_philo) * buba->n_philo);
	buba->forks = (pthread_mutex_t *)malloc \
				 (sizeof(pthread_mutex_t) * buba->n_philo);
	if (!buba->p_a || !buba->forks)
	{
		printf("ERROR: malloc is not allocated\n");
		return (1);
	}
	while (i < buba->n_philo)
	{
		pthread_mutex_init(&buba->forks[i], NULL);
		i++;
	}
	pthread_mutex_init(&buba->print, NULL);
	i = 0;
	while (i < buba->n_philo)
	{
		ft_init2(argv, argc, i, buba);
		i++;
	}
	return (0);
}
