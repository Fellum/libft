/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleann <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 18:50:39 by jleann            #+#    #+#             */
/*   Updated: 2019/04/05 18:50:40 by jleann           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void    ft_lstadd(t_list *alst, t_list_node *new)
{
    if (alst->begin)
    {
        new->next = alst->begin;
        alst->begin = new;
    }
    else
    {
        alst->begin = new;
        alst->end = new;
    }
    alst->len += 1;
}
