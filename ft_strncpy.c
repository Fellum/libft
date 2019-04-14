/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleann <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 20:44:20 by jleann            #+#    #+#             */
/*   Updated: 2019/04/02 20:44:21 by jleann           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t	cur;

	if (dst == src)
		return (dst);
	cur = 0;
	while (cur < len && src[cur])
	{
		dst[cur] = src[cur];
		cur++;
	}
	while (cur < len && dst[cur])
		dst[cur++] = '\0';
	return (dst);
}
