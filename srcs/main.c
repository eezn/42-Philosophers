/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jin-lee <jin-lee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 20:14:44 by jin-lee           #+#    #+#             */
/*   Updated: 2021/12/15 00:01:29 by jin-lee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_data(int argc, char **argv, t_data *data)
{
	data->philosophers = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	data->must_eat_flag = FALSE;
	if (argc == 6)
	{
		data->must_eat_flag = TRUE;
		data->must_eat = ft_atoi(argv[5]);
	}
	gettimeofday(&data->g_timestamp, NULL);
}

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
