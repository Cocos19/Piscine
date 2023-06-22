/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_numbers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mprofett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 18:33:45 by mprofett          #+#    #+#             */
/*   Updated: 2022/07/27 18:33:47 by mprofett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_number(int nb)
{
	char	n;

	n = nb + 48;
	write(1, &n, 1);
}

void	ft_putnbr(int nb)
{
	if (nb < 0)
	{
		write(1, "-", 1);
		if (nb == -2147483648)
		{
			write(1, "2", 1);
			nb = -147483648;
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
}

int	ft_atoi(char *str)
{
	int	i;
	int	result;
	int	sign;

	i = 0;
	sign = 1;
	while (str[i] == ' ' || str[i] == '\f' || str[i] == '\n'
		|| str[i] == '\r' || str[i] == '\t' || str[i] == '\v')
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	result = 0;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		result *= 10;
		result += (str[i] - 48);
		i++;
	}
	return (result * sign);
}
