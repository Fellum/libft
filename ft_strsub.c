/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleann <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 23:44:12 by jleann            #+#    #+#             */
/*   Updated: 2019/04/03 23:44:13 by jleann           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*res;

	if (!s)
		return (0);
	res = ft_strnew(len);
	if (!res)
		return (0);
	ft_strncpy(res, s + start, len);
	return (res);
}
