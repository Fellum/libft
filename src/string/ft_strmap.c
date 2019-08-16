/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleann <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 23:22:22 by jleann            #+#    #+#             */
/*   Updated: 2019/04/03 23:22:23 by jleann           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t	cur;
	char	*res;

	if (!s || !f)
		return (0);
	res = ft_strnew(ft_strlen(s));
	if (!res)
		return (0);
	cur = 0;
	while (s[cur])
	{
		res[cur] = f(s[cur]);
		cur++;
	}
	return (res);
}
