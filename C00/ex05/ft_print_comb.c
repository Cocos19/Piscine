/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mprofett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 15:24:22 by mprofett          #+#    #+#             */
/*   Updated: 2022/07/09 18:05:07 by mprofett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h> 

void	print_number(int c, int d, int u)
{
	char	centaine;
	char	dizaine;
	char	unite;

	centaine = c + 48;
	dizaine = d + 48;
	unite = u + 48;
	if (c != 0 || d != 1 || u != 2)
	{
		write(1, ", ", 2);
	}
	write(1, &centaine, 1);
	write(1, &dizaine, 1);
	write(1, &unite, 1);
}

void	ft_print_comb(void)
{
	int	c;
	int	d;
	int	u;

	c = 0;
	d = 1;
	u = 2;
	while (c < 10)
	{
		while (d < 10)
		{
			while (u < 10)
			{
				print_number(c, d, u);
				u++;
			}
			d++;
			u = d + 1;
		}
		c++;
		d = c + 1;
		u = d + 1;
	}
}

/*
int	main()
{
	ft_print_comb();
	return 0;
}*/
