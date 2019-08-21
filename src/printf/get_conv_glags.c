/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_conv_glags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanhand <mcanhand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 19:38:22 by mcanhand          #+#    #+#             */
/*   Updated: 2019/06/19 19:55:38 by mcanhand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_.h"

int			is_conv_flag(char c)
{
	return (c == 'l' || c == 'L' || c == 'h' || c == 'j' || c == 'z');
}

unsigned	comp_flag_ll(const char **format)
{
	if (*(*format + 1) == 'l')
	{
		(*format)++;
		return (LLO_FLAG);
	}
	else
		return (LO_FLAG);
}

unsigned	comp_flag_hh(const char **format)
{
	if (*(*format + 1) == 'h')
	{
		(*format)++;
		return (HH_FLAG);
	}
	else
		return (H_FLAG);
}

unsigned	get_conv_flags(const char **format)
{
	unsigned res;

	res = 0;
	while (**format && is_conv_flag(**format))
	{
		if (**format == 'l')
			res |= comp_flag_ll(format);
		else if (**format == 'h')
			res |= comp_flag_hh(format);
		else if (**format == 'L')
			res |= L_FLAG;
		else if (**format == 'z')
			res |= Z_FLAG;
		else if (**format == 'j')
			res |= J_FLAG;
		(*format)++;
	}
	return (res);
}
