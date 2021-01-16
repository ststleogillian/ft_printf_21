/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgillian <jgillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 11:53:27 by jgillian          #+#    #+#             */
/*   Updated: 2020/11/09 12:07:23 by jgillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*ptr;
	int		len;
	int		i;

	i = 0;
	if (!f || !s)
		return (NULL);
	len = ft_strlen(s);
	if (!(ptr = (char *)malloc(len + 1)))
		return (NULL);
	while (*(s + i))
	{
		*(ptr + i) = f(i, *(s + i));
		i++;
	}
	*(ptr + i) = '\0';
	return (ptr);
}
