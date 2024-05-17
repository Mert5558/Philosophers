/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_routine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merdal <merdal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 12:57:37 by merdal            #+#    #+#             */
/*   Updated: 2024/05/16 16:37:50 by merdal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_eat(t_philo *philo)
{
	pthread_mutex_lock(philo->r_fork);
	ft_print_status(philo, "takes right fork");
	pthread_mutex_lock(philo->l_fork);
	ft_print_status(philo, "takes left fork");
	philo->eating = 1;
	ft_print_status(philo, "is eating");
	pthread_mutex_lock(philo->meal_lock);
	philo->meals_eaten++;
	pthread_mutex_unlock(philo->meal_lock);
	philo->last_meal = ft_get_time();
	ft_usleep(philo->time_to_eat);
	philo->eating = 0;
	pthread_mutex_unlock(philo->r_fork);
	pthread_mutex_unlock(philo->l_fork);
}

void	ft_sleep(t_philo *philo)
{
	ft_print_status(philo, "is sleeping");
	ft_usleep(philo->time_to_sleep);
}

void	ft_think(t_philo *philo)
{
	ft_print_status(philo, "is thinking");
}

void	*ft_routine(void *pointer)
{
	t_philo	*philo;
	
	philo = (t_philo*) pointer;
	while (1)
	{
		ft_eat(philo);
		ft_sleep(philo);
		ft_think(philo);
	}
	return (pointer);
}
