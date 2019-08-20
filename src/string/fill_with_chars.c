/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_with_chars.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanhand <mcanhand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 19:42:20 by mcanhand          #+#    #+#             */
/*   Updated: 2019/06/20 18:14:54 by mcanhand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*fill_with_chars(int num, char c)
{
	char *str;

	if (num > 0)
	{
		if (!(str = ft_strnew(num)))
			return (NULL);
		ft_memset(str, c, num);
		return (str);
	}
	return (NULL);
}
