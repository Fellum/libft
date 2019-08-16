/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleann <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 22:01:41 by jleann            #+#    #+#             */
/*   Updated: 2019/04/02 22:01:43 by jleann           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	cur;
	size_t	tmp;

	if (!*needle)
		return ((char *)haystack);
	cur = 0;
	while (haystack[cur] && cur < len)
	{
		tmp = 0;
		while (needle[tmp] && needle[tmp] == haystack[cur + tmp] &&
			cur + tmp < len)
			tmp++;
		if (!needle[tmp])
			return ((char *)(haystack + cur));
		cur++;
	}
	return (0);
}
