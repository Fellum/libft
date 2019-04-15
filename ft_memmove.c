/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleann <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 21:00:09 by jleann            #+#    #+#             */
/*   Updated: 2019/04/02 21:00:10 by jleann           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	if (dst <= src)
		return (ft_memcpy(dst, src, len));
	while (len-- > 0)
		((t_byte *)dst)[len] = ((t_byte *)src)[len];
	return (dst);
}
