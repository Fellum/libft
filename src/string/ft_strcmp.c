/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleann <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 20:42:50 by jleann            #+#    #+#             */
/*   Updated: 2019/04/02 20:42:51 by jleann           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	size_t cur;

	cur = 0;
	while (s1[cur] == s2[cur])
	{
		if (!s1[cur] && !s2[cur])
			return (0);
		cur++;
	}
	return ((t_byte)s1[cur] - (t_byte)s2[cur]);
}
