/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _ft_printf.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleann <jleann@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 19:28:38 by jleann            #+#    #+#             */
/*   Updated: 2019/06/21 15:57:22 by jleann           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF__H
# define FT_PRINTF__H

# include <stdarg.h>
# include <string.h>
# include <unistd.h>
# include <stdarg.h>
# include "ft_list.h"

# define HASH_FLAG 1U
# define PLUS_FLAG 2U
# define MINUS_FLAG 4U
# define SPACE_FLAG 8U
# define ZERO_FLAG 16U
# define LO_FLAG 32U
# define LLO_FLAG 64U
# define H_FLAG 128U
# define HH_FLAG 256U
# define L_FLAG 512U
# define Z_FLAG 1024U
# define J_FLAG 2048U

typedef struct		s_params
{
	int				precision;
	int				field_width;
	unsigned		flags;
	char			conversion;
}					t_params;

int					get_field_width(const char **format, va_list *args);
int					get_flags(const char **format);
int					get_precision(const char **format, va_list *args);
unsigned			get_conv_flags(const char **format);
char				get_conversion(const char **format);

int					print_conversion(t_params formating, va_list *args,
									t_list *lst);
int					ft_before_num(t_params ft, int str_len, int hash,
									t_list *lst);
int					ft_after_num(t_params ft, int str_len, t_list *lst,
								int hash);
char				*make_double(double val, int precision);
char				*make_ldouble(long double val, int precision);
int					create_node(void *str, size_t len, t_list *lst);
char				*ft_itoa_base(long long n, int bs, int up);
char				*ft_itoa_base_hex_long(unsigned long long n,
											int base, int upr);

#endif
