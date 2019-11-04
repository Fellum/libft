/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleann <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 18:35:56 by jleann            #+#    #+#             */
/*   Updated: 2019/04/04 18:35:58 by jleann           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	calc_words(char const *s, const char *seps)
{
	size_t	res;
	size_t	cur;

	cur = 0;
	res = 0;
	while (s[cur])
	{
		while (s[cur] && ft_contain(seps, s[cur]))
			cur++;
		if (s[cur])
		{
			res++;
			while (s[cur] && !ft_contain(seps, s[cur]))
				cur++;
		}
	}
	return (res);
}

static char		*get_word(char const *s, size_t *cur, const char *seps)
{
	size_t	len;
	char	*res;

	res = 0;
	while (s[*cur] && ft_contain(seps, s[*cur]))
		(*cur)++;
	if (s[*cur])
	{
		len = 0;
		while (s[*cur + len] && !ft_contain(seps, s[*cur + len]))
			len++;
		if (len != 0)
			res = ft_strsub(s, *cur, len);
		*cur += len;
	}
	return (res);
}

static void		free_arr(char **arr, size_t cur_word)
{
	size_t cur;

	cur = 0;
	while (cur < cur_word)
		free(arr[cur++]);
	free(arr);
}

char			**ft_strsplit(char const *s, const char *seps)
{
	char	**res;
	size_t	words;
	size_t	cur;
	size_t	cur_word;

	if (!s)
		return (0);
	words = calc_words(s, seps);
	if (!(res = (char **)ft_memalloc(sizeof(char *) * (words + 1))))
		return (0);
	cur = 0;
	cur_word = 0;
	while (cur_word < words)
	{
		res[cur_word] = get_word(s, &cur, seps);
		if (!res[cur_word])
		{
			free_arr(res, cur_word);
			return (0);
		}
		cur_word++;
	}
	return (res);
}
