/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleann <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 18:50:39 by jleann            #+#    #+#             */
/*   Updated: 2019/04/05 18:50:40 by jleann           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_lstaddend(t_list *alst, t_list_node *new)
{
    if (alst->end)
    {
        alst->end->next = new;
        alst->end = new;
    }
    else
    {
        alst->end = new;
        alst->begin = new;
    }
    alst->len += 1;
}
