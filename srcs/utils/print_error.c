/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jin-lee <jin-lee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 09:18:35 by jin-lee           #+#    #+#             */
/*   Updated: 2021/12/20 13:34:33 by jin-lee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	print_error(char *message)
{
	printf("\033[33mError: \033[0m");
	printf("%s\n", message);
	return (EXIT_FAILURE);
}
