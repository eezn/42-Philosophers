/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jin-lee <jin-lee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 09:20:07 by jin-lee           #+#    #+#             */
/*   Updated: 2021/12/06 09:20:41 by jin-lee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	is_number(char *str)
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
