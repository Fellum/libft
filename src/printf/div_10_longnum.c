/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   div_10_longnum.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanhand <mcanhand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 17:49:57 by mcanhand          #+#    #+#             */
/*   Updated: 2019/06/20 18:08:36 by mcanhand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "large_arythmetics.h"

void		div_10_longnum(unsigned *num)
{
	unsigned		old_tail;
	unsigned		tail;
	int				cur;

	tail = 0;
	cur = num[0];
	while (cur >= 1)
	{
		old_tail = tail;
		tail = num[cur] % 10;
		num[cur] = num[cur] / 10 + (BASE / 10) * old_tail;
		cur--;
	}
	if (!num[num[0]])
		num[0] -= 1;
}
