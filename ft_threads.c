/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_threads.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merdal <merdal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 12:26:25 by merdal            #+#    #+#             */
/*   Updated: 2024/05/17 16:36:46 by merdal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_threads(t_philo *philos, char **argv)
{
	int i;

	i = 0;
	while (i < ft_atoi(argv[1]))
	{
		//printf("creating thread %d\n", i);
		pthread_create(&philos[i].thread, NULL, ft_routine, &philos[i]);
		i++;
	}
}
