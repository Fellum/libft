/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleann <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 23:50:29 by jleann            #+#    #+#             */
/*   Updated: 2019/04/03 23:50:32 by jleann           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	size_t	len1;
	size_t	len2;

	if (!s1 && s2)
		return (ft_strdup(s2));
	if (!s2 && s1)
		return (ft_strdup(s1));
	if (!s1 && !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	if (len2 > ULONG_MAX - len1 - 1)
		return (NULL);
	res = ft_strnew(len1 + len2);
	if (!res)
		return (NULL);
	res = ft_strcpy(res, s1);
	res = ft_strcat(res, s2);
	return (res);
}
