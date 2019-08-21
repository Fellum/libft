/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_conversions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleann <jleann@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 18:45:25 by jleann            #+#    #+#             */
/*   Updated: 2019/06/20 18:22:37 by jleann           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "conversions.h"
#include "libft.h"

int		before_num(t_params ft, int str_len, long long arg_val, t_list *lst)
{
	char	space_char;
	int		spaces;
	char	*str;
	int		tmp;

	space_char = (ft.flags & ZERO_FLAG) ? '0' : ' ';
	spaces = ft.field_width - ((str_len > ft.precision) ?
			str_len : ft.precision) - ((ft.flags & PLUS_FLAG) ||
			(arg_val < 0) || (ft.flags & SPACE_FLAG));
	spaces = (ft.flags & MINUS_FLAG) ? 0 : spaces;
	if (spaces > 0)
	{
		str = fill_with_chars(spaces, space_char);
		if ((tmp = create_node(str, spaces + 1, lst)) == -1)
			return (tmp);
	}
	if (((ft.flags & PLUS_FLAG) || (arg_val < 0)) && !(ft.flags & ZERO_FLAG))
		if ((tmp = create_node((arg_val < 0) ? ft_strdup("-") :
						ft_strdup("+"), 2, lst)) == -1)
			return (tmp);
	return (1);
}

int		ft_dconversion(t_params ft, int len, long long arg_val, t_list *lst)
{
	int		tmp;
	char	*str;
	int		spaces;
	int		i;

	tmp = 0;
	i = 0;
	spaces = before_num(ft, len, arg_val, lst);
	if (ft.precision - len > 0)
	{
		if (!(str = (char *)malloc(sizeof(char) * (ft.precision - len + 1))))
			return (-1);
		while (i < ft.precision - len)
			str[i++] = '0';
		str[i] = '\0';
		if ((tmp = create_node(str, ft.precision - len + 1, lst)) == -1)
			return (tmp);
	}
	return (1);
}

int		ft_print_sign(unsigned flags, intmax_t arg_val, t_list *lst)
{
	int		tmp;

	tmp = 0;
	if (((flags & PLUS_FLAG) || (arg_val < 0)) && (flags & ZERO_FLAG))
		if ((tmp = create_node(ft_strdup((arg_val < 0) ? "-" : "+"), 2, lst)))
			return (tmp);
	if ((flags & SPACE_FLAG) && !((flags & PLUS_FLAG) || (arg_val < 0)))
		if ((tmp = create_node(ft_strdup(" "), 2, lst) == -1))
			return (tmp);
	return (tmp);
}

int		d_conversions(t_params ft, va_list *args, t_list *lst)
{
	long long int		arg_val;
	int					str_len;
	int					tmp;
	char				*num;

	str_len = 0;
	arg_val = convert_flags(ft.flags, args);
	if (((arg_val != 0) || (ft.precision != 0)) && !(num = ft_itoa_base(arg_val,
			10, 0)))
		return (-1);
	((ft.flags & ZERO_FLAG) && (ft.precision != -1)) ?
				ft.flags &= ~ZERO_FLAG : ft.flags;
	if ((arg_val != 0) || (ft.precision != 0))
		str_len = ft_strlen(num);
	if ((tmp = ft_print_sign(ft.flags, arg_val, lst) == -1))
		return (tmp);
	if ((tmp = ft_dconversion(ft, str_len, arg_val, lst) == -1))
		return (tmp);
	((arg_val == 0) && (ft.precision == 0)) ? 0 :
				create_node(num, str_len + 1, lst);
	if ((ft.flags & MINUS_FLAG) && (ft.field_width > ft.precision))
		if ((tmp = ft_after_num(ft, str_len, lst, ((ft.flags & PLUS_FLAG)
			|| (arg_val < 0) || (ft.flags & SPACE_FLAG)))) == -1)
			return (tmp);
	return (0);
}
