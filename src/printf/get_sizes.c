/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_sizes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanhand <mcanhand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 19:39:22 by mcanhand          #+#    #+#             */
/*   Updated: 2019/06/19 20:02:32 by mcanhand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>

int		get_len(const char **format)
{
	int res;

	res = 0;
	if (**format >= '0' && **format <= '9')
	{
		while (**format >= '0' && **format <= '9')
		{
			res = res * 10 + **format - '0';
			(*format)++;
		}
	}
	else
		return (-1);
	return (res);
}

int		get_field_width(const char **format, va_list *args)
{
	if (**format == '*')
	{
		(*format)++;
		return (va_arg(*args, int));
	}
	else
		return (get_len(format));
}

int		get_precision(const char **format, va_list *args)
{
	int res;

	if (**format == '.')
	{
		(*format)++;
		if ((res = get_field_width(format, args)) != -1)
			return (res);
		else
			return (0);
	}
	return (-1);
}
