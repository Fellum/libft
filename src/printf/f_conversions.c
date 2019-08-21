/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_conversions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanhand <mcanhand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 19:18:58 by mcanhand          #+#    #+#             */
/*   Updated: 2019/06/24 15:22:49 by mcanhand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_.h"
#include "ft_string.h"
#include <stdlib.h>

void	place_sign(t_params ft, char sign, t_list *lst)
{
	if (sign)
		create_node(ft_strdup("-"), 2, lst);
	else if (ft.flags & PLUS_FLAG)
		create_node(ft_strdup("+"), 2, lst);
	else if (ft.flags & SPACE_FLAG)
		create_node(ft_strdup(" "), 2, lst);
}

int		calc_min_chars(t_params ft, long double val, size_t len)
{
	int min_chars;

	min_chars = (val < 0 || ft.flags & SPACE_FLAG ||
				ft.flags & PLUS_FLAG || (val == 0 && 1 / val < 0));
	min_chars += len;
	min_chars += (ft.precision == 0 && ft.flags & HASH_FLAG);
	return (min_chars);
}

void	left_part(t_params ft, long double val, size_t len, t_list *lst)
{
	int		min_chars;
	char	*spaces;
	char	tmp;

	if (val == 0 && 1 / val < 0)
	{
		ft.flags &= ~SPACE_FLAG;
		ft.flags &= ~PLUS_FLAG;
	}
	min_chars = calc_min_chars(ft, val, len);
	if (ft.flags & MINUS_FLAG || ft.flags & ZERO_FLAG)
		place_sign(ft, val < 0 || ((val == 0 && 1 / val < 0)), lst);
	if (ft.field_width > min_chars && !(ft.flags & MINUS_FLAG))
	{
		tmp = ft.flags & ZERO_FLAG ? '0' : ' ';
		spaces = fill_with_chars(ft.field_width - min_chars, tmp);
		create_node(spaces, ft.field_width - min_chars + 1, lst);
	}
	if (!(ft.flags & MINUS_FLAG || ft.flags & ZERO_FLAG))
		place_sign(ft, (val < 0) || ((val == 0 && 1 / val < 0)), lst);
}

void	right_part(t_params ft, long double val, size_t len, t_list *lst)
{
	int		min_chars;
	char	*spaces;

	min_chars = calc_min_chars(ft, val, len);
	if (ft.flags & HASH_FLAG && ft.precision == 0)
		create_node(ft_strdup("."), 2, lst);
	if (ft.field_width > min_chars && ft.flags & MINUS_FLAG)
	{
		spaces = fill_with_chars(ft.field_width - min_chars, ' ');
		create_node(spaces, ft.field_width - min_chars + 1, lst);
	}
}

int		f_conversions(t_params ft, va_list *args, t_list *lst)
{
	char		*res;
	long double	val;
	int			len;

	ft.precision = ft.precision == -1 ? 6 : ft.precision;
	val = ft.flags & L_FLAG ? va_arg(*args, long double) :
					va_arg(*args, double);
	if (val == -(1.0 / 0.0) || val == (1.0 / 0.0) || (val != 1 * val))
	{
		ft.flags &= ~ZERO_FLAG;
		ft.flags &= ~HASH_FLAG;
		if (val != 1 * val)
			ft.flags &= ~SPACE_FLAG | ~PLUS_FLAG;
		res = ft_strdup((val != 1 * val) ? "nan" : "inf");
	}
	else
		res = ft.flags & L_FLAG ? make_ldouble(val, ft.precision) :
				make_double(val, ft.precision);
	len = ft_strlen(res);
	left_part(ft, val, len, lst);
	create_node(res, len + 1, lst);
	right_part(ft, val, len, lst);
	return (0);
}
