/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleann <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 11:16:18 by jleann            #+#    #+#             */
/*   Updated: 2019/04/03 11:16:20 by jleann           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	cur;

	cur = 0;
	while (cur < n)
	{
		if (((t_byte *)s)[cur] == (t_byte)c)
			return ((void *)(s + cur));
		cur++;
	}
	return (0);
}
