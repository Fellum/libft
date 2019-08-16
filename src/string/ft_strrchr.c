/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleann <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 21:39:04 by jleann            #+#    #+#             */
/*   Updated: 2019/04/02 21:39:05 by jleann           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	long	cur;

	cur = ft_strlen(s);
	while (cur >= 0)
	{
		if (s[cur] == c)
			return ((char *)(s + cur));
		cur--;
	}
	return (0);
}
