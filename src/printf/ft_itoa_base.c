/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanhand <mcanhand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 12:34:08 by mcanhand          #+#    #+#             */
/*   Updated: 2019/06/20 17:41:11 by mcanhand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	intlen(long long int n, int base)
{
	size_t len;

	len = 0;
	while (n)
	{
		len++;
		n /= base;
	}
	return (len);
}

char			*ft_itoa_base(long long n, int bs, int up)
{
	char				*res;
	int					len;
	char				*barr;
	int					i;
	unsigned long long	tmp;

	i = 0;
	if (n == 0)
		return (ft_strdup("0"));
	barr = up ? "0123456789ABCDEF" : "0123456789abcdef";
	len = intlen(n, bs);
	res = ft_strnew(len);
	if (!res)
		return (NULL);
	i = len;
	tmp = n > 0 ? n : -n;
	while (len--)
	{
		res[--i] = barr[(tmp % bs)];
		tmp /= bs;
	}
	return (res);
}
