/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgillian <jgillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 11:50:36 by jgillian          #+#    #+#             */
/*   Updated: 2020/11/02 10:46:08 by jgillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*to;
	unsigned char	*from;

	if (dst > src)
	{
		to = (unsigned char *)dst + len - 1;
		from = (unsigned char *)src + len - 1;
		while (len--)
			*to-- = *from--;
	}
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
