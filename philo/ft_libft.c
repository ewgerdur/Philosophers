/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libft.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgerdur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 16:01:58 by wgerdur           #+#    #+#             */
/*   Updated: 2021/08/05 16:43:21 by wgerdur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_check_digit(char *argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if (argv[i] >= '0' && argv[i] <= '9')
			return (1);
		i++;
	}
	return (0);
}

int	ft_atoi(const char *str)
{
	long long int	result;
	long long int	j;
	long long int	q;

	result = 0;
	j = 0;
	q = 1;
	while (str[j] == ' ' || str[j] == '\0' || str[j] == '\n'
		|| str[j] == '\t' || str[j] == '\v'
		|| str[j] == '\f' || str[j] == '\r')
		j++;
	if (str[j] == '-' || str[j] == '+')
	{
		if (str[j] == '-')
			q = -1;
		j++;
	}
	while (str[j] >= '0' && str[j] <= '9')
	{
		result = (10 * result) + str[j] - '0';
		j++;
	}
	return (q * result);
}
