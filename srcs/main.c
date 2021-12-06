/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jin-lee <jin-lee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 20:14:44 by jin-lee           #+#    #+#             */
/*   Updated: 2021/12/06 09:29:44 by jin-lee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/**
 * @brief 
 * 
 * @param argc 
 * @param argv
 * argv[0]
 * argv[1]: number_of_philosophers (do not over 200)
 * argv[2]: time_to_die (do not under 60ms)
 * argv[3]: time_to_eat (do not under 60ms)
 * argv[4]: time_to_sleep (do not under 60ms)
 * argv[5]: (optional) number_of_times_each_philosopher_must_eat
 * @return int 
 */

int	main(int argc, char **argv)
{
	if (argc == 5 || argc == 6)
	{
		if (check_args(argc, argv))
			return (EXIT_FAILURE);
		if (argc == 5)
			pass();
		if (argc == 6)
			pass();
	}
	else
		print_error(ERR_ARGS);
	return (EXIT_SUCCESS);
}
