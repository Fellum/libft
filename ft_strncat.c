/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleann <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 22:33:02 by jleann            #+#    #+#             */
/*   Updated: 2019/04/02 22:33:03 by jleann           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t	cur1;
	size_t	cur2;

	cur1 = 0;
	while (s1[cur1])
		cur1++;
	cur2 = 0;
	while (s2[cur2] && cur2 < n)
	{
		s1[cur1 + cur2] = s2[cur2];
		cur2++;
	}
	s1[cur1 + cur2] = 0;
	return (s1);
}
