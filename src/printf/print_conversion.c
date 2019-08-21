/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_conversion.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleann <jleann@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 15:24:04 by jleann            #+#    #+#             */
/*   Updated: 2019/06/24 15:24:47 by jleann           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "conversions.h"
#include "ft_printf.h"

int		print_conversion(t_params formating, va_list *args, t_list *lst)
{
	if (formating.conversion == 'c')
		return (c_conversions(formating, args, lst));
	else if (formating.conversion == '%')
		return (mod_conversions(formating, lst));
	else if (formating.conversion == 'd' || formating.conversion == 'i')
		return (d_conversions(formating, args, lst));
	else if (formating.conversion == 's')
		return (s_conversions(formating, args, lst));
	else if (formating.conversion == 'x' || formating.conversion == 'X')
		return (x_conversions(formating, args, lst));
	else if (formating.conversion == 'o')
		return (o_conversions(formating, args, lst));
	else if (formating.conversion == 'u')
		return (u_conversions(formating, args, lst));
	else if (formating.conversion == 'p')
		return (p_conversions(formating, args, lst));
	else if (formating.conversion == 'f')
		return (f_conversions(formating, args, lst));
	return (0);
}
