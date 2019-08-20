/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_conversion.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanhand <mcanhand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 16:26:13 by mcanhand          #+#    #+#             */
/*   Updated: 2019/06/20 17:46:49 by mcanhand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "conversions.h"
#include "libft.h"

int		u_conversions(t_params ft, va_list *args, t_list *lst)
{
	unsigned long long int	arg_val;
	int						res;
	int						tmp;
	char					*num;
	int						str_len;

	res = 0;
	arg_val = convert_flags_u(ft.flags, args);
	num = ft_itoa_base_hex_long(arg_val, 10, (ft.conversion == 'x') ? 0 : 1);
	((ft.flags & ZERO_FLAG) && (ft.precision != -1)) ?
			ft.flags &= ~ZERO_FLAG : ft.flags;
	ft.flags &= ~HASH_FLAG;
	str_len = ((arg_val == 0) && (ft.precision == 0)) ? 0 : ft_strlen(num);
	ft.field_width = ft.precision > ft.field_width ?
						ft.precision : ft.field_width;
	tmp = ft_before_num(ft, str_len, 0, lst);
	create_node(num, str_len + 1, lst);
	if ((tmp = ft_after_num(ft, str_len, lst, 0)) == -1)
		return (tmp);
	tmp += str_len;
	return (tmp);
}
