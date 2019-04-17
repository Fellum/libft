/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleann <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 11:37:37 by jleann            #+#    #+#             */
/*   Updated: 2019/04/03 11:37:38 by jleann           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	cur;

	cur = 0;
	while (cur < n && ((t_byte *)s1)[cur] == ((t_byte *)s2)[cur])
		cur++;
	if (cur == n)
		return (0);
	else
		return (((t_byte *)s1)[cur] - ((t_byte *)s2)[cur]);
}
