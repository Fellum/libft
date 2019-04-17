/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleann <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 23:22:30 by jleann            #+#    #+#             */
/*   Updated: 2019/04/03 23:22:32 by jleann           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
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
		res[cur] = f(cur, s[cur]);
		cur++;
	}
	return (res);
}
