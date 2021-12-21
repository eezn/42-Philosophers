/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_interval.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jin-lee <jin-lee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 15:07:37 by jin-lee           #+#    #+#             */
/*   Updated: 2021/12/20 22:59:42 by jin-lee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static double	get_time(t_data *data, t_philo *philo, int time)
{
	struct timeval	timestamp;

	timestamp.tv_sec = 0;
	timestamp.tv_usec = 0;
	if (time == GLOBAL)
		timestamp = data->global_timestamp;
	if (time == LIFE)
		timestamp = philo->life_timestamp;
	if (time == ACTION)
		timestamp = philo->act_timestamp;
	if (time == CURRENT)
		gettimeofday(&timestamp, NULL);
	return (timestamp.tv_sec * 1000 + timestamp.tv_usec * 0.001);
}

double	get_interval(t_data *data, t_philo *philo, int start, int end)
{
	return (get_time(data, philo, end) - get_time(data, philo, start));
}
