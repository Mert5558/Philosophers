/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merdal <merdal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 12:56:26 by merdal            #+#    #+#             */
/*   Updated: 2024/06/11 15:56:51 by merdal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_init_forks(pthread_mutex_t *forks, int philo_num)
{
	int	i;

	i = 0;
	while (i < philo_num)
	{
		pthread_mutex_init(&forks[i], NULL);
		i++;
	}
}

void	ft_init_arg(t_philo *philo, t_program *program, char **argv)
{
	int	i;

	i = 0;
	while (i < program->philo_num)
	{
		philo[i].philo_num = ft_atoi(argv[1]);
		philo[i].time_to_die = ft_atoi(argv[2]);
		philo[i].time_to_eat = ft_atoi(argv[3]);
		philo[i].time_to_sleep = ft_atoi(argv[4]);
		if (argv[5])
			philo[i].meal_amount = ft_atoi(argv[5]);
		else
			philo[i].meal_amount = -1;
		i++;
	}
}

void	ft_init_philo(t_philo *philo, t_program *program,
			pthread_mutex_t *forks, char **argv)
{
	int	i;

	i = 0;
	ft_init_arg(philo, program, argv);
	while (i < program->philo_num)
	{
		philo[i].id = i + 1;
		philo[i].is_eating = 0;
		philo[i].meals_eaten = 0;
		philo[i].dead_philo = 0;
		philo[i].all_ate = 0;
		philo[i].start_time = ft_get_time();
		philo[i].last_meal = ft_get_time();
		philo[i].write_lock = &program->write_lock;
		philo[i].dead_lock = &program->dead_lock;
		philo[i].meal_lock = &program->meal_lock;
		philo[i].l_fork = &forks[i];
		if (i == 0)
			philo[i].r_fork = &forks[program->philo_num - 1];
		else
			philo[i].r_fork = &forks[i - 1];
		i++;
	}
}

void	ft_init_program(t_program *program, t_philo *philo, int philo_num)
{
	program->philo_num = philo_num;
	program->philo = philo;
	pthread_mutex_init(&program->write_lock, NULL);
	pthread_mutex_init(&program->dead_lock, NULL);
	pthread_mutex_init(&program->meal_lock, NULL);
}

void	ft_init(t_philo *philo, t_program *program,
			pthread_mutex_t	*forks, char **argv)
{
	ft_init_program(program, philo, ft_atoi(argv[1]));
	ft_init_philo(philo, program, forks, argv);
	ft_init_forks(forks, program->philo_num);
}
