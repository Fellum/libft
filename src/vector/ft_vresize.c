/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vresize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleann <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 20:35:49 by jleann            #+#    #+#             */
/*   Updated: 2019/04/02 20:35:51 by jleann           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "ft_vector.h"

void	ft_vresize(t_vector *vec, size_t new_vol)
{
	void	**new_arr;
	size_t	cpy_size;

	new_arr = ft_memalloc(sizeof(void *) * new_vol);
	cpy_size = new_vol > vec->size ? vec->size : new_vol;
	ft_memcpy(new_arr, vec->arr, sizeof(void *) * cpy_size);
	free(vec->arr);
	vec->arr = new_arr;
}
