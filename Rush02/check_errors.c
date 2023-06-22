/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mprofett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 18:22:17 by mprofett          #+#    #+#             */
/*   Updated: 2022/07/24 18:22:19 by mprofett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	check_if_unsigned_int(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (0);
		i++;
	}
	return (1);
}

int	check_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		if (tab[i] != NULL)
			return (1);
		i++;
	}
	return (0);
}

int	check_tabs(char **u, char **teens, char **tens, char **range)
{
	int	check;

	check = 0;
	tens[0] = tens[2];
	tens[0] = tens[2];
	check += check_tab(u);
	check += check_tab(teens);
	check += check_tab(tens);
	check += check_tab(range);
	if (check != 4)
	{
		write(1, "Dict Error\n", 11);
		return (0);
	}
	return (1);
}

int	check_errors(int argc, char **argv)
{
	if (argc == 2)
	{
		if (check_if_unsigned_int(argv[1]) == 0)
		{
			write(1, "Error\n", 6);
			return (0);
		}
	}
	if (argc == 3)
	{
		if (check_if_unsigned_int(argv[2]) == 0)
		{
			write(1, "Error\n", 6);
			return (0);
		}
	}
	return (1);
}
