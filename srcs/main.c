/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jin-lee <jin-lee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 20:14:44 by jin-lee           #+#    #+#             */
/*   Updated: 2021/12/17 02:54:17 by jin-lee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_arr_stick(t_data *data)
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

void	init_arr_philo(t_data *data)
{
	int idx;

	data->arr_philo = (t_philo *)malloc(sizeof(t_philo) * data->num_philos);
		
	idx = -1;
	while (++idx < data->num_philos)
	{
		data->arr_philo[idx].philo_id = idx + 1;
		data->arr_philo[idx].status = 0;
		data->arr_philo[idx].even_odd = -1;
		data->arr_philo[idx].thread = NULL;
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
	init_arr_philo(data);
	init_arr_stick(data);
}

/* ************************************************************************** */

void	*func(void *param)
{
	t_data	*data;

	data = param;
	return (NULL);
}

void	is_even_odd(t_data *data, int idx)
{
	if (idx % 2 == 0)
		data->arr_philo[idx].even_odd = EVEN;
	else
		data->arr_philo[idx].even_odd = ODD;
}

int	create_thread(t_data *data)
{
	int	idx;
	int thr_id;

	idx = -1;
	thr_id = 0;
	while (++idx < data->num_philos && thr_id == 0)
	{
		is_even_odd(data, idx);
		thr_id = pthread_create(&data->arr_philo[idx].thread, NULL, &func, data);
		if (thr_id < 0)
			return (print_error(ERR_));
	}
	return (EXIT_SUCCESS);
}

int	main_process(t_data *data)
{
	int idx;

	if (create_thread(data))
		return (EXIT_FAILURE);

	idx = -1;
	while (++idx < data->num_philos)
		pthread_join(data->arr_philo[idx].thread, NULL);

	return (EXIT_SUCCESS);
}

/* ************************************************************************** */

int	main(int argc, char **argv)
{
	t_data	data;
	
	if (!(argc == 5 || argc == 6))
		return (print_error(ERR_ARGS));

	if (check_args(argc, argv))
		return (EXIT_FAILURE);
	else
	{
		init_data(argc, argv, &data);
		if (main_process(&data))
			pass();
		return (EXIT_SUCCESS);
	}
}
