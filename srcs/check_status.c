/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_status.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jin-lee <jin-lee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 17:25:27 by jin-lee           #+#    #+#             */
/*   Updated: 2021/12/21 16:55:36 by jin-lee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	unlock_mutex(t_data *data, t_philo *philo)
{
	pthread_mutex_unlock(data->arr_stick[philo->lstick].mutex_lock);
	pthread_mutex_unlock(data->arr_stick[philo->rstick].mutex_lock);
}

static int	update_status(t_data *data)
{
	pthread_mutex_lock(data->mutex_pause);
	if (data->program_status == ALIVE)
	{
		data->program_status = DEAD;
		pthread_mutex_unlock(data->mutex_pause);
		return (1);
	}
	else
	{
		pthread_mutex_unlock(data->mutex_pause);
		return (0);
	}
}

int	check_status(t_data *data, t_philo *philo)
{
	philo->starving = get_interval(data, philo, LIFE, CURRENT);
	if (philo->starving >= data->time_to_die)
	{
		if (update_status(data))
		{
			print_status(data, DIED, \
				get_interval(data, philo, GLOBAL, CURRENT), philo->philo_id);
			unlock_mutex(data, philo);
			return (DEAD);
		}
	}
	if (data->must_eat_flag)
	{
		if (philo->meals == data->must_eat)
		{
			unlock_mutex(data, philo);
			return (FULL);
		}
	}
	return (ALIVE);
}
