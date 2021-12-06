/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_libft.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jin-lee <jin-lee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 20:35:15 by jin-lee           #+#    #+#             */
/*   Updated: 2021/12/06 06:00:17 by jin-lee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_LIBFT_H
# define MINI_LIBFT_H

# include "unistd.h"
# include "stdlib.h"

int		ft_atoi(const char *str);

int		ft_isdigit(int c);
int		ft_isspace(int c);

size_t	ft_strlen(const char *str);

#endif