/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_supervisor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merdal <merdal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 12:42:00 by merdal            #+#    #+#             */
/*   Updated: 2024/05/27 15:19:39 by merdal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_check_meals(t_philo *philo)
{
	int	i;
	size_t	meal_amount;
	size_t	how_many_ate;

	i = 0;
	how_many_ate = 0;
	meal_amount = philo[0].meal_amount;
	while (i < philo[0].philo_num)
	{
		pthread_mutex_lock(philo[i].meal_lock);
		if (philo[i].meals_eaten == philo->meal_amount)
			how_many_ate++;
		pthread_mutex_unlock(philo[i].meal_lock);
		i++;
	}
	if (how_many_ate >= meal_amount)
	{
		philo->dead_philo = 1;
		return (1);
	}
	return (0);
}

int	ft_check_dead_philo(t_philo *philo)
{
	size_t	time;

	time = ft_get_time() - philo->last_meal;
	pthread_mutex_lock(philo->meal_lock);
	if (time >= philo->time_to_die && philo->is_eating == 0)
	{
		pthread_mutex_unlock(philo->meal_lock);
		pthread_mutex_lock(philo->dead_lock);
		ft_print_status(philo, "died");                         // aktualisieren
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
		{
			break ;
		}
		if (ft_check_meals(philo) == 1)
		{
			break ;
		}
	}
	return (pointer);
}