/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgillian <jgillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 13:45:29 by jgillian          #+#    #+#             */
/*   Updated: 2020/11/05 15:33:06 by jgillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*ptr;
	char	*ptr_begin;

	if ((ptr = (char *)malloc(sizeof(char) * (int)(ft_strlen(s1) + 1))) == NULL)
		return (NULL);
	ptr_begin = ptr;
	while (*s1)
		*ptr++ = *s1++;
	*ptr = '\0';
	return (ptr_begin);
}
