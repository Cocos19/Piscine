/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_elem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mprofett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 14:52:20 by mprofett          #+#    #+#             */
/*   Updated: 2022/07/28 14:52:21 by mprofett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdio.h>
#include <stdlib.h>

t_list  *ft_create_elem(void *data)
{
    t_list  *result;

    result = malloc(sizeof(t_list));
    if (!result)
        return (NULL);
    result->next = NULL;
    result->data = data;
    return(result);
}

int main(void)
{
    void    *data;
    int test;
    t_list  *result;

    test = 0;
    data = &test;
    result = ft_create_elem(data);
    printf("%p", result->data);
    return (0);
}