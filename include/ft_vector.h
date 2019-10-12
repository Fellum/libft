/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleann <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 20:35:49 by jleann            #+#    #+#             */
/*   Updated: 2019/04/02 20:35:51 by jleann           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_VECTOR_H
# define FT_VECTOR_H

# include <stdlib.h>

typedef struct	s_vector
{
	void		**arr;
	size_t		volume;
	size_t		size;
}				t_vector;

t_vector		*ft_vinit(size_t size);
void			ft_vpush(t_vector *to, void *data);
void			ft_vcpush(t_vector *to, void *data, size_t data_len);
void			ft_vresize(t_vector *vec, size_t new_vol);

#endif
