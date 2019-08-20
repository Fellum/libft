/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_to_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanhand <mcanhand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 19:42:28 by mcanhand          #+#    #+#             */
/*   Updated: 2019/06/20 18:14:30 by mcanhand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include "ft_string.h"

char			*ft_lst_to_str(t_list *lst)
{
	char		*res;
	size_t		sum_length;
	size_t		cur;
	t_list_node	*cur_node;

	sum_length = ft_calc_string_len(lst);
	if (!(res = ft_strnew(sum_length)))
		return (NULL);
	cur = 0;
	cur_node = lst->begin;
	while (cur_node)
	{
		if (cur_node->content && cur_node->content_size)
		{
			ft_memcpy(res + cur, cur_node->content, cur_node->content_size - 1);
			cur += cur_node->content_size - 1;
		}
		cur_node = cur_node->next;
	}
	res[cur] = '\0';
	return (res);
}
