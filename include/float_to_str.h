/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_to_str.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanhand <mcanhand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 19:27:55 by mcanhand          #+#    #+#             */
/*   Updated: 2019/06/19 19:28:05 by mcanhand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FLOAT_TO_STR_H
# define FLOAT_TO_STR_H

void	append_string(char **res, char *str);
char	*float_part_to_str(unsigned *longnum, int precision);
char	*int_part_to_str(unsigned *longnum);
#endif
