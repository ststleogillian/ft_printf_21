/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgillian <jgillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 12:58:29 by jgillian          #+#    #+#             */
/*   Updated: 2020/11/10 14:34:36 by jgillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	ft_reverse(char *s)
{
	int		k;
	int		i;
	char	c;

	k = ft_strlen(s) - 1;
	i = 0;
	while (i < k)
	{
		c = *(s + i);
		*(s + i) = *(s + k);
		*(s + k) = c;
		k--;
		i++;
	}
}

static int		ft_count_mmry(int n, int *sign)
{
	int		len;

	len = 0;
	*sign = (n < 0) ? 1 : 0;
	if (*sign)
		n *= -1;
	while (n)
	{
		len++;
		n /= 10;
	}
	return (len + *sign);
}

char			*ft_itoa(int n)
{
	char	*s;
	int		len;
	int		sign;
	int		k;

	len = ft_count_mmry(n, &sign);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (!len)
		return (ft_strdup("0"));
	if (!(s = (char *)malloc(len + 1)))
		return (NULL);
	k = 0;
	n *= (sign = n) < 0 ? -1 : 1;
	while (n > 0)
	{
		*(s + k++) = '0' + n % 10;
		n /= 10;
	}
	if (sign < 0)
		s[k++] = '-';
	*(s + len) = '\0';
	ft_reverse(s);
	return (s);
}
