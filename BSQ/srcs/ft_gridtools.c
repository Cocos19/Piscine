/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gridtools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbarbe <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 16:21:28 by tbarbe            #+#    #+#             */
/*   Updated: 2022/07/26 19:35:30 by tbarbe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/bsq.h"

char	ft_gettype(t_grid	grid, int x, int y)
{
	return (grid.cels[y * grid.size.x + x].type);
}

void	ft_settype(t_grid	*grid, int x, int y, char c)
{
	grid->cels[y * grid->size.x + x].type = c;
}

int	ft_goodzone(t_grid grid, t_pos pos)
{
	int	x;
	int	y;

	x = pos.x;
	y = pos.y;
	while (y < pos.y + grid.result.size + 1)
	{
		while (x < pos.x + grid.result.size + 1)
		{
			if (ft_gettype(grid, x, y) == grid.types.obst
				|| grid.result.size >= grid.size.x - pos.x
				|| grid.result.size >= grid.size.y - pos.y)
				return (0);
			x++;
		}
		x = pos.x;
		y++;
	}
	return (1);
}

void	ft_celfindsize(t_grid *grid, t_pos pos)
{
	while (ft_goodzone(*grid, pos))
	{
		grid->result.pos = pos;
		grid->result.size++;
	}
}

void	ft_celsfindsizes(t_grid	*grid)
{
	int	i;

	i = 0;
	while (i < grid->size.x * grid->size.y)
	{
		ft_celfindsize(grid, grid->cels[i].pos);
		i++;
	}
}
