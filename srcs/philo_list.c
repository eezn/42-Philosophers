/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jin-lee <jin-lee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 08:39:39 by jin-lee           #+#    #+#             */
/*   Updated: 2021/12/15 10:39:43 by jin-lee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	add_philo(t_philo_list *list, t_philo *philo)
{
	t_philo	*prev_philo;
	t_philo *next_philo;

	if (list->count == 0)
	{
		philo->next = philo;
		philo->prev = philo;
		list->head = philo;
		list->tail = philo;
		list->count += 1;
	}
	else
	{
		prev_philo = list->tail;
		next_philo = list->head;
		philo->next = next_philo;
		philo->prev = prev_philo;
		prev_philo->next = philo;
		next_philo->prev = philo;
		list->tail = philo;
		list->count += 1;
	}
}

t_philo	*new_philo(void)
{
	t_philo	*philo;

	philo = (t_philo *)malloc(sizeof(t_philo));
	if (!philo)
		return (NULL);
	// philo->thread
	// philo->chopstick
	philo->next = NULL;
	philo->prev = NULL;
	return (philo);
}

t_philo_list	*init_philo_list(void)
{
	t_philo_list	*list;

	list = (t_philo_list *)malloc(sizeof(t_philo_list));
	if (!list)
		return (NULL);
	list->count = 0;
	list->head = NULL;
	list->tail = NULL;
	return (list);
}