/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_threads.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merdal <merdal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 12:26:25 by merdal            #+#    #+#             */
/*   Updated: 2024/06/12 13:10:15 by merdal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_thread_error(t_philo *philo, t_program *program,
			pthread_mutex_t *forks)
{
	ft_destroy(philo, program, forks);
	write(1, "Error thread\n", 22);
}

void	ft_threads(t_philo *philo, t_program *program, pthread_mutex_t *forks)
{
	pthread_t	supervisor;
	int			i;

	i = 0;
	if (pthread_create(&supervisor, NULL, ft_supervisor, program->philo) != 0)
		ft_thread_error(philo, program, forks);
	while (i < program->philo_num)
	{
		if (pthread_create(&philo[i].thread, NULL, ft_routine, &philo[i]) != 0)
			ft_thread_error(philo, program, forks);
		i++;
	}
	i = 0;
	if (pthread_join(supervisor, NULL) != 0)
		ft_thread_error(philo, program, forks);
	while (i < program->philo_num)
	{
		if (pthread_join(philo[i].thread, NULL) != 0)
			ft_thread_error(philo, program, forks);
		i++;
	}
}
