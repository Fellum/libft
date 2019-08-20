/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_to_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanhand <mcanhand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 19:26:09 by jleann            #+#    #+#             */
/*   Updated: 2019/06/19 19:54:06 by mcanhand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "large_arythmetics.h"
#include "libft.h"

void	append_string(char **res, char *str)
{
	size_t	res_len;
	size_t	str_len;
	char	*tmp;

	res_len = *res ? ft_strlen(*res) : 0;
	str_len = ft_strlen(str);
	tmp = (char *)malloc(sizeof(char) * (res_len + str_len + 1));
	if (*res)
		ft_strcpy(tmp, *res);
	ft_strcpy(tmp + res_len, str);
	tmp[res_len + str_len] = 0;
	free(*res);
	free(str);
	*res = tmp;
}

int		put_segment(unsigned num, char first, char *dst)
{
	unsigned	max;
	int			cur;

	cur = 0;
	if (first)
	{
		max = 1;
		while (num / max > 9)
			max *= 10;
		num = num % max;
		max /= 10;
	}
	else
		max = BASE / 10;
	while (max)
	{
		dst[cur++] = '0' + num / max;
		num = num % max;
		max /= 10;
	}
	dst[cur] = 0;
	return (cur);
}

int		put_uint(unsigned num, char first, char *dst)
{
	unsigned	max;
	int			res;

	res = 0;
	if (first)
	{
		max = 1;
		while (num / max > 9)
			max *= 10;
	}
	else
		max = BASE / 10;
	while (max)
	{
		dst[res++] = '0' + num / max;
		num = num % max;
		max /= 10;
	}
	return (res);
}

char	*float_part_to_str(unsigned *longnum, int precision)
{
	char	*res;
	int		cur_seg;
	int		cur_pos;
	int		tmp;

	if (precision == 0)
		return (ft_strdup(""));
	cur_seg = longnum[0];
	res = (char *)malloc(precision + 2);
	if (!res)
		return (NULL);
	res[precision + 1] = '\0';
	res[0] = '.';
	cur_pos = 1;
	tmp = put_segment(longnum[cur_seg--], 1, res + cur_pos);
	cur_pos += tmp;
	while (cur_seg > 0)
	{
		tmp = put_segment(longnum[cur_seg--], 0, res + cur_pos);
		cur_pos += tmp;
	}
	while (cur_pos <= precision)
		res[cur_pos++] = '0';
	return (res);
}

char	*int_part_to_str(unsigned *longnum)
{
	char	*res;
	int		cur_seg;
	int		cur_pos;
	int		tmp;

	cur_seg = longnum[0];
	tmp = calc_uint_len(longnum[cur_seg]) + 9 * (cur_seg - 1);
	tmp = tmp ? tmp : 1;
	res = ft_strnew(tmp);
	if (!res)
		return (NULL);
	cur_pos = 0;
	res[tmp] = 0;
	cur_pos += put_uint(longnum[cur_seg--], 1, res + cur_pos);
	while (cur_seg > 0)
		cur_pos += put_uint(longnum[cur_seg--], 0, res + cur_pos);
	return (res);
}
