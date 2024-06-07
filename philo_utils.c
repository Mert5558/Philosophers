/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merdal <merdal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 12:36:37 by merdal            #+#    #+#             */
/*   Updated: 2024/06/03 13:28:38 by merdal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	result;
	int	neg;

	i = 0;
	neg = 1;
	result = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
		||str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = (result * 10) + (str[i] - '0');
		i++;
	}
	return (result * neg);
}

int	ft_usleep(size_t milliseconds)
{
	size_t	start;
	size_t	current;

	start = ft_get_time();
	while (1)
	{
		current = ft_get_time();
		if ((current - start) >= milliseconds)
			break ;
		usleep(500);
	}
	return (0);
}

size_t	ft_get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

void	ft_print_status(t_philo *philo, char *status)
{
	size_t	time;

	pthread_mutex_lock(philo->write_lock);
	time = ft_get_time() - philo->start_time;
	printf("%zu %d %s\n", time, philo->id, status);
	pthread_mutex_unlock(philo->write_lock);
}
