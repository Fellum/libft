/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstat.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleann <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 18:50:39 by jleann            #+#    #+#             */
/*   Updated: 2019/04/05 18:50:40 by jleann           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_lstat(t_list *alst, size_t at)
{
	size_t cur;

	if (!alst)
		return (NULL);
	cur = 0;
	while (alst)
	{
		if (cur == at)
			return (alst);
		alst = alst->next;
		cur++;
	}
	return (NULL);
}
