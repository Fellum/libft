/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_double.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanhand <mcanhand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 18:40:40 by jleann            #+#    #+#             */
/*   Updated: 2019/06/20 18:21:07 by mcanhand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "large_arythmetics.h"
#include "floats.h"
#include "float_to_str.h"

unsigned	*fill_float_d(unsigned long mask, int exp, unsigned long mant)
{
	unsigned *cur;
	unsigned *res;

	cur = init_num(1);
	res = init_num(1);
	if (exp < 0)
	{
		while (exp++ < 0)
		{
			mul_dig_longnum(cur, 5, cur);
			mul_dig_longnum(res, 10, res);
		}
		sum_longnum(res, cur, res);
	}
	else
		mask = (unsigned)exp > 22 ? 0 : mask >> (unsigned)exp;
	while (mask)
	{
		mul_dig_longnum(cur, 5, cur);
		mul_dig_longnum(res, 10, res);
		mant & mask ? sum_longnum(res, cur, res) : mant;
		mask = mask >> 1U;
	}
	free(cur);
	return (res);
}

unsigned	*fill_integer_d(unsigned long mask, int exp, unsigned long mant)
{
	unsigned	*res;
	unsigned	*pow2;
	int			cur;

	res = init_num(0);
	pow2 = init_num(1);
	if (exp >= 0)
	{
		mask = mask >> (exp > D_MANT ? D_MANT - 1 : (exp - 1));
		cur = exp - D_MANT;
		while (cur-- > 0)
			mul_dig_longnum(pow2, 2, pow2);
		while (mask <= D_MASK && exp > 0)
		{
			if (mant & mask)
				sum_longnum(res, pow2, res);
			mul_dig_longnum(pow2, 2, pow2);
			mask = mask << 1U;
			exp--;
		}
		sum_longnum(res, pow2, res);
	}
	free(pow2);
	return (res);
}

char		*make_double(double val, int precision)
{
	t_double_cast		tmp;
	unsigned			*integer_part;
	unsigned			*float_part;
	char				*res;

	res = NULL;
	tmp.f = val;
	integer_part = fill_integer_d(D_MASK, tmp.parts.exp - 1023, tmp.parts
			.mant);
	float_part = fill_float_d(D_MASK, tmp.parts.exp - 1023, tmp.parts.mant);
	apply_precision(integer_part, float_part, precision);
	append_string(&res, int_part_to_str(integer_part));
	append_string(&res, float_part_to_str(float_part, precision));
	free(integer_part);
	free(float_part);
	return (res);
}
