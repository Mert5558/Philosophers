/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merdal <merdal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 12:03:42 by merdal            #+#    #+#             */
/*   Updated: 2024/05/20 16:32:02 by merdal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


int	main(int argc, char **argv)
{
	t_philo			*philo;
	t_program		*program;
	
	philo = ft_calloc(1, sizeof(t_philo));     // verbessern
	program = ft_calloc(1, sizeof(t_program)); // verbessern
	if (argc != 5 && argc != 6)
	{
		write(1, "Error: Wrong number of arguments\n", 33);
		return (1);
	}
	if (ft_check_args(argc, argv) != 0)
		return (1);
	ft_init(philo, program, argv);
	return (0);
}
