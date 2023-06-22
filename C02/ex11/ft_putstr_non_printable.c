/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mprofett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 09:37:04 by mprofett          #+#    #+#             */
/*   Updated: 2022/07/12 17:53:29 by mprofett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
//#include <stdio.h>

void	print_hexa(char c)
{
	char	d;
	char	a;

	d = c / 16;
	a = c % 16;
	if (a >= 10 && a <= 16)
		a += 87;
	if (d >= 10 && d <= 16)
		d += 87;
	if (d < 10)
		d += 48;
	write(1, "\\", 1);
	write(1, &d, 1);
	write(1, &a, 1);
}

void	ft_putstr_non_printable(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] <= 31)
		{
			print_hexa(str[i]);
		}
		else
		{
			write(1, &str[i], 1);
		}
	i++;
	}
}

/*int	main(void)
{
	char	str[30] = "Coucou\ntu vas bien ?";
	char c;
	c = 127;
	printf("test");
	printf("%c", c);
	printf("test");
	c = 0;
	ft_putstr_non_printable(str);
	return (0);
}*/
