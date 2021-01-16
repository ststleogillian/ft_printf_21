/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgillian <jgillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 16:09:01 by jgillian          #+#    #+#             */
/*   Updated: 2020/11/10 15:09:08 by jgillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*go_lst;

	if (new)
	{
		go_lst = *lst;
		if (!(*lst))
			*lst = new;
		else
		{
			while (go_lst->next)
				go_lst = go_lst->next;
			go_lst->next = new;
		}
	}
}
