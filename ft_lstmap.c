/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleann <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 18:44:39 by jleann            #+#    #+#             */
/*   Updated: 2019/04/09 18:44:42 by jleann           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		del_elem(void *content, size_t content_size)
{
	content_size++;
	free(content);
}

static int		main_loop(t_list *lst, t_list **begin, t_list *(*f)(t_list *elem))
{
	t_list *cur;
	t_list *tmp;

	cur = *begin;
	while (lst)
	{
		if (!(tmp = f(lst)))
		{
			if (!(tmp = ft_lstnew(tmp->content, tmp->content_size)))
			{
				ft_lstdel(begin, del_elem);
				return (1);
			}
			ft_lstaddend(&cur, tmp);
			cur = cur->next;
		}
		lst = lst->next;
	}
	return (0);
}

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*begin;

	begin = NULL;
	if (!lst || !f)
		return (NULL);
	while (!(begin = f(lst)))
		lst = lst->next;
	if (!(begin = ft_lstnew(begin->content, begin->content_size)))
		return (NULL);
	if (main_loop(lst, &begin, f) != 0)
		return (NULL);
	return (begin);
}

