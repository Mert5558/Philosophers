/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_destroy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merdal <merdal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 11:29:22 by merdal            #+#    #+#             */
/*   Updated: 2024/06/12 12:56:52 by merdal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_destroy(t_philo *philo, t_program *program, pthread_mutex_t *forks)
{
	int	i;

	i = 0;
	pthread_mutex_destroy(&program->write_lock);
	pthread_mutex_destroy(&program->dead_lock);
	pthread_mutex_destroy(&program->meal_lock);
	while (i < philo[0].philo_num)
	{
		pthread_mutex_destroy(&forks[i]);
		i++;
	}
	free(philo);
	free(program);
}
