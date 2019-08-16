/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleann <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 18:27:27 by jleann            #+#    #+#             */
/*   Updated: 2019/04/04 18:27:28 by jleann           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_space(char c)
{
	return (c == ' ' || c == '\n' || c == '\t');
}

char		*ft_strtrim(char const *s)
{
	size_t	begin;
	size_t	end;

	if (!s)
		return (0);
	begin = 0;
	while (is_space(s[begin]))
		begin++;
	end = ft_strlen(s) - 1;
	if (begin - 1 == end)
		return (ft_strdup(""));
	while (is_space(s[end]))
		end--;
	return (ft_strsub(s, begin, end - begin + 1));
}
