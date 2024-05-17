/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merdal <merdal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 12:56:26 by merdal            #+#    #+#             */
/*   Updated: 2024/05/17 12:55:39 by merdal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_init_philos(t_philo *philo, t_program *program, char **argv, pthread_mutex_t *fork)
{
	int	i;

	i = 0;
	while (i < ft_atoi(argv[1]))
	{
		philo[i].id = i + 1;
		philo[i].eating = 0;
		philo[i].meals_eaten = 0;
		philo[i].time_to_die = ft_atoi(argv[2]);
		philo[i].time_to_eat = ft_atoi(argv[3]);
		philo[i].time_to_sleep = ft_atoi(argv[4]);
		philo[i].start_time = ft_get_time();
		philo[i].last_meal = ft_get_time();
		philo[i].write_lock = &program->write_lock;
		philo[i].dead_lock = &program->dead_lock;
		philo[i].meal_lock = &program->meal_lock;
		philo[i].is_dead = &program->dead_flag;
		philo[i].r_fork = &fork[i];
		if (i == 0)
			philo[i].l_fork = &fork[ft_atoi(argv[1]) - 1];
		else
			philo[i].l_fork = &fork[i - 1];
		i++;
	}
}

void	ft_init_forks(pthread_mutex_t *fork, char **argv)
{
	int	i;

	i = 0;
	while (i < ft_atoi(argv[1]))
	{
		pthread_mutex_init(&fork[i], NULL);
		i++;
	}
}

void	ft_init(t_philo *philo, t_program *program, char **argv)
{
	pthread_mutex_t	*fork;
	
	fork = malloc(sizeof(pthread_mutex_t) * ft_atoi(argv[1]));
	if (!fork)
		exit(1);
	program->dead_flag = 0;
	program->philo = philo;
	program->philo = philo;
	philo->num_of_philos = ft_atoi(argv[1]);
	pthread_mutex_init(&program->write_lock, NULL);
	pthread_mutex_init(&program->dead_lock, NULL);
	pthread_mutex_init(&program->meal_lock, NULL);
	ft_init_forks(fork, argv);
	//philo->start_time = ft_get_time();
	ft_init_philos(philo, program, argv, fork);
}
