/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_conversion.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanhand <mcanhand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 19:18:58 by mcanhand          #+#    #+#             */
/*   Updated: 2019/06/19 20:05:52 by mcanhand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_.h"
#include "ft_string.h"

int	s_conversions(t_params ft, va_list *args, t_list *lst)
{
	char	*arg_val;
	char	*res;
	int		str_len;

	if (!(arg_val = va_arg(*args, char *)))
		arg_val = "(null)";
	str_len = ft_strlen(arg_val);
	str_len = ft.precision != -1 && ft.precision < str_len ?
							ft.precision : str_len;
	res = ft_strsub(arg_val, 0, str_len);
	if (ft.field_width > str_len)
	{
		arg_val = fill_with_chars(ft.field_width - str_len, ' ');
		if (!(ft.flags & MINUS_FLAG))
			create_node(arg_val, ft.field_width - str_len + 1, lst);
		create_node(res, str_len + 1, lst);
		if (ft.flags & MINUS_FLAG)
			create_node(arg_val, ft.field_width - str_len + 1, lst);
	}
	else
		create_node(res, str_len + 1, lst);
	return (0);
}
