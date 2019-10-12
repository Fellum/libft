/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vpush.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleann <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 20:35:49 by jleann            #+#    #+#             */
/*   Updated: 2019/04/02 20:35:51 by jleann           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "ft_vector.h"

void	ft_vcpush(t_vector *to, void *data, size_t data_len)
{
	if (to->size == to->volume)
		ft_vresize(to, to->volume * 2);
	to->arr[to->size] = ft_memdup(data, data_len);
}
