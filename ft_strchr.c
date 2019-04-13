/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleann <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 21:38:57 by jleann            #+#    #+#             */
/*   Updated: 2019/04/02 21:38:58 by jleann           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	cur;

	cur = 0;
	while (s[cur])
	{
		if (s[cur] == c)
			return ((char *)(s + cur));
		cur++;
	}
	if (c == '\0')
		return ((char *)(s + cur));
	return (0);
}
