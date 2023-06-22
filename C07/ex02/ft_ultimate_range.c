/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mprofett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 17:19:18 by mprofett          #+#    #+#             */
/*   Updated: 2022/07/21 12:50:36 by mprofett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;
	int	range_size;

	i = 0;
	range_size = max - min;
	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	*range = malloc((sizeof(int) * range_size) + 1);
	if (!*range)
		return (-1);
	else
	{	
		while (i < range_size)
		{
			(*range)[i] = min;
			i++;
			min++;
		}
	}
	return (range_size);
}

/*int	main(void)
{
	int	**ptr_on_tab = NULL;
	int *tab;
	int	range_size;
	int	i;

	ptr_on_tab = &tab;
	i = 0;
	range_size = ft_ultimate_range(ptr_on_tab, 4, 8);
	if (range_size <= 0)
		printf("Pas de chance, il y a eu une erreur : %d", range_size);
	else
	{	
		printf("La range est de: %d\nVoici les elements du tableau: ", range_size);
		while (tab[i])
		{
			printf("%d", tab[i]);
			i++;
		}
	}
	return (0);
}*/
