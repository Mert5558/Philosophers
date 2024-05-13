/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merdal <merdal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 12:03:42 by merdal            #+#    #+#             */
/*   Updated: 2024/05/13 14:21:33 by merdal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo			philos;
t_program		program;

int	main(int argc, char **argv)
{
	if (argc != 5 && argc != 6)
	{
		write(1, "Error: Wrong number of arguments\n", 33);
		return (1);
	}
	if (ft_check_args(argc, argv) != 0)
		return (1);
	ft_init(&philos, &program, argv);
	ft_threads(&philos, &program);
}
