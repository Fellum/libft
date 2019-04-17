/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleann <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 16:33:41 by jleann            #+#    #+#             */
/*   Updated: 2019/04/04 16:33:43 by jleann           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int			max;
	unsigned	res;

	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		res = -n;
	}
	else
		res = n;
	max = 1;
	while (res / max >= 10)
		max *= 10;
	while (max != 0)
	{
		ft_putchar_fd(res / max + '0', fd);
		res %= max;
		max /= 10;
	}
}
