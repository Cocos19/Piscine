/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mprofett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 14:17:38 by mprofett          #+#    #+#             */
/*   Updated: 2022/07/16 10:48:27 by mprofett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
//#include <stdio.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	check_errors(char *base, int base_length)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	if (base[0] == '\0' || base[1] == '\0')
		return (0);
	while (i < base_length - 1)
	{	
		j = i + 1;
		while (base[j])
		{	
			if (base[i] == base[j] || base[i] == '+' || base[i] == '-'
				|| base[j] == '+' || base[j] == '-' || base[i] <= 32
				|| base[i] == 127 || base[j] <= 32 || base[j] == 127)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int				base_length;
	unsigned int	n;

	base_length = 0;
	while (base[base_length])
		base_length++;
	if (check_errors(base, base_length) > 0)
	{
		if (nbr < 0)
		{
			ft_putchar('-');
			n = nbr * -1;
		}
		else
			n = nbr;
		if ((n / base_length) != 0)
			ft_putnbr_base((n / base_length), base);
		ft_putchar(base[n % base_length]);
	}
}

/*int	main(void)
{
	int		test;
	char	base[5] = {'0', '1', '2', '3'};

	test = -2156466;
	ft_putnbr_base(test, base);
	return (0);
}*/
