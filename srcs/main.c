/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jin-lee <jin-lee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 20:14:44 by jin-lee           #+#    #+#             */
/*   Updated: 2021/12/21 17:19:16 by jin-lee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
		if (philosophers(&data))
			printf("\n\033[31mP H I L O S O P H E R S\033[0m\n\n");
		else
			printf("\n\033[32mP H I L O S O P H E R S\033[0m\n\n");
		return (EXIT_SUCCESS);
	}
}
