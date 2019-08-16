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
# include <unistd.h>
# include <string.h>

typedef	struct			s_list
{
    void			*content;
    size_t			content_size;
    struct s_list	*next;
}						t_list;

t_list					*ft_lstnew(void const *content, size_t content_size);
void					ft_lstadd(t_list **alst, t_list *new);
t_list					*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void					ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void					ft_lstiter(t_list *lst, void (*f)(t_list *elem));
void					ft_lstdelone(t_list **alst, void (*del)(void*,
                                                                size_t));
size_t					ft_lstlen(t_list *lst);
char					*ft_lsttostr(t_list *lst);
void					ft_lstaddend(t_list **alst, t_list *new);
void					*ft_lstat(t_list *alst, size_t at);
void					*ft_lstfind(t_list *alst, void *content,
                                    int (*f)(void *, void *));

#endif
