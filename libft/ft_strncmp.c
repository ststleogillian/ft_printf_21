/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgillian <jgillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 12:54:01 by jgillian          #+#    #+#             */
/*   Updated: 2020/11/10 14:30:08 by jgillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			len;
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	len = 0;
	while (*(str1 + len) == *(str2 + len) && *(str1 + len) != '\0')
	{
		if (len == n - 1)
			return (*(str1 + len) - *(str2 + len));
		len++;
	}
	return (n ? *(str1 + len) - *(str2 + len) : 0);
}
