/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgillian <jgillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 14:11:26 by jgillian          #+#    #+#             */
/*   Updated: 2020/11/19 14:46:59 by jgillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char *const s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	k;
	size_t	i;

	if ((substr = (char *)malloc(sizeof(char) * (int)(len + 1))) == NULL)
		return (NULL);
	k = 0;
	i = 0;
	while (*(s + k))
	{
		if (k >= start && i < len)
		{
			*(substr + i) = *(s + k);
			i++;
		}
		k++;
	}
	*(substr + i) = '\0';
	return (substr);
}
