/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jin-lee <jin-lee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 20:35:09 by jin-lee           #+#    #+#             */
/*   Updated: 2021/12/15 00:02:40 by jin-lee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>
# include "mini_libft.h"
# include "err_message.h"

# define TRUE 1
# define FALSE 0

typedef struct s_data	t_data;

struct s_data
{
	int				philosophers;
	int				time_to_die;
	int				time_to_eat;
	int 			time_to_sleep;
	int				must_eat_flag;
	int				must_eat;
	struct timeval	g_timestamp;
};

/* utils */
void	pass(void);
int		print_error(char *message);

int		check_args(int argc, char **argv);

#endif