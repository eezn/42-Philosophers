/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jin-lee <jin-lee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 20:35:09 by jin-lee           #+#    #+#             */
/*   Updated: 2021/12/15 10:45:41 by jin-lee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>
# include "mini_libft.h"
# include "err_message.h"

# define TRUE 1
# define FALSE 0

/* ************************************************************************** */

typedef struct	s_philo_list	t_philo_list;

struct	s_philo_list
{
	t_philo			*head;
	t_philo			*tail;
	size_t			count;
};

/* ************************************************************************** */

typedef struct	s_data			t_data;
typedef struct	s_philo			t_philo;
typedef struct	s_chopstick t_chopstick;

struct	s_chopstick
{
	int				curr_chopstick;
	
	pthread_mutex_t	*mutex_lock;
};

struct	s_philo
{
	int				curr_philo;

	pthread_t		thread;
	t_chopstick		chopstick;
	t_philo			*next;
	t_philo			*prev;
};

struct	s_data
{
	int				philosophers;
	int				time_to_die;
	int				time_to_eat;
	int 			time_to_sleep;
	int				must_eat_flag;
	int				must_eat;

	struct timeval	g_timestamp;
	
	t_philo			*arr_philo;
};

/* ************************************************************************** */

/* utils */
void	pass(void);
int		print_error(char *message);

int		check_args(int argc, char **argv);

#endif