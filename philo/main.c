/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgerdur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 16:02:57 by wgerdur           #+#    #+#             */
/*   Updated: 2021/08/10 13:21:46 by wgerdur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_philos(t_buba *buba)
{
	int	i;

	i = -1;
	while (++i < buba->n_philo)
		if (buba->p_a[i].f_6 != -1)
			return (0);
	return (1);
}

static void	ft_end(t_buba *buba)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < buba->n_philo)
	{
		pthread_detach(buba->p_a[i].thread);
		i++;
	}
	while (j < buba->n_philo)
	{
		pthread_mutex_destroy(&buba->forks[j]);
		j++;
	}
	pthread_mutex_destroy(&buba->print);
}

static int	ft_check(int argc, char **argv)
{
	if (!(argc == 5 || argc == 6))
		return (0);
	if (ft_atoi(argv[1]) <= 0 || ft_atoi(argv[2]) <= 0 \
	|| ft_atoi(argv[3]) <= 0 || ft_atoi(argv[4]) <= 0)
		return (0);
	if (!ft_check_digit(argv[1]) || !ft_check_digit(argv[2]) \
	|| !ft_check_digit(argv[3]) || !ft_check_digit(argv[4]))
		return (0);
	if (argc == 6)
	{
		if (!ft_check_digit(argv[5]) || ft_atoi(argv[5]) <= 0)
			return (0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_buba	buba;

	if (ft_check(argc, argv))
	{
		if (ft_init1(argv, argc, &buba))
			return (0);
		ft_start(&buba);
	}
	else
	{
		printf("ERROR: incorrect input\n");
		return (1);
	}
	ft_end(&buba);
	free(buba.forks);
	free(buba.p_a);
	return (0);
}
