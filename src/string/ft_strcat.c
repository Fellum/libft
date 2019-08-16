/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleann <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 20:42:36 by jleann            #+#    #+#             */
/*   Updated: 2019/04/02 20:42:37 by jleann           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	size_t	cur1;
	size_t	cur2;

	cur1 = 0;
	while (s1[cur1])
		cur1++;
	cur2 = 0;
	while (s2[cur2])
	{
		s1[cur1 + cur2] = s2[cur2];
		cur2++;
	}
	s1[cur1 + cur2] = 0;
	return (s1);
}
