/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_foreach.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mprofett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 13:02:16 by mprofett          #+#    #+#             */
/*   Updated: 2022/07/25 19:41:33 by mprofett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <unistd.h>
#include <stdio.h>

void    print_number(int nbr)
{
    char n;

    n = nbr + 48;
    write(1, &n, 1);
}

void	ft_putnbr(int nb)
{
	if (nb < 0)
	{
		write(1, "-", 1);
		if (nb == -2147483648)
		{
			print_number(2);
			nb = nb + 2000000000;
		}
		nb = -nb;
	}
	if (nb < 10)
	{
		print_number(nb);
	}
	else
	{
		if (nb >= 10)
		{
			ft_putnbr(nb / 10);
			ft_putnbr(nb % 10);
		}
	}
}*/

void	ft_foreach(int *tab, int length, void (*f)(int))
{
	int	i;

	i = 0;
	while (i < length)
	{
		(*f)(tab[i]);
		i++;
	}
}

/*int main(void)
{
    void    (*ptr_putnbr)(int);
    int     tab[5] = {1, 2, 3, 4, 5};
    int     length;

    length = 5;
    ptr_putnbr = &ft_putnbr;
    ft_foreach(tab, length, ptr_putnbr);
    return (0);
}*/
