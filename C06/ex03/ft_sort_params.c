/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mprofett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 13:58:52 by mprofett          #+#    #+#             */
/*   Updated: 2022/07/14 14:01:04 by mprofett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{	
		write(1, &str[i], 1);
		i++;
	}
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i])
	{	
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}

void	print_rev_strtab(int length, char **strtab)
{
	int	i;

	i = 1;
	ft_putstr(strtab[1]);
	i++;
	while (i < length)
	{
		write(1, "\n", 1);
		ft_putstr(strtab[i]);
		i++;
	}
}

void	ft_sort_char_tab(int length, char **strtab)
{	
	char	*buffer;
	int		i;
	int		j;

	i = 1;
	j = 1;
	while (i < length - 1)
	{
		j = i + 1;
		while (j < length)
		{
			if (ft_strcmp(strtab[i], strtab[j]) > 0)
			{
				buffer = strtab[i];
				strtab[i] = strtab[j];
				strtab[j] = buffer;
			}
		j++;
		}
	i++;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 1)
		return (0);
	ft_sort_char_tab(argc, argv);
	print_rev_strtab(argc, argv);
	write(1, "\n", 1);
	return (0);
}
