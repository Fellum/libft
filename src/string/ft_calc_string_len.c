/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calc_string_len.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleann <jleann@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 16:06:52 by mcanhand          #+#    #+#             */
/*   Updated: 2019/06/19 20:09:01 by mcanhand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_calc_string_len(t_list *lst)
{
	size_t		sum_length;
	t_list_node	*cur;

	sum_length = 0;
	cur = lst->begin;
	while (cur)
	{
		sum_length += cur->content_size ? cur->content_size - 1 : 0;
		cur = cur->next;
	}
	return (sum_length);
}
