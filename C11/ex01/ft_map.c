/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mprofett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 14:51:45 by mprofett          #+#    #+#             */
/*   Updated: 2022/07/25 19:42:45 by mprofett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
//#include <stdio.h>

/*int	mult_by_two(int nbr)
{	
	return (nbr * 2);
}
*/
int	*ft_map(int *tab, int length, int (*f)(int))
{
	int	*result;
	int	i;

	i = 0;
	result = (int *)malloc(sizeof(int) * length);
	if (!result)
		return (NULL);
	while (i < length)
	{
		result[i] = (*f)(tab[i]);
		i++;
	}
	i = 0;
	return (result);
}

/*int main(void)
{
	int (*ptr_mult)(int);
	int tab[5] = {1, 2, 3, 4, 5};
	int *result;
	int	i;

	i = 0;
	ptr_mult = &mult_by_two;
	result = ft_map(tab, 5, ptr_mult);
	while (!(result[i] == 0))
	{
		printf("%d\n", result[i]);
		i++;
	}
	return (0);
}*/
