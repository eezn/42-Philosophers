/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jin-lee <jin-lee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 17:01:19 by jin-lee           #+#    #+#             */
/*   Updated: 2021/12/21 17:16:58 by jin-lee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	get_chopstick(t_data *data, t_philo *philo)
{
	t_chopstick	*sticks;

	sticks = data->arr_stick;
	pthread_mutex_lock(sticks[philo->lstick].mutex_lock);
	print_status(data, TAKE, \
		get_interval(data, philo, GLOBAL, CURRENT), philo->philo_id);
	pthread_mutex_lock(sticks[philo->rstick].mutex_lock);
	print_status(data, TAKE, \
		get_interval(data, philo, GLOBAL, CURRENT), philo->philo_id);
}

int	eating(t_data *data, t_philo *philo)
{
	if (data->program_status == DEAD)
		return (1);
	get_chopstick(data, philo);
	gettimeofday(&(philo->act_timestamp), NULL);
	print_status(data, EATING, \
		get_interval(data, philo, GLOBAL, CURRENT), philo->philo_id);
	while (get_interval(data, philo, ACTION, CURRENT) <= data->time_to_eat)
		if (check_status(data, philo))
			return (1);
	if (data->must_eat_flag)
		philo->meals++;
	unlock_mutex(data, philo);
	gettimeofday(&(philo->life_timestamp), NULL);
	return (0);
}

/* ************************************************************************** */

int	sleeping(t_data *data, t_philo *philo)
{
	if (data->program_status == DEAD)
		return (1);
	gettimeofday(&(philo->act_timestamp), NULL);
	print_status(data, SLEEPING, \
		get_interval(data, philo, GLOBAL, CURRENT), philo->philo_id);
	while (get_interval(data, philo, ACTION, CURRENT) <= data->time_to_sleep)
		if (check_status(data, philo))
			return (1);
	return (0);
}

/* ************************************************************************** */

void	thinking(t_data *data, t_philo *philo)
{
	if (data->program_status == DEAD)
		return ;
	print_status(data, THINKING, \
		get_interval(data, philo, GLOBAL, CURRENT), philo->philo_id);
}
