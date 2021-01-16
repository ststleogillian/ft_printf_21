/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgillian <jgillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 13:07:18 by jgillian          #+#    #+#             */
/*   Updated: 2020/11/02 14:24:57 by jgillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t destsize)
{
	size_t		n;
	size_t		d_len;
	char		*d;
	const char	*s;

	n = destsize;
	s = src;
	d = dst;
	while (n-- != 0 && *d)
		d++;
	d_len = d - dst;
	n = destsize - d_len;
	if (n == 0)
		return (destsize + ft_strlen(src));
	while (--n != 0 && *s)
		*d++ = *s++;
	*d = '\0';
	return (d_len + ft_strlen(src));
}
