/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jin-lee <jin-lee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 14:10:13 by jin-lee           #+#    #+#             */
/*   Updated: 2021/12/22 20:22:25 by jin-lee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	set_philo(t_data *data)
{
	if (data->curr_idx == 0)
	{
		data->arr_philo[data->curr_idx].rstick = data->num_philos - 1;
		data->arr_philo[data->curr_idx].lstick = 0;
	}
	else
	{
		data->arr_philo[data->curr_idx].rstick = data->curr_idx - 1;
		data->arr_philo[data->curr_idx].lstick = data->curr_idx;
	}
	gettimeofday(&(data->arr_philo[data->curr_idx].life_timestamp), NULL);
}

static void	*thread_philo(void *param)
{
	t_data		*data;
	t_philo		*philo;

	data = param;
	set_philo(data);
	philo = &(data->arr_philo[data->curr_idx]);
	if (philo->lstick == philo->rstick)
		while (philo->lstick == philo->rstick)
			if (check_status(data, philo))
				return (NULL);
	while (check_status(data, philo) == ALIVE)
	{
		if (eating(data, philo))
			return (NULL);
		if (sleeping(data, philo))
			return (NULL);
		thinking(data, philo);
	}
	return (NULL);
}

static int	create_philo(t_data *data, int idx)
{
	int	ret;

	ret = 0;
	while (idx < data->num_philos && !ret)
	{
		data->curr_idx = idx;
		ret = pthread_create(&(data->arr_philo[idx].thread), \
			NULL, &thread_philo, data);
		idx += 2;
	}
	if (ret)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

/* ************************************************************************** */

int	philosophers(t_data *data)
{
	int	idx;

	gettimeofday(&(data->global_timestamp), NULL);
	if (create_philo(data, ODD))
		return (EXIT_FAILURE);
	if (create_philo(data, EVEN))
		return (EXIT_FAILURE);
	idx = -1;
	while (++idx < data->num_philos)
		pthread_join(data->arr_philo[idx].thread, NULL);
	if (data->program_status)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
