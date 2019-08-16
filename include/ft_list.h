/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleann <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 20:45:49 by jleann            #+#    #+#             */
/*   Updated: 2019/04/17 20:07:53 by jleann           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIST_H
# define FT_LIST_H
# include <stdlib.h>
# include <string.h>

typedef	struct			s_list_node
{
    void			    *content;
    size_t			    content_size;
    struct s_list_node	*next;
}						t_list_node;

typedef struct          s_list
{
    t_list_node *begin;
    t_list_node *end;
    size_t      len;
}                       t_list;

t_list                  *ft_lstinit();
t_list_node				*ft_lstnew_node(void *content, size_t content_size);
void					ft_lstadd(t_list *alst, t_list_node *new);
void					ft_lstaddend(t_list *alst, t_list_node *new);
void					*ft_lstfind(t_list *alst, void *content,
                                    int (*f)(void *, void *));

#endif
