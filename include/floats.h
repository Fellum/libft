/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floats.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanhand <mcanhand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 19:28:10 by mcanhand          #+#    #+#             */
/*   Updated: 2019/06/19 19:28:25 by mcanhand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_FLOAT_FLOATS_H
# define PRINT_FLOAT_FLOATS_H

# define F_MANT 23
# define D_MANT 52
# define LD_MANT 63

typedef union			u_double_cast
{
	double				f;
	struct
	{
		unsigned long	mant : D_MANT;
		unsigned long	exp : 11;
		unsigned int	sign : 1;
	}					parts;
}						t_double_cast;

typedef union			u_ldouble_cast{
	long double			f;
	struct
	{
		unsigned long	mant : LD_MANT;
		unsigned long	exp : 15;
		unsigned int	sign : 1;
	}					parts;
}						t_ldouble_cast;

# define F_MASK 0x00400000
# define D_MASK 0x0008000000000000
# define LD_MASK 0x4000000000000000
#endif
