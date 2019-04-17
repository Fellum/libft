/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleann <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 18:36:05 by jleann            #+#    #+#             */
/*   Updated: 2019/04/04 18:36:05 by jleann           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*zero_case(void)
{
	return (ft_strdup("0"));
}

static int	calc_len(int n)
{
	int res;

	res = 0;
	while (n != 0)
	{
		res++;
		n /= 10;
	}
	return (res);
}

char		*ft_itoa(int n)
{
	int			len;
	int			sign;
	unsigned	tmp;
	char		*res;

	if (n < 0)
		sign = 1;
	else if (n > 0)
		sign = 0;
	else
		return (zero_case());
	len = sign + calc_len(n);
	res = ft_strnew(len);
	if (!res)
		return (NULL);
	tmp = sign ? -n : n;
	while (len-- > sign)
	{
		res[len] = tmp % 10 + '0';
		tmp /= 10;
	}
	if (sign)
		res[0] = '-';
	return (res);
}
