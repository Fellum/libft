/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfind.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleann <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 18:50:39 by jleann            #+#    #+#             */
/*   Updated: 2019/04/05 18:50:40 by jleann           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_lstfind(t_list *alst, void *content, int (*f)(void *, void *,
		size_t size)
{
	if (!alst || !f)
		return (NULL);
	while (alst)
	{
		if (f(alst->content, content, size) == 0)
			return (alst);
		alst = alst->next;
	}
	return (NULL);
}
