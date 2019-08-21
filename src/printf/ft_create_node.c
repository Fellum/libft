/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_node.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanhand <mcanhand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 15:20:50 by mcanhand          #+#    #+#             */
/*   Updated: 2019/06/12 17:24:45 by mcanhand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

int		create_node(void *str, size_t len, t_list *lst)
{
	t_list_node	*tmp_lst;

	if (!(tmp_lst = ft_lstnew_node(str, len)))
	{
		free(str);
		return (-1);
	}
	ft_lstaddend(lst, tmp_lst);
	free(str);
	return (0);
}
