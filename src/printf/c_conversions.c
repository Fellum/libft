/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_conversions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleann <jleann@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 19:30:39 by jleann            #+#    #+#             */
/*   Updated: 2019/06/19 20:01:34 by jleann           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_.h"
#include "ft_string.h"

int		c_conversions(t_params ft, va_list *args, t_list *lst)
{
	char	space_char;
	char	*res;

	if (ft.field_width < 2)
	{
		if (!(res = ft_strnew(1)))
			return (-1);
		res[0] = va_arg(*args, int);
		return (create_node(res, 2, lst));
	}
	space_char = (ft.flags & ZERO_FLAG && !(ft.flags & MINUS_FLAG)) ? '0' : ' ';
	if (!(res = fill_with_chars(ft.field_width, space_char)))
		return (-1);
	res[ft.flags & MINUS_FLAG ? 0 : ft.field_width - 1] =
			va_arg(*args, int);
	return (create_node(res, ft.field_width != -1 ? ft.field_width + 1 : 0,
			lst));
}
