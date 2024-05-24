/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_threads.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merdal <merdal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 12:26:25 by merdal            #+#    #+#             */
/*   Updated: 2024/05/24 12:01:46 by merdal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_threads(t_philo *philo, t_program *program)
{
	pthread_t	supervisor;
	int sup;
	int i;

	sup = pthread_create(&supervisor, NULL, ft_supervisor, (void *)philo);
	if (sup == 1)
	{
		printf("Error: supervisor not created\n");
		return ;
	}
	//printf("supervisor created\n");
	i = 0;
	while (i < 4)
	{
		pthread_create(&philo[i].thread, NULL, ft_routine, &philo[i]);
		//printf("nabaysun loo\n");
		usleep(100);
		i++;
	}
	//printf("philo created\n");
	pthread_join(supervisor, NULL);
	i = 0;
	while (i < program->philo_num)
	{
		pthread_join(philo[i].thread, NULL);
		i++;
	}
}
