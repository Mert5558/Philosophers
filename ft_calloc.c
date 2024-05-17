/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merdal <merdal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 12:40:02 by merdal            #+#    #+#             */
/*   Updated: 2024/05/14 12:40:05 by merdal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_memset(void *mem, int value, size_t n)
{
	unsigned char	byte_value;
	unsigned char	*dest;
	size_t			i;

	byte_value = (unsigned char)value;
	dest = (unsigned char *)mem;
	i = 0;
	while (i < n)
	{
		dest[i] = byte_value;
		i++;
	}
	return (mem);
}

void	*ft_calloc(size_t n_items, size_t size)
{
	void	*ptr;

	ptr = malloc(n_items * size);
	if (!ptr)
		return (NULL);
	ft_memset(ptr, 0, n_items * size);
	return (ptr);
}
