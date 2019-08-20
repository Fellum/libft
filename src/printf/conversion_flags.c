/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_flags.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleann <jleann@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 17:39:02 by mcanhand          #+#    #+#             */
/*   Updated: 2019/06/19 20:08:25 by mcanhand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "conversions.h"
#include <unistd.h>

long long	convert_flags(int flags, va_list *args)
{
	long long	n;

	if (flags & LO_FLAG)
		n = va_arg(*args, long);
	else if (flags & LLO_FLAG)
		n = va_arg(*args, long long);
	else
		n = va_arg(*args, int);
	if (flags & H_FLAG)
		n = (short)n;
	else if (flags & HH_FLAG)
		n = (signed char)n;
	return (n);
}
