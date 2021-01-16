/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgillian <jgillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 14:36:49 by jgillian          #+#    #+#             */
/*   Updated: 2020/11/02 14:45:44 by jgillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*p;
	char	symbol;

	p = 0;
	symbol = c;
	while (*s)
	{
		if (*s == symbol)
			if (s > p)
				p = (char *)s;
		s++;
	}
	if (*s == c)
		p = (char *)s;
	return (p > 0) ? p : NULL;
}
