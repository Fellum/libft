/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   o_conversions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanhand <mcanhand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 12:28:10 by mcanhand          #+#    #+#             */
/*   Updated: 2019/06/21 15:55:18 by mcanhand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>
#include "conversions.h"
#include "libft.h"

void	ft_oconversions(t_params ft, int str_len, t_list *lst)
{
	char	*line;
	int		i;
	int		spaces;

	i = 0;
	spaces = ft.field_width - ((ft.precision > str_len) ?
			ft.precision : str_len) - ((ft.flags & HASH_FLAG) ? 1 : 0);
	if ((ft.flags & MINUS_FLAG) &&
			(ft.field_width > ft.precision) && spaces > 0)
	{
		line = (char *)malloc(sizeof(char) * (spaces + 1));
		while (i < spaces)
			line[i++] = ' ';
		line[i] = '\0';
		create_node(line, spaces + 1, lst);
	}
}

int		o_conversions(t_params ft, va_list *args, t_list *lst)
{
	unsigned long long	arg_val;
	int					tmp;
	char				*num;
	int					str_len;

	arg_val = convert_flags_u(ft.flags, args);
	num = ft_itoa_base_hex_long(arg_val, 8, 1);
	str_len = ((arg_val == 0) && (ft.precision == 0)) ? 0 : ft_strlen(num);
	((ft.flags & ZERO_FLAG) && (ft.precision != -1)) ?
						ft.flags &= ~ZERO_FLAG : ft.flags;
	ft.field_width = ft.precision > ft.field_width ?
						ft.precision : ft.field_width;
	if (((arg_val == 0) && (ft.flags & HASH_FLAG) &&
			(ft.precision != 0)) || ft.precision > str_len)
		(ft.flags &= ~HASH_FLAG);
	tmp = ft_before_num(ft, str_len, (ft.flags & HASH_FLAG) ? 1 : 0, lst);
	(arg_val == 0 && ft.precision == 0) ? 0 :
						create_node(num, str_len + 1, lst);
	ft_oconversions(ft, str_len, lst);
	return (0);
}
