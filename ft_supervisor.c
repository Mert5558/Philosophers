/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_supervisor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merdal <merdal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 12:42:00 by merdal            #+#    #+#             */
/*   Updated: 2024/06/07 13:00:28 by merdal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_check_meals(t_philo *philo)
{
	int	i;
	int		how_many_ate;
	size_t	meal_amount;

	i = 0;
	how_many_ate = 0;
	meal_amount = philo[0].meal_amount;
	while (i < philo[0].philo_num)
	{
		pthread_mutex_lock(philo->meal_lock);
		if (philo[i].meals_eaten >= meal_amount)
			how_many_ate++;
		pthread_mutex_unlock(philo->meal_lock);
		i++;
	}
	if (how_many_ate == philo[0].philo_num)
	{
		i = 0;
		while (i < philo[0].philo_num)
		{
			philo[i].dead_philo = 1;
			i++;
		}
    	printf("yeeeeeeeedddddiiiiiiimmmmmmmm\n");
    	return (1);
	}
	return (0);
}

int	ft_check_dead_philo(t_philo *philo)
{
	size_t	time;
	int i;

	i = 0;
	time = ft_get_time() - philo->last_meal;
	pthread_mutex_lock(philo->meal_lock);
	if (time >= philo->time_to_die && philo->is_eating == 0)  // nicht ende eat sondern anfang eat rechnen
	{
		pthread_mutex_unlock(philo->meal_lock);
		pthread_mutex_lock(philo->dead_lock);
		ft_print_status(philo, "died");                         // aktualisieren
		while (i < philo->philo_num)
		{
			philo[i].dead_philo = 1;
			i++;
		}
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