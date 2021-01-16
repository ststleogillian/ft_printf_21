/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgillian <jgillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 14:27:22 by jgillian          #+#    #+#             */
/*   Updated: 2020/11/03 13:50:36 by jgillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	symbol;

	symbol = c;
	while (*s)
	{
		if (*s == symbol)
			return ((char *)s);
		s++;
	}
	return ((*s == c) ? (char *)s : NULL);
}
