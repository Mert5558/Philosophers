/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merdal <merdal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 12:03:42 by merdal            #+#    #+#             */
/*   Updated: 2024/05/31 14:17:40 by merdal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//i started this project before finishing the 3rd circle. But i just realized now i could use my own git hub and later remote it to the git repo of the Project, so that i have all git commits also on the projects repo

int	main(int argc, char **argv)
{
	t_philo			*philo;
	t_program		*program;
	pthread_mutex_t	forks[200];
	
	philo = ft_calloc(ft_atoi(argv[1]), sizeof(t_philo));
	program = ft_calloc(1, sizeof(t_program));
	if (argc != 5 && argc != 6)
	{
		write(1, "Error: Wrong number of arguments\n", 33);
		return (1);
	}
	if (ft_check_args(argc, argv) != 0)
		return (1);
	ft_init(philo, program, forks, argv);
	ft_threads(philo, program);
	return (0);
}
