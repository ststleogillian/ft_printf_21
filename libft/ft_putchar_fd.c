/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgillian <jgillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 12:09:36 by jgillian          #+#    #+#             */
/*   Updated: 2020/11/09 15:36:22 by jgillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	unsigned char	code[2];

	if (c >= 0)
		write(fd, &c, 1);
	else
	{
		code[1] = (unsigned char)c;
		code[0] = (code[1] < 192) ? 0xc2 : 0xc3;
		code[1] > 191 ? code[1] -= 64 : 0;
		write(fd, code, 2);
	}
}
