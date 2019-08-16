/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lsttostr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleann <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 08:41:50 by jleann            #+#    #+#             */
/*   Updated: 2019/04/10 08:41:52 by jleann           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_lsttostr(t_list *lst)
{
	t_list	*tmp;
	char	*res;

	res = NULL;
	tmp = lst;
	while (tmp)
	{
		res = ft_strjoin(res, (char *)(tmp->content));
		tmp = tmp->next;
	}
	return (res);
}
