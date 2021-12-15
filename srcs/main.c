/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jin-lee <jin-lee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 20:14:44 by jin-lee           #+#    #+#             */
/*   Updated: 2021/12/15 14:48:35 by jin-lee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_chopstick(t_chopstick *chopstick, int idx)
{
	chopstick->chopstick_id = idx;
	chopstick->status = RELEASED;
	chopstick->mutex_lock = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init(chopstick->mutex_lock, NULL);
}

void	init_arr_philo(t_data *data)
{
	int idx;

	idx = -1;
	while (++idx < data->num_philos)
	{
		data->arr_philo[idx].philo_id = idx;
		data->arr_philo[idx].status = 0;
		data->arr_philo[idx].thread = NULL;
		init_chopstick(&(data->arr_philo[idx].chopstick), idx);
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
	gettimeofday(&(data->g_timestamp), NULL);

	data->arr_philo = (t_philo *)malloc(sizeof(t_philo) * data->num_philos);
	init_arr_philo(data);
}

/* ************************************************************************** */



/* ************************************************************************** */

int	main(int argc, char **argv)
{
	t_data	data;
	
	if (!(argc == 5 || argc == 6))
		print_error(ERR_ARGS);

	if (check_args(argc, argv))
		return (EXIT_FAILURE);
	else
	{
		init_data(argc, argv, &data);
		return (EXIT_SUCCESS);
	}
}
