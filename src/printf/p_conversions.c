/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_conversions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanhand <mcanhand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 13:55:31 by mcanhand          #+#    #+#             */
/*   Updated: 2019/06/20 18:17:42 by mcanhand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "conversions.h"
#include "libft.h"

int		p_conversions(t_params ft, va_list *args, t_list *lst)
{
	long long int	arg_val;
	int				tmp;
	char			*num;
	char			*num2;
	int				str_len;

	arg_val = va_arg(*args, long long int);
	num = ft_itoa_base(arg_val, 16, 0);
	num2 = ft_strjoin("0x", num);
	free(num);
	str_len = ft_strlen(num2);
	((ft.flags & ZERO_FLAG) && (ft.precision != -1)) ?
								ft.flags &= ~ZERO_FLAG : ft.flags;
	ft.flags &= ~HASH_FLAG;
	ft_before_num(ft, str_len, 0, lst);
	create_node(num2, str_len + 1, lst);
	if ((tmp = ft_after_num(ft, str_len, lst, 0)) == -1)
		return (tmp);
	return (tmp);
}
