/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mprofett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 13:44:27 by mprofett          #+#    #+#             */
/*   Updated: 2022/07/21 13:44:29 by mprofett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <stdlib.h>
#include <stdio.h>

int get_str_size(int i, char **strs)
{
	int j;
	int	size;

	j = 0;
	size = (int)malloc(sizeof(int));
	size = 0;
	while (strs[i][j])
	{
		size++;
		j++;
	}
	return (size + 1);
}

char	*fill_str(int i, char **strs)
{
	char	*result;
	int		j;

	j = 0;
	result = (char *)malloc(sizeof(char) * get_str_size(i, strs));
	while (strs[i][j])
	{	
		result[j] = strs[i][j];
		j++;
	}
	result[j] = '\0';
	return (result);
}

struct s_stock_str *ft_strs_to_tab(int ac, char **av)
{
	t_stock_str	*result;
	int			size;

	size = 0;
	result = (t_stock_str *)malloc(sizeof(t_stock_str) * ac + 1);
	if (!result)
		return (NULL);
	while (size < ac)
	{	
		result[size].str = fill_str(size, av);
		result[size].copy = fill_str(size, av);
		result[size].size = get_str_size(size, av) - 1;
		size++;
	}
	result[size].str = "\0";
	return (result);
}

/*int main(int argc, char **argv)
{
	t_stock_str *par;
	int			i;
	
	i = 0;
	par = ft_strs_to_tab(argc, argv);
	printf("%s\n", par[3].str);
	return (0);
}*/