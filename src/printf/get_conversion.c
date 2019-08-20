/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_conversion.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanhand <mcanhand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 19:38:36 by mcanhand          #+#    #+#             */
/*   Updated: 2019/06/20 17:41:49 by mcanhand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		is_conversion(char c)
{
	return (c == 'd' || c == 'i' || c == 'o' || c == 'u' || c == 'x' ||
			c == 'X' || c == 'c' || c == 's' || c == 'p' || c == '%' ||
			c == 'f');
}

char	get_conversion(const char **format)
{
	char res;

	res = -1;
	if (is_conversion(**format))
	{
		res = **format;
		(*format)++;
		return (res);
	}
	else
		return (res);
}
