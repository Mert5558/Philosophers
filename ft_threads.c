/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_threads.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merdal <merdal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 12:26:25 by merdal            #+#    #+#             */
/*   Updated: 2024/06/07 14:18:40 by merdal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_threads(t_philo *philo, t_program *program)
{
	pthread_t	supervisor;
	int i;

	i = 0;
	pthread_create(&supervisor, NULL, ft_supervisor, program->philo);
	while (i < program->philo_num)
	{
		pthread_create(&philo[i].thread, NULL, ft_routine, &philo[i]);
		i++;
	}
	i = 0;
	while (i < program->philo_num)
	{
		pthread_join(philo[i].thread, NULL);
		i++;
	}
	pthread_join(supervisor, NULL);
}
