/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleann <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 13:33:21 by jleann            #+#    #+#             */
/*   Updated: 2019/04/17 19:55:39 by jleann           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GET_NEXT_LINE_H
# define FT_GET_NEXT_LINE_H
# include "libft.h"

# define BUFF_SIZE 100
# define GNL_END_OF_FILE 0
# define GNL_ERROR -1
# define GNL_SUCCESS 1
# define GNL_MAX_FD 10240

int					ft_get_next_line(const int fd, char **line);

#endif
