/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macro.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jin-lee <jin-lee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 09:00:59 by jin-lee           #+#    #+#             */
/*   Updated: 2021/12/20 23:57:43 by jin-lee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MACRO_H
# define MACRO_H

/* ************************************************************************** */
# define DELAY 200
/* ************************************************************************** */

# define TRUE 1
# define FALSE 0

# define ODD 0
# define EVEN 1

# define GLOBAL 0
# define LIFE 1
# define ACTION 2
# define CURRENT 3

# define ALIVE 0
# define DEAD 1
# define FULL 2

# define TAKE 0
# define EATING 1
# define SLEEPING 2
# define THINKING 3
# define DIED 4

/* ************************************************************************** */

# define ERR_ "\033[33m(MESSAGE)\033[0m"

// # define ERR_ARGS "\033[33m(ERR_ARGS)\033[0m"
// # define NULL_INPUT "\033[33m(NULL_INPUT)\033[0m"
// # define EMPTY_STR "\033[33m(EMPTY_STR)\033[0m"
// # define NOT_NUM "\033[33m(NOT_NUM)\033[0m"
// # define PHILO_RANGE "\033[33m(PHILO_RANGE)\033[0m"
// # define TIME_RANGE "\033[33m(TIME_RANGE)\033[0m"

# define ERR_ARGS "\033[33mAt least 4 arguments are required.\033[0m"
# define NULL_INPUT "\033[33mSome arguments have null values.\033[0m"
# define EMPTY_STR "\033[33mSome arguments have empty string.\033[0m"
# define NOT_NUM "\033[33mSome arguments are not number.\033[0m"
# define PHILO_RANGE "\033[33mDo not test with more than 200 philosophers.\033[0m"
# define TIME_RANGE "\033[33mDo not test with actions under 60ms\033[0m"

#endif