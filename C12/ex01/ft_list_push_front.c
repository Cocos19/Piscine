/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_front.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mprofett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 17:05:29 by mprofett          #+#    #+#             */
/*   Updated: 2022/07/28 17:05:31 by mprofett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>
#include <stdio.h>

void    ft_list_push_front(t_list **begin_list, void *data)
{
    t_list  *new_elem;

    new_elem = malloc(sizeof(t_list));
    new_elem->next = *begin_list.next;
    new_elem->data = data;
    begin_list.next = new_elem;
}

int main(void)
{
    void    *data;
    int     value;
    t_list  elem1;
    t_list  elem2;
    t_list  elem3;
    t_list  *begin;

    begin = &elem1;
    elem1.next = &elem2;
    elem2.next = &elem3;
    elem3.next = NULL;

    value = 5;
    data = &value;
    printf("%p\n", data);
    ft_list_push_front(&begin, data);
    printf("%p\n", data);
    return (0);
}
