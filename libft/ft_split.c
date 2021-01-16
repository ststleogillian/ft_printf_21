/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgillian <jgillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 14:03:52 by jgillian          #+#    #+#             */
/*   Updated: 2020/11/09 11:44:49 by jgillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_count_parts(char *s, char c)
{
	int		count;
	int		k;
	int		in;

	count = 0;
	k = 0;
	in = 0;
	while (*s)
	{
		if (*(s) != c && in == 0)
		{
			in = 1;
			count++;
		}
		else if (*(s) == c)
			in = 0;
		s++;
	}
	return (count);
}

static char	**ft_free(char **s)
{
	int		k;
	char	**ptr;

	if (!(s))
		return (NULL);
	k = 0;
	ptr = s;
	while (*(s + k))
	{
		free(*(s + k));
		k++;
	}
	free(s);
	return (NULL);
}

char		*ft_memcpy_with_malloc(char *to, char *from, int len)
{
	char	*ptr;

	if (!to && !from)
		return (NULL);
	if (!(ptr = (char *)malloc(len + 1)))
		return (NULL);
	to = ptr;
	while (len--)
		*ptr++ = *from++;
	*ptr = '\0';
	return (to);
}

char		**ft_split(char const *s, char c)
{
	char	**ptr;
	int		i;
	int		parts;
	int		k;
	int		length;

	parts = ft_count_parts((char *)s, c);
	i = 0;
	length = 0;
	if ((ptr = (char **)malloc(sizeof(char *) * (parts + 1))) == NULL)
		return (ft_free(ptr));
	*(ptr + parts) = NULL;
	while (parts--)
	{
		while (*(s + length) == c)
			length++;
		k = 0;
		while (*(s + length + k) != c && *(s + length + k) != '\0')
			k++;
		if (!(ptr[i] = ft_memcpy_with_malloc(ptr[i], (char *)(s + length), k)))
			return (ft_free(ptr));
		i++;
		length += k;
	}
	return (ptr);
}
