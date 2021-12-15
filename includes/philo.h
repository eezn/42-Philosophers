/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jin-lee <jin-lee@student.42Seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 20:35:09 by jin-lee           #+#    #+#             */
/*   Updated: 2021/12/15 16:33:04 by jin-lee          ###   ########.fr       */
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

# define ACQUIED 1
# define RELEASED 0

typedef struct	s_data			t_data;
typedef struct	s_philo			t_philo;
typedef struct	s_chopstick t_chopstick;

struct	s_chopstick
{
	int				chopstick_id;
	int				status;
	
	pthread_mutex_t	*mutex_lock;
};

struct	s_philo
{
	int				philo_id;
	int				status;

	pthread_t		thread;
	t_chopstick		chopstick;
};

struct	s_data
{
	int				num_philos;
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