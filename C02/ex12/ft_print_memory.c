/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mprofett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 09:37:04 by mprofett          #+#    #+#             */
/*   Updated: 2022/07/11 10:00:41 by mprofett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_hexa(char c)
{
	char	d;
	char	a;

	d = c / 16;
	a = c % 16;
	if (a >= 10 && a <= 16)
		a += 87;
	write(1, "\\", 1);
	write(1, "n", 1);
	write(1, &d, 1);
	write(1, &a, 1);
}

void	ft_putstr_non_printable(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] <= 31 || str[i] == 127)
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

/*
int	main(void)
{
	int	a;
	void *ptra;

	ft_print_memory(ptra);
	return (0);
}*/
