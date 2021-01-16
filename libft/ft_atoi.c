/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgillian <jgillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 13:04:46 by jgillian          #+#    #+#             */
/*   Updated: 2020/11/02 14:53:56 by jgillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int		sign;
	int		number;
	int		r;

	r = 0;
	sign = 1;
	number = 0;
	while (*str == '\n' || *str == '\b' || *str == '\t' ||
	*str == '\f' || *str == '\v' || *str == '\r' || *str == ' ')
		str++;
	sign = (*str == '-') ? (-1) : 1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		number = number * 10 + (*str++ - '0');
		if (++r > 19)
			return ((sign == 1) ? -1 : 0);
	}
	return (number * sign);
}
