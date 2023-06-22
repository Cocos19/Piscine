/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbarbe <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 13:01:13 by tbarbe            #+#    #+#             */
/*   Updated: 2022/07/26 19:57:06 by tbarbe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/bsq.h"
#include <unistd.h>

void	free_strs(char **strs)
{
	free_strtab(strs);
	free(strs);
}

int	run(char *src)
{
	t_grid	grid;
	char	*str;

	str = ft_copyfile(src);
	if (str == 0)
		return (1);
	grid = ft_initgrid(str);
	if (grid.size.y == 0)
		return (1);
	if (ft_checkgrid(&grid, str) == 0)
	{
		free(str);
		return (1);
	}
	grid.cels = ft_loadcels(grid, str);
	ft_celsfindsizes(&grid);
	ft_writesquare(&grid);
	ft_putgrid(grid);
	free(grid.cels);
	free(str);
	return (0);
}

int	main(int argc, char **argv)
{
	int	i;
	int	check;

	i = 1;
	check = 0;
	while (i <= argc)
	{
		check = run(argv[i]);
		if (check == 1)
			write(1, "map error\n", 10);
		write(1, "\n", 1);
		i++;
	}
	system("leaks bsq");
	return (0);
}
