/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vdprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanhand <mcanhand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 15:18:31 by jleann            #+#    #+#             */
/*   Updated: 2019/06/20 15:01:53 by mcanhand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conversions.h"
#include "ft_list.h"
#include "ft_string.h"

static void		free_lst(t_list *lst)
{
	t_list_node	*tmp;

	while (lst->begin)
	{
		tmp = lst->begin->next;
		free(lst->begin->content);
		free(lst->begin);
		lst->begin = tmp;
	}
}

static int		print_arg(const char **format, va_list *args, t_list *lst)
{
	t_params	formating;

	(*format)++;
	formating.flags = get_flags(format);
	formating.field_width = get_field_width(format, args);
	formating.precision = get_precision(format, args);
	formating.flags |= get_conv_flags(format);
	formating.conversion = get_conversion(format);
	return (print_conversion(formating, args, lst));
}

static int		main_loop(const char *format, va_list *args, t_list *res_lst)
{
	const char	*tmp;
	t_list_node	*tmp_node;

	while (*format)
	{
		tmp = format;
		while (*tmp && *tmp != '%')
			tmp++;
		tmp_node = NULL;
		if (tmp - format && create_node(ft_strsub(format, 0, tmp - format),
				tmp - format + 1, res_lst) == -1)
			return (-1);
		format = tmp;
		if (*tmp == '%' && print_arg(&format, args, res_lst) == -1)
			return (-1);
	}
	return (0);
}

int				ft_vdprintf(int fd, const char *format, va_list *ap)
{
	t_list		res_lst;
	char		*tmp_str;
	int			res;

	res_lst.begin = NULL;
	res_lst.end = NULL;
	res_lst.len = 0;
	res = -1;
	if (main_loop(format, ap, &res_lst) == 0)
	{
		if ((tmp_str = ft_lst_to_str(&res_lst)))
		{
			res = write(fd, tmp_str, ft_calc_string_len(&res_lst));
			free(tmp_str);
		}
		free_lst(&res_lst);
	}
	else
		free_lst(&res_lst);
	return (res);
}
