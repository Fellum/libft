/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleann <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 11:54:51 by jleann            #+#    #+#             */
/*   Updated: 2019/04/03 11:54:54 by jleann           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t n;
	size_t cur1;
	size_t cur2;
	size_t dlen;

	n = size;
	cur1 = 0;
	cur2 = 0;
	while (n-- != 0 && dst[cur1])
		cur1++;
	dlen = cur1;
	n = size - cur1;
	if (n == 0)
		return (dlen + ft_strlen(src));
	while (src[cur2])
	{
		if (n != 1)
		{
			dst[cur1++] = src[cur2];
			n--;
		}
		cur2++;
	}
	dst[cur1] = 0;
	return (dlen + cur2);
}
