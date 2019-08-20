/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   large_arythmetics.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanhand <mcanhand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 19:21:57 by jleann            #+#    #+#             */
/*   Updated: 2019/06/20 17:51:45 by mcanhand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LARGE_ARYTHMETICS_H
# define LARGE_ARYTHMETICS_H
# include <stdlib.h>
# include <unistd.h>

# define MASS_LEN 2000
# define BASE 1000000000U

unsigned	*init_num(unsigned num);
void		sum_longnum(unsigned *left, unsigned *right, unsigned *dst);
void		mul_dig_longnum(unsigned *num, unsigned char dig, unsigned *dst);
void		div_10_longnum(unsigned *num);
void		apply_precision(unsigned *f_part, unsigned *i_part, int precision);
int			calc_uint_len(unsigned num);
int			get_first_dig(unsigned num);
#endif
