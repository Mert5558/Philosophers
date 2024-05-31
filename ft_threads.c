/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_threads.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merdal <merdal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 12:26:25 by merdal            #+#    #+#             */
/*   Updated: 2024/05/31 13:02:30 by merdal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_threads(t_philo *philo, t_program *program)
{
	int i;

	i = 0;
	while (i < program->philo_num)
	{
		pthread_create(&philo[i].thread, NULL, ft_routine, &philo[i]);
		//printf("nabaysun loo\n");
		//usleep(100);
		i++;
	}
	i = 0;
	while (i < program->philo_num)
	{
		pthread_join(philo[i].thread, NULL);
		i++;
	}
}
