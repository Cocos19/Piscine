/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhouyet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 10:03:47 by jhouyet           #+#    #+#             */
/*   Updated: 2022/07/10 13:22:27 by mprofett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	print_line(int x, char out, char in)
{
	ft_putchar(out);
	if (x != 1)
	{
		x--;
		while (x > 1)
		{
			ft_putchar(in);
			x--;
		}
		ft_putchar(out);
	}
	ft_putchar('\n');
}

void	rush(int x, int y)
{
	print_line(x, 'o', '-');
	if (y != 1)
	{
		y--;
		while (y > 1)
		{
			print_line(x, '|', ' ');
			y--;
		}
		print_line(x, 'o', '-');
	}
}

