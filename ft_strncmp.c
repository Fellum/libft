/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleann <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 22:15:59 by jleann            #+#    #+#             */
/*   Updated: 2019/04/02 22:16:01 by jleann           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t cur;

	if (s1 == s2)
		return (0);
	cur = 0;
	while (cur < n && s1[cur] == s2[cur])
	{
		if (!s1[cur] && !s2[cur])
			return (0);
		cur++;
	}
	if (cur == n)
		return (0);
	else
		return ((t_byte)s1[cur] - (t_byte)s2[cur]);
}
