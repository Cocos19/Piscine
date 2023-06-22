/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mprofett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 18:06:00 by mprofett          #+#    #+#             */
/*   Updated: 2022/07/08 12:43:23 by mprofett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_nbre(int nbre)
{
	char	dizaine;
	char	unite;
	int		n;

	n = nbre;
	dizaine = n / 10 + 48;
	unite = n % 10 + 48;
	write(1, &dizaine, 1);
	write(1, &unite, 1);
}

void	ft_print_comb2(void)
{
	int	nbr1;
	int	nbr2;

	nbr1 = 0;
	nbr2 = 2;
	print_nbre(0);
	write(1, " ", 1);
	print_nbre(1);
	while (nbr1 < 99)
	{
		while (nbr2 < 100)
		{
			write(1, ", ", 2);
			print_nbre(nbr1);
			write(1, " ", 1);
			print_nbre(nbr2);
			nbr2++;
		}	
	nbr1++;
	nbr2 = nbr1 + 1;
	}
}
/*
int	main()
{
	ft_print_comb2();
	return 0;
}*/
