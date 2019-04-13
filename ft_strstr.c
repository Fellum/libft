/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleann <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 20:44:29 by jleann            #+#    #+#             */
/*   Updated: 2019/04/02 20:44:30 by jleann           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t	cur;
	size_t	tmp;

	if (!*needle)
		return ((char *)haystack);
	cur = 0;
	while (haystack[cur])
	{
		tmp = 0;
		while (needle[tmp] && needle[tmp] == haystack[cur + tmp])
			tmp++;
		if (!needle[tmp])
			return ((char *)(haystack + cur));
		cur++;
	}
	return (0);
}
