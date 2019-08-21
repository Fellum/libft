/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_flags.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanhand <mcanhand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 15:24:44 by mcanhand          #+#    #+#             */
/*   Updated: 2019/06/19 20:02:01 by mcanhand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_.h"

int		is_flag(char c)
{
	return (c == ' ' || c == '0' || c == '#' || c == '+' || c == '-');
}

int		get_flags(const char **format)
{
	unsigned res;

	res = 0;
	while (**format && is_flag(**format))
	{
		if (**format == ' ')
			res |= SPACE_FLAG;
		else if (**format == '0')
			res |= ZERO_FLAG;
		else if (**format == '#')
			res |= HASH_FLAG;
		else if (**format == '+')
			res |= PLUS_FLAG;
		else if (**format == '-')
			res |= MINUS_FLAG;
		(*format)++;
	}
	return (res);
}
