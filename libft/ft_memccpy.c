/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memccpy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgillian <jgillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 10:57:08 by jgillian          #+#    #+#             */
/*   Updated: 2020/11/02 09:01:03 by jgillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*to;
	unsigned char	*from;
	unsigned char	s;

	to = (unsigned char *)dst;
	from = (unsigned char *)src;
	s = (unsigned char)c;
	while (n--)
	{
		*to = *from;
		if (*from == s)
			return (++to);
		to++;
		from++;
	}
	return (0);
}
