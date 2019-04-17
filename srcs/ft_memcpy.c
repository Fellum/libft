/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleann <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 20:41:31 by jleann            #+#    #+#             */
/*   Updated: 2019/04/02 20:41:32 by jleann           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	cur;

	if (dst == src)
		return (dst);
	cur = 0;
	while (cur < n)
	{
		((t_byte *)dst)[cur] = ((t_byte *)src)[cur];
		cur++;
	}
	return (dst);
}
