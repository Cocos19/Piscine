/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mprofett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 14:35:15 by mprofett          #+#    #+#             */
/*   Updated: 2022/07/10 18:00:59 by mprofett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_sort_int_tab(int *tab, int size)
{
	int	buffer;
	int	buffer2;
	int	counter;

	counter = 1;
	while (counter < size)
	{
		if (tab[counter - 1] > tab[counter])
		{
			buffer = tab[counter - 1];
			buffer2 = tab[counter];
			tab[counter] = buffer;
			tab[counter - 1] = buffer2;
			counter = 1;
		}
		else
			counter++;
	}
}
/*
int	main(void)
{
	int	tab[6] = {1, 4, 3, -18, 2, 4};

	printf("%d", tab[0]);
	printf("%d", tab[1]);
	printf("%d", tab[2]);
	printf("%d", tab[3]);
	printf("%d", tab[4]);
	printf("%d", tab[5]);
	ft_sort_int_tab(tab, 6);
	printf("%d", tab[0]);
	printf("%d", tab[1]);
	printf("%d", tab[2]);
	printf("%d", tab[3]);
	printf("%d", tab[4]);
	printf("%d", tab[5]);
	return (0);
}*/
