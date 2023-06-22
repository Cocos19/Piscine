/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_number.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mprofett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 16:12:52 by mprofett          #+#    #+#             */
/*   Updated: 2022/07/23 16:12:58 by mprofett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

void	ft_putstr(char *str);

void	print_h(char *n, char **u, char *h)
{
	ft_putstr(u[n[0] - 48]);
	write(1, " ", 1);
	ft_putstr(h);
	if (n[1] != '0' || n[2] != '0')
		write(1, " ", 1);
}

void	print_hundreds(char *n, char **u, char **teens, char **tens, char *h)
{
	if (n[0] != '0')
		print_h(n, u, h);
	if (n[1] != '0' || n[2] != '0')
	{
		if (n[1] == '0')
			ft_putstr(u[n[2] - 48]);
		else if (n[1] == '1')
			ft_putstr(teens[n[2] - 48]);
		else
		{
			ft_putstr(tens[n[1] - 48]);
			if (n[2] != '0')
			{
				write(1, " ", 1);
				ft_putstr(u[n[2] - 48]);
			}
		}
	}
}

void	print_range(char *str)
{
	write(1, " ", 1);
	ft_putstr(str);
	write(1, " ", 1);
}

void	init_buffer(char *buf, char zero, char one, char two)
{
	buf[0] = zero;
	buf[1] = one;
	buf[2] = two;
}
