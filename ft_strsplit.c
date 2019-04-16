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

static size_t	calc_words(char const *s, char c)
{
	size_t	res;
	size_t	cur;

	cur = 0;
	res = 0;
	while (s[cur])
	{
		while (s[cur] && s[cur] == c)
			cur++;
		if (s[cur])
		{
			res++;
			while (s[cur] && s[cur] != c)
				cur++;
		}
	}
	return (res);
}

static char		*get_word(char const *s, size_t *cur, char c)
{
	size_t	len;
	char	*res;

	res = 0;
	while (s[*cur] && s[*cur] == c)
		(*cur)++;
	if (s[*cur])
	{
		len = 0;
		while (s[*cur + len] && s[*cur + len] != c)
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

char			**ft_strsplit(char const *s, char c)
{
	char	**res;
	size_t	words;
	size_t	cur;
	size_t	cur_word;

	if (!s)
		return (0);
	words = calc_words(s, c);
	res = (char **)malloc(sizeof(char *) * (words + 1));
	if (!res)
		return (0);
	res[words] = 0;
	cur = 0;
	cur_word = 0;
	while (cur_word < words)
	{
		res[cur_word] = get_word(s, &cur, c);
		if (!res[cur_word])
		{
			free_arr(res, cur_word);
			return (0);
		}
		cur_word++;
	}
	return (res);
}
