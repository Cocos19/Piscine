/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mprofett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 12:51:21 by mprofett          #+#    #+#             */
/*   Updated: 2022/07/14 13:58:02 by mprofett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{	
		ft_putchar(str[i]);
		i++;
	}
}

int	lenght_strtab(char **strtab)
{
	int	i;

	i = 0;
	while (strtab[i])
		i++;
	return (i);
}

void	print_rev_strtab(int argc, char **strtab)
{
	int	i;

	i = argc - 1;
	if (i > 0)
		ft_putstr(strtab[i]);
	i--;
	while (i > 0)
	{	
		write(1, "\n", 1);
		ft_putstr(strtab[i]);
		i--;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 1)
		return (0);
	print_rev_strtab(argc, argv);
	write(1, "\n", 1);
	return (0);
}
