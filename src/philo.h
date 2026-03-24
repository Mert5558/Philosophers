/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merdal <merdal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 12:03:59 by merdal            #+#    #+#             */
/*   Updated: 2024/06/12 12:12:41 by merdal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>

typedef struct s_philo
{
	pthread_t		thread;
	int				id;
	int				is_eating;
	int				dead_philo;
	int				all_ate;
	int				philo_num;
	size_t			meals_eaten;
	size_t			last_meal;
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	size_t			meal_amount;
	size_t			start_time;
	pthread_mutex_t	*write_lock;
	pthread_mutex_t	*dead_lock;
	pthread_mutex_t	*meal_lock;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*l_fork;
}					t_philo;

typedef struct s_program
{
	int				philo_num;
	pthread_mutex_t	write_lock;
	pthread_mutex_t	dead_lock;
	pthread_mutex_t	meal_lock;
	t_philo			*philo;
}					t_program;

int		ft_check_args(int argc, char **argv);
void	ft_init(t_philo *philo, t_program *program,
			pthread_mutex_t	*forks, char **argv);
void	*ft_supervisor(void *pointer);
void	*ft_routine(void *pointer);
void	ft_threads(t_philo *philo, t_program *program, pthread_mutex_t *forks);
int		ft_check_dead_philo(t_philo *philo);
int		ft_check_meals(t_philo *philo);
int		ft_check_dead(t_philo *philo);
void	ft_destroy(t_philo *philo, t_program *program, pthread_mutex_t *forks);

// utils
int		ft_atoi(const char *str);
size_t	ft_get_time(void);
int		ft_usleep(size_t milliseconds);
void	ft_print_status(t_philo *philo, char *status);
void	*ft_calloc(size_t n_items, size_t size);
void	ft_one_philo(t_philo *philo);

#endif