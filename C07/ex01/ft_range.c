/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mprofett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 16:56:18 by mprofett          #+#    #+#             */
/*   Updated: 2022/07/21 12:56:53 by mprofett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*tab;
	int	i;
	int	range;

	i = 0;
	range = max - min;
	if (min >= max)
		return (NULL);
	tab = (int *)malloc(sizeof(int) * range);
	if (!tab)
		return (NULL);
	while (i < range)
	{
		tab[i] = min;
		i++;
		min++;
	}
	return (tab);
}

/*int	main(void)
{
	int	*tab;
	int	i;

	i = 0;
	tab = ft_range(5, 8);
	if (tab != 0)
	{
		while (tab[i])
		{	
			printf("%d", tab[i]);
			i++;
		}	
	}
	else
		printf("%s", "Pas de chance, le pointeur etait nul");
	return (0);
}*/
