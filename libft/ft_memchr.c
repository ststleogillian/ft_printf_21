/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memchr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgillian <jgillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 12:14:30 by jgillian          #+#    #+#             */
/*   Updated: 2020/11/02 09:01:05 by jgillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char *where;

	where = (unsigned char *)s;
	while (n--)
	{
		if (*where == (unsigned char)c)
			return (where);
		where++;
	}
	return (0);
}
