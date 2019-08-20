/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_after_num.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanhand <mcanhand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 19:31:59 by mcanhand          #+#    #+#             */
/*   Updated: 2019/06/20 14:43:16 by mcanhand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "conversions.h"
#include "libft.h"
#include "ft_list.h"

int		ft_after_num(t_params ft, int str_len, t_list *lst, int hash)
{
	char	*str;
	int		i;
	int		spaces;

	i = 0;
	spaces = ft.field_width - ((ft.precision > str_len) ?
				ft.precision : str_len) - hash;
	if ((ft.flags & MINUS_FLAG) && (ft.field_width > ft.precision))
		if (spaces + 1 > 1)
		{
			str = fill_with_chars(spaces, ' ');
			create_node(str, spaces + 1, lst);
		}
	return (i);
}
