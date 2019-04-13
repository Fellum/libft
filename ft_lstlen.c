/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleann <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 08:41:43 by jleann            #+#    #+#             */
/*   Updated: 2019/04/10 08:41:45 by jleann           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_lstlen(t_list *lst)
{
	size_t	res;

	res = 0;
	while (lst)
	{
		lst = lst->next;
		res++;
	}
	return (res);
}
