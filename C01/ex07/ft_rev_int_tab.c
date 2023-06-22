/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mprofett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 14:35:15 by mprofett          #+#    #+#             */
/*   Updated: 2022/07/10 15:14:03 by mprofett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
//#include <stdio.h>

void	ft_rev_int_tab(int *tab, int size)
{
	int	buffer;
	int	counter;
	int	i;

	counter = 0;
	i = size - 1;
	while (counter < size / 2)
	{
		buffer = tab[i];
		tab[i] = tab[counter];
		tab[counter] = buffer;
		counter++;
		i--;
	}
}

/*
int	main(void)
{
	int tab[4] = {1, 2, 3, 4};
	printf("%d", tab[0]);
	printf("%d", tab[1]);
	printf("%d", tab[2]);
	ft_rev_int_tab(tab, 4);
	printf("%d", tab[0]);
	printf("%d", tab[1]);
	printf("%d", tab[2]);
	printf("%d", tab[3]);

	return (0);
}*/
