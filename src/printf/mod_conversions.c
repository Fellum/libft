/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mod_conversions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanhand <mcanhand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 19:39:46 by mcanhand          #+#    #+#             */
/*   Updated: 2019/06/20 18:08:04 by mcanhand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_ft_printf.h"
#include "ft_string.h"

int	mod_conversions(t_params ft, t_list *lst)
{
	char	space_char;
	char	*res;

	if (ft.field_width < 2)
	{
		res = ft_strnew(1);
		res[0] = '%';
		return (create_node(res, 2, lst));
	}
	space_char = (ft.flags & ZERO_FLAG && !(ft.flags & MINUS_FLAG)) ? '0' : ' ';
	res = fill_with_chars(ft.field_width, space_char);
	res[ft.flags & MINUS_FLAG ? 0 : ft.field_width - 1] = '%';
	return (create_node(res, ft.field_width != -1 ?
						ft.field_width + 1 : 0, lst));
}
