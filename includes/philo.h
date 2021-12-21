/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jin-lee <jin-lee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 20:35:09 by jin-lee           #+#    #+#             */
/*   Updated: 2021/12/21 17:19:10 by jin-lee          ###   ########.fr       */
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
# include "macro.h"

/* ************************************************************************** */

typedef struct s_data		t_data;
typedef struct s_philo		t_philo;
typedef struct s_chopstick	t_chopstick;

struct	s_chopstick
{
	int				chopstick_id;
	pthread_mutex_t	*mutex_lock;
};

struct	s_philo
{
	int				philo_id;
	int				status;
	int				meals;
	double			starving;
	pthread_t		thread;
	int				rstick;
	int				lstick;
	struct timeval	act_timestamp;
	struct timeval	life_timestamp;
};

struct	s_data
{
	int				program_status;
	int				num_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				must_eat_flag;
	int				must_eat;
	int				curr_idx;
	struct timeval	global_timestamp;
	pthread_mutex_t	*mutex_pause;
	t_philo			*arr_philo;
	t_chopstick		*arr_stick;
};

/* ************************************************************************** */

void	pass(void);
int		print_error(char *message);

int		ft_isdigit(int c);
int		ft_isspace(int c);
int		ft_atoi(const char *str);
size_t	ft_strlen(const char *str);

void	unlock_mutex(t_data *data, t_philo *philo);
void	print_status(t_data *data, int behavior, long time, int philo_id);
int		check_status(t_data *data, t_philo *philo);
double	get_interval(t_data *data, t_philo *philo, int start, int end);

int		eating(t_data *data, t_philo *philo);
int		sleeping(t_data *data, t_philo *philo);
void	thinking(t_data *data, t_philo *philo);

int		check_args(int argc, char **argv);
void	init_data(int argc, char **argv, t_data *data);
int		philosophers(t_data *data);

#endif