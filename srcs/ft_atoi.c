/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleann <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 21:54:40 by jleann            #+#    #+#             */
/*   Updated: 2019/04/14 04:22:24 by jleann           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_space(char c)
{
	return (c == '\n' || c == '\t' || c == '\v' ||
			c == ' ' || c == '\f' || c == '\r');
}

int			ft_atoi(const char *str)
{
	long			res;
	int				sign;
	long			treshold;
	int				treshold_dig;

	while (*str && (*str == '0' || is_space(*str)))
		str++;
	sign = 1;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	treshold = LONG_MAX / 10;
	treshold_dig = sign == 1 ? LONG_MAX % 10 : (LONG_MIN % 10) * -1;
	res = 0;
	while (*str && ft_isdigit(*str))
	{
		if (res > treshold || (res == treshold && (*str - '0') > treshold_dig))
			return (sign == 1 ? -1 : 0);
		res = res * 10 + (*str - '0');
		str++;
	}
	return (sign * res);
}
