/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_conversions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanhand <mcanhand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/26 13:08:21 by mcanhand          #+#    #+#             */
/*   Updated: 2019/06/21 14:44:38 by mcanhand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>
#include "conversions.h"
#include "libft.h"
#include "ft_string.h"

int		x_conversions(t_params ft, va_list *args, t_list *lst)
{
	long long	arg_val;
	int			tmp;
	char		*num;
	int			str_len;

	arg_val = convert_flags_u(ft.flags, args);
	num = ft_itoa_base_hex_long(arg_val, 16,
		(ft.conversion == 'x') ? 0 : 1);
	(arg_val == 0) ? ft.flags &= ~HASH_FLAG : ft.flags;
	str_len = ((arg_val == 0) && (ft.precision == 0)) ? 0 : ft_strlen(num);
	((ft.flags & ZERO_FLAG) && (ft.precision != -1)) ?
								ft.flags &= ~ZERO_FLAG : ft.flags;
	ft.field_width = ft.precision > ft.field_width ?
						ft.precision : ft.field_width;
	ft_before_num(ft, str_len, (ft.flags & HASH_FLAG) ? 2 : 0, lst);
	create_node(num, str_len + 1, lst);
	if ((tmp = ft_after_num(ft, str_len, lst,
			(ft.flags & HASH_FLAG) ? 2 : 0)) == -1)
		return (tmp);
	tmp += str_len;
	return (0);
}
