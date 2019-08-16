/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleann <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 20:43:55 by jleann            #+#    #+#             */
/*   Updated: 2019/04/14 04:42:13 by jleann           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strdup(const char *s1)
{
	char	*res;

	res = ft_strnew(ft_strlen(s1));
	if (!res)
		return (0);
	ft_strcpy(res, s1);
	return (res);
}
