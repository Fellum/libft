/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleann <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 20:43:03 by jleann            #+#    #+#             */
/*   Updated: 2019/04/02 20:43:05 by jleann           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *dst, const char *src)
{
	size_t	cur;

	if (src == dst)
		return (dst);
	cur = 0;
	while (src[cur])
	{
		dst[cur] = src[cur];
		cur++;
	}
	dst[cur] = 0;
	return (dst);
}
