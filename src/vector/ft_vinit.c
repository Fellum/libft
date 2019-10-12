/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vinit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleann <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 20:35:49 by jleann            #+#    #+#             */
/*   Updated: 2019/04/02 20:35:51 by jleann           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "ft_vector.h"

t_vector	*ft_vinit(size_t size)
{
	t_vector	*res;

	res = ft_memalloc(sizeof(t_vector));
	res->arr = ft_memalloc(sizeof(void *) * size);
	res->size = 0;
	res->volume = size;
	return (res);
}
