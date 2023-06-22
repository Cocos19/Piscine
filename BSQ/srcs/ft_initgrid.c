/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initgrid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbarbe <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 13:13:33 by tbarbe            #+#    #+#             */
/*   Updated: 2022/07/26 19:38:24 by tbarbe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/bsq.h"

t_cel	*ft_loadcels(t_grid grid, char *str)
{
	t_cel	*cels;
	int		x;
	int		y;
	char	**lines;

	lines = ft_split(str, "\n");
	cels = malloc(sizeof(t_cel) * (grid.size.x * grid.size.y));
	if (!cels)
		exit(1);
	x = 0;
	y = 0;
	while (y < grid.size.y)
	{
		while (x < grid.size.x)
		{	
			cels[y * grid.size.x + x].pos.x = x;
			cels[y * grid.size.x + x].pos.y = y;
			cels[y * grid.size.x + x].type = lines[y + 1][x];
			x++;
		}
		x = 0;
		y++;
	}
	free_strs(lines);
	return (cels);
}

int	ft_checkline(t_grid grid, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != grid.types.empty && str[i] != grid.types.obst)
			return (0);
		i++;
	}
	return (1);
}

int	ft_checkgrid(t_grid *grid, char	*str)
{
	char	**lines;
	int		width;
	int		i;

	lines = ft_split(str, "\n");
	i = 1;
	width = 0;
	while (lines[i])
	{
		if (width != 0 && ft_strlen(lines[i]) != width)
		{
			free_strs(lines);
			return (0);
		}
		width = ft_strlen(lines[i]);
		if (ft_checkline(*grid, lines[i]) == 0)
		{
			free_strs(lines);
			return (0);
		}
		i++;
	}
	grid->size.x = width;
	free_strs(lines);
	return (1);
}

t_grid	ft_inittypes(t_grid grid, char *str)
{
	int	len;

	len = ft_strlen(str);
	grid.types.empty = str[len - 3];
	grid.types.obst = str[len - 2];
	grid.types.full = str[len - 1];
	return (grid);
}

t_grid	ft_initgrid(char *str)
{
	t_grid	grid;
	int		len;
	int		size;
	char	**lines;

	lines = ft_split(str, "\n");
	size = ft_atoi(lines[0]);
	len = ft_strlen(lines[0]);
	if (size <= 0 || len < 4 || lines[0][len - 1] < ' '
		|| lines[0][len - 2] < ' ' || lines[0][len - 3] < ' '
		|| lines[0][len - 3] == lines[0][len - 2]
		|| lines[0][len - 3] == lines[0][len - 1]
		|| lines[0][len - 2] == lines[0][len - 1])
	{
		grid.size.y = 0;
		free_strs(lines);
		return (grid);
	}
	grid.result.size = 0;
	grid.size.y = size;
	grid = ft_inittypes(grid, lines[0]);
	free_strs(lines);
	return (grid);
}
