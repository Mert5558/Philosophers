/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_supervisor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merdal <merdal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 12:42:00 by merdal            #+#    #+#             */
/*   Updated: 2024/05/21 13:34:40 by merdal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_check_dead_philo(t_philo *philo)
{
	size_t	time;

	time = ft_get_time() - philo->last_meal;
	pthread_mutex_lock(philo->meal_lock);
	if (time >= philo->time_to_die && philo->is_eating == 0)
	{
		pthread_mutex_unlock(philo->meal_lock);
		pthread_mutex_lock(philo->dead_lock);
		ft_print_status(philo, "died");
		philo->dead_philo = 1;
		pthread_mutex_unlock(philo->dead_lock);
		return (1);
	}
	else
	{
		pthread_mutex_unlock(philo->meal_lock);
		return (0);
	}
}

void	*ft_supervisor(void *pointer)
{
	t_philo *philo;
	
	philo = (t_philo *)pointer;
	while (1)
	{
		if (ft_check_dead_philo(philo) == 1)
			break ;
	}
	return (pointer);
}