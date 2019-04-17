/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleann <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 11:01:49 by jleann            #+#    #+#             */
/*   Updated: 2019/04/03 11:01:51 by jleann           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t	cur;
	char	found;

	if (dst == src)
		return (dst);
	cur = 0;
	found = 0;
	while (cur < n)
	{
		((t_byte *)dst)[cur] = ((t_byte *)src)[cur];
		if (((t_byte *)dst)[cur] == (t_byte)c)
		{
			cur++;
			found = 1;
			break ;
		}
		cur++;
	}
	if (found)
		return (dst + cur);
	else
		return (0);
}
