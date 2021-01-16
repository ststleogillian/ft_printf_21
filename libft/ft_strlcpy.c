/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgillian <jgillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 14:28:42 by jgillian          #+#    #+#             */
/*   Updated: 2020/11/02 12:32:55 by jgillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t		n;

	n = 0;
	if (dst == NULL || src == NULL)
		return (0);
	if (dstsize > 0)
	{
		while (n < dstsize - 1 && *(src + n) != '\0')
		{
			*(dst + n) = *(src + n);
			n++;
		}
		*(dst + n) = '\0';
	}
	while (*(src + n))
		n++;
	return (n);
}
