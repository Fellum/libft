/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleann <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 23:19:26 by jleann            #+#    #+#             */
/*   Updated: 2019/04/04 23:19:27 by jleann           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list_node				*ft_lstnew_node(void *content, size_t content_size)
{
	t_list_node	*res;

	res = malloc(sizeof(t_list));
	if (!res)
		return (NULL);
	if (content == NULL)
	{
		res->content = NULL;
		res->content_size = 0;
		res->next = NULL;
		return (res);
	}
	res->content = content;
	res->content_size = content_size;
	res->next = NULL;
	return (res);
}
