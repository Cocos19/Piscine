/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putresult.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbarbe <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 18:53:12 by tbarbe            #+#    #+#             */
/*   Updated: 2022/07/26 19:41:13 by tbarbe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/bsq.h"

void	ft_writesquare(t_grid *grid)
{
	int	x;
	int	y;

	x = grid->result.pos.x;
	y = grid->result.pos.y;
	while (y < grid->result.pos.y + grid->result.size)
	{
		while (x < grid->result.pos.x + grid->result.size)
		{
			ft_settype(grid, x, y, grid->types.full);
			x++;
		}	
		x = grid->result.pos.x;
		y++;
	}
}

void	ft_putgrid(t_grid grid)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < grid.size.y)
	{
		while (x < grid.size.x)
		{
			ft_putchar(ft_gettype(grid, x, y));
			x++;
		}
		ft_putchar('\n');
		x = 0;
		y++;
	}
}
