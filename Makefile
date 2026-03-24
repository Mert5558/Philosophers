# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: merdal <merdal@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/09 12:54:09 by merdal            #+#    #+#              #
#    Updated: 2024/06/11 15:49:09 by merdal           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror -pthread
NAME = philo
SRCS =	src/philo.c \
		src/philo_utils.c \
		src/ft_init.c \
		src/ft_check_args.c \
		src/ft_calloc.c \
		src/ft_supervisor.c \
		src/ft_threads.c \
		src/ft_routine.c \
		src/ft_destroy.c \

OBJS = $(SRCS:.c=.o)
RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
