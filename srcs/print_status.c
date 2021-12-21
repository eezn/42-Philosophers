/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_status.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jin-lee <jin-lee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 18:19:53 by jin-lee           #+#    #+#             */
/*   Updated: 2021/12/22 05:31:09 by jin-lee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_status(t_data *data, int behavior, long time, int philo_id)
{
	pthread_mutex_lock(data->mutex_pause);
	if (behavior == DIED)
		printf("\033[31m%ld %d died\033[0m\n", time, philo_id);
	if (data->program_status == DEAD)
	{
		pthread_mutex_unlock(data->mutex_pause);
		return ;
	}
	if (behavior == TAKE)
		printf("\033[33m%ld %d has taken a fork\033[0m\n", time, philo_id);
	if (behavior == EATING)
		printf("\033[32m%ld %d is eating\033[0m\n", time, philo_id);
	if (behavior == SLEEPING)
		printf("\033[35m%ld %d is sleeping\033[0m\n", time, philo_id);
	if (behavior == THINKING)
		printf("\033[36m%ld %d is thinking\033[0m\n", time, philo_id);
	pthread_mutex_unlock(data->mutex_pause);
}
