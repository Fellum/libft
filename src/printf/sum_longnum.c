/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sum_longnum.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanhand <mcanhand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 17:51:24 by mcanhand          #+#    #+#             */
/*   Updated: 2019/06/20 18:20:26 by mcanhand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "large_arythmetics.h"

void	sum_longnum(unsigned *left, unsigned *right, unsigned *dst)
{
	unsigned	res;
	unsigned	max_len;
	int			tail;
	unsigned	cur;

	tail = 0;
	cur = 1;
	max_len = left[0] > right[0] ? left[0] : right[0];
	while (cur <= max_len || tail)
	{
		res = (cur <= left[0] ? left[cur] : 0) +
					(cur <= right[0] ? right[cur] : 0) + tail;
		tail = res / BASE;
		dst[cur] = res % BASE;
		cur++;
	}
	dst[0] = cur - 1;
}
