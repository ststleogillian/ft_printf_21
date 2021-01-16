/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgillian <jgillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 13:13:40 by jgillian          #+#    #+#             */
/*   Updated: 2020/11/03 13:44:39 by jgillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	if ((ptr = (void *)malloc(size * count)) == NULL)
		return (NULL);
	ft_bzero(ptr, count * size);
	return (ptr);
}
