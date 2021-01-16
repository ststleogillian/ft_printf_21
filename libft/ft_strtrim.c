/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgillian <jgillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 12:35:03 by jgillian          #+#    #+#             */
/*   Updated: 2020/11/10 14:35:25 by jgillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_check(char c, char *set)
{
	int		flag;

	flag = 0;
	while (*set && !flag)
	{
		if (*set == c)
			flag = 1;
		set++;
	}
	return (flag);
}

static int	ft_c_b(char *s1, char *s2, int i, int from)
{
	int		count;

	count = 0;
	while (i >= from)
	{
		if (!ft_check(*(s1 + i), s2))
			break ;
		else
			count++;
		i--;
	}
	return (count);
}

static int	ft_c_f(char *s1, char *s2)
{
	int		count;

	count = 0;
	while (*s1)
	{
		if (!ft_check(*s1, (char *)s2))
			break ;
		else
			count++;
		s1++;
	}
	return (count);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	char	*rem_str;
	int		len;
	int		from;
	int		i;

	i = 0;
	if (!s1 || !set)
		return (NULL);
	len = (int)ft_strlen(s1);
	from = ft_c_f((char *)s1, (char *)set);
	len = len - from - ft_c_b((char *)s1, (char *)set, len - 1, from);
	if ((rem_str = (char *)malloc(sizeof(char) * (len + 1))) == NULL)
		return (NULL);
	while (len--)
	{
		*(rem_str + i) = *(s1 + from);
		from++;
		i++;
	}
	*(rem_str + i) = '\0';
	return (rem_str);
}
