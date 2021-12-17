/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jin-lee <jin-lee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 11:16:02 by jin-lee           #+#    #+#             */
/*   Updated: 2021/12/17 11:17:16 by jin-lee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	init_arr_stick(t_data *data)
{
	int idx;

	data->arr_stick = (t_chopstick *)malloc(sizeof(t_chopstick) * data->num_philos);
	
	idx = -1;
	while (++idx < data->num_philos)
	{
		data->arr_stick[idx].mutex_lock = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
		pthread_mutex_init(data->arr_stick[idx].mutex_lock, NULL);
		data->arr_stick[idx].chopstick_id = idx + 1;
		data->arr_stick[idx].status = RELEASED;
	}
}

static void	init_arr_philo(t_data *data)
{
	int idx;

	data->arr_philo = (t_philo *)malloc(sizeof(t_philo) * data->num_philos);
		
	idx = -1;
	while (++idx < data->num_philos)
	{
		data->arr_philo[idx].philo_id = idx + 1;
		data->arr_philo[idx].status = 0;
		data->arr_philo[idx].thread = NULL;
		if (idx % 2 == 0)
			data->arr_philo[idx].even_odd = ODD;
		else
			data->arr_philo[idx].even_odd = EVEN;
	}
}

void	init_data(int argc, char **argv, t_data *data)
{
	data->num_philos = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	data->must_eat_flag = FALSE;
	if (argc == 6)
	{
		data->must_eat_flag = TRUE;
		data->must_eat = ft_atoi(argv[5]);
	}
	gettimeofday(&(data->global_timestamp), NULL);
	init_arr_philo(data);
	init_arr_stick(data);
}
