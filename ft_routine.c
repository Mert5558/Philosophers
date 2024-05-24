/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_routine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merdal <merdal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 12:57:37 by merdal            #+#    #+#             */
/*   Updated: 2024/05/24 15:44:50 by merdal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_think(t_philo *philo)
{
	ft_print_status(philo, "is thinking");
}

void	ft_sleep(t_philo *philo)
{
	ft_print_status(philo, "is sleeping");
	ft_usleep(philo->time_to_sleep);
}

void	ft_eat(t_philo *philo)
{
	pthread_mutex_lock(philo->r_fork);
	ft_print_status(philo, "has taken right fork");
	pthread_mutex_lock(philo->l_fork);
	ft_print_status(philo, "has taken left fork");      // eigene funktion
	philo->is_eating = 1;
	ft_print_status(philo, "is eating");
	pthread_mutex_lock(philo->meal_lock);
	philo->last_meal = ft_get_time();
	philo->meals_eaten++;
	pthread_mutex_unlock(philo->meal_lock);
	ft_usleep(philo->time_to_eat);                   // nach sleep philo[3] stuck; data race time_to_eat, time_to_eat ist nicht bei jedem philo gleich
	philo->is_eating = 0;
	pthread_mutex_unlock(philo->l_fork);
	ft_print_status(philo, "has put left fork");
	pthread_mutex_unlock(philo->r_fork);
	ft_print_status(philo, "has put right fork");
}

int	ft_check_dead(t_philo *philo)
{
	pthread_mutex_lock(philo->dead_lock);
	if (philo->dead_philo == 1)
	{
		pthread_mutex_unlock(philo->dead_lock);
		return (1);
	}
	pthread_mutex_unlock(philo->dead_lock);
	return (0);
}

void	*ft_routine(void *pointer)
{
	t_philo	*philo;

	philo = (t_philo *)pointer;
	if (philo->id % 2 == 0)
		ft_usleep(1);
	while (ft_check_dead(philo) != 1)
	{
		ft_eat(philo);        // if () für 1 philo
		ft_sleep(philo);
		ft_think(philo);
	}
	return (pointer);
}