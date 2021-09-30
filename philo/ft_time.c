/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_time.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgerdur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 16:02:46 by wgerdur           #+#    #+#             */
/*   Updated: 2021/08/03 16:02:48 by wgerdur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

uint64_t	g_t(uint64_t go_time)
{
	struct timeval	x;
	uint64_t		time;

	gettimeofday(&x, NULL);
	time = (x.tv_sec * 1000) + (x.tv_usec / 1000) - go_time;
	return (time);
}

void	my_usleep(uint64_t time)
{
	uint64_t	go_time;

	go_time = g_t(0);
	while (g_t(0) - go_time < time)
		usleep(100);
}
