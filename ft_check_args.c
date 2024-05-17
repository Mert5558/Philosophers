/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merdal <merdal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 12:35:45 by merdal            #+#    #+#             */
/*   Updated: 2024/05/09 12:52:08 by merdal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_check_if_num(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (1);
		i++;
	}
	return (0);
}

int	ft_check_args(int argc, char **argv)
{
	if (ft_atoi(argv[1]) < 0 || ft_check_if_num(argv[1]) == 1)
	{
		write(2, "Philosophers number is not valid\n", 33);
		return (1);
	}
	if (ft_atoi(argv[2]) <= 0 || ft_check_if_num(argv[2]) == 1)
	{
		write(2, "Time to die is not valid\n", 26);
		return (1);
	}
	if (ft_atoi(argv[3]) <= 0 || ft_check_if_num(argv[3]) == 1)
	{
		write(2, "Time to eat is not valid\n", 26);
		return (1);
	}
	if (ft_atoi(argv[4]) <= 0 || ft_check_if_num(argv[4]) == 1)
	{
		write(2, "Time to sleep is not valid\n", 28);
		return (1);
	}
	if (argc == 6 && (ft_atoi(argv[5]) < 0 || ft_check_if_num(argv[5]) == 1))
	{
		return (write(2, "Number of times to eat is not valid\n", 36), 1);
	}
	return (0);
}
