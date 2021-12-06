/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jin-lee <jin-lee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 20:14:44 by jin-lee           #+#    #+#             */
/*   Updated: 2021/12/06 09:12:36 by jin-lee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

# define NULL_INPUT "\033[33m(NULL_INPUT)\033[0m"
# define EMPTY_STR "\033[33m(EMPTY_STR)\033[0m"
# define NOT_NUM "\033[33m(NOT_NUM)\033[0m"
# define PHILO_RANGE "\033[33m(PHILO_RANGE)\033[0m"
# define TIME_RANGE "\033[33m(TIME_RANGE)\033[0m"
# define ERR_ARGS "\033[33m(ERR_ARGS)\033[0m"

int	print_error(char *message)
{
	printf("\033[33mError: \033[0m");
	printf("%s\n", message);
	return (EXIT_FAILURE);
}

/* ************************************************************************** */

int	is_number(char *str)
{
	if (*str == '-')
	{
		while (*(++str))
			if (!ft_isdigit(*str))
				return (1);
	}
	else
	{
		while (*str)
			if (!ft_isdigit(*str++))
				return (1);
	}
	return (0);
}

int	check_args(int argc, char **argv)
{
	int	i;

	i = 0;
	while (++i < argc)
	{
		if (argv[i] == NULL)
			return (print_error(NULL_INPUT));
		if (argv[i][0] == 0)
			return (print_error(EMPTY_STR));
		if (is_number(argv[i]))
			return (print_error(NOT_NUM));
	}
	i = ft_atoi(argv[1]);
	if (!(0 < i && i < 201))
		return (print_error(PHILO_RANGE));
	if (ft_atoi(argv[2]) < 60
		|| ft_atoi(argv[3]) < 60
		|| ft_atoi(argv[4]) < 60)
		return (print_error(TIME_RANGE));
	return (EXIT_SUCCESS);
}

/* ************************************************************************** */

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
