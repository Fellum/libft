/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleann <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 13:33:15 by jleann            #+#    #+#             */
/*   Updated: 2019/04/13 13:33:17 by jleann           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_get_next_line.h"

char	*safe_append(char *left, char *right)
{
	if (!(right = ft_strjoin(left, right)))
		return (NULL);
	if (left)
		free(left);
	return (right);
}

int		read_loop(char **fds, int fd)
{
	char		*buff;
	int			res;

	if (!(buff = (char *)malloc(BUFF_SIZE + 1)))
		return (GNL_ERROR);
	while ((res = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[res] = 0;
		if (!(fds[fd] = safe_append(fds[fd], buff)))
		{
			free(buff);
			return (GNL_ERROR);
		}
		if (ft_strchr(buff, '\n'))
			break ;
	}
	free(buff);
	if (res == -1)
		return (GNL_ERROR);
	return (GNL_SUCCESS);
}

int		endl_found_case(char **fds, char **line, char *tmp)
{
	char *buff;

	*tmp++ = 0;
	if (!(*line = ft_strdup(*fds)))
		return (GNL_ERROR);
	if (*tmp)
	{
		buff = *fds;
		if (!(*fds = ft_strdup(tmp)))
			return (GNL_ERROR);
		free(buff);
	}
	else
	{
		free(*fds);
		*fds = NULL;
	}
	return (GNL_SUCCESS);
}

int		ft_get_next_line(const int fd, char **line)
{
	static char	*fds[GNL_MAX_FD];
	char		*tmp;

	if (fd < 0 || fd > GNL_MAX_FD || !line || BUFF_SIZE + 1 < 1)
		return (GNL_ERROR);
	if ((!fds[fd] || (fds[fd] && !(tmp = ft_strchr(fds[fd], '\n')))) &&
											read_loop(fds, fd) != GNL_SUCCESS)
		return (GNL_ERROR);
	if (fds[fd] && (tmp = ft_strchr(fds[fd], '\n')))
		return (endl_found_case(fds + fd, line, tmp));
	else if (!fds[fd])
		return (GNL_END_OF_FILE);
	*line = fds[fd];
	fds[fd] = NULL;
	return (GNL_SUCCESS);
}
