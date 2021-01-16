/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgillian <jgillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 15:01:32 by jgillian          #+#    #+#             */
/*   Updated: 2020/11/10 14:17:10 by jgillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t		i;
	size_t		k;
	size_t		n;

	n = 0;
	if (*needle == '\0')
		return ((char *)haystack);
	while (*(haystack + n))
	{
		if (*(haystack + n) == *needle)
		{
			k = 0;
			i = 0;
			while (*(needle + k) == *(haystack + n + i) && (n + i) < len &&
			*(needle + k) != '\0')
			{
				k++;
				i++;
			}
			if (*(needle + k) == '\0')
				return ((char *)(haystack + n));
		}
		n++;
	}
	return (NULL);
}
