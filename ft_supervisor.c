/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_supervisor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merdal <merdal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 12:31:07 by merdal            #+#    #+#             */
/*   Updated: 2024/05/14 15:36:24 by merdal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_check_if_dead(t_philo *philo)
{
	
}

void	ft_supervisor(void *pointer)
{
	t_philo	*philo;

	philo = (t_philo*) pointer;
	while (1)
	{
		if (ft_check_if_dead(philo) == 1)
			break ;
	}
	return (pointer);
}