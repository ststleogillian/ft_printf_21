/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgillian <jgillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 11:52:53 by jgillian          #+#    #+#             */
/*   Updated: 2020/11/09 12:15:10 by jgillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*un_str;
	int		un_len;
	int		k;
	int		i;

	un_len = (int)(ft_strlen(s1) + ft_strlen(s2) + 1);
	if ((un_str = (char *)malloc(sizeof(char) * un_len)) == NULL)
		return (NULL);
	k = 0;
	i = 0;
	while (*(s1 + k))
		*(un_str + i++) = *(s1 + k++);
	k = 0;
	while (*(s2 + k))
		*(un_str + i++) = *(s2 + k++);
	*(un_str + i) = '\0';
	return (un_str);
}
