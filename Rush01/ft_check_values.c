/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info_on_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mprofett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 22:11:43 by mprofett          #+#    #+#             */
/*   Updated: 2022/07/17 22:11:46 by mprofett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_if_col_correct(int *map, int *views, int col)
{
	int	i;

	i = 1;
	if (map[col + 11] == 4)
		i++;
	if (map[col + 3] > map[col - 1])
		i++;
	if (map[col + 7] > map[col + 3] && map[col + 7] > map[col - 1])
		i++;
	if (views[col - 1] != i)
		return (0);
	i = 1;
	if (map[col - 1] == 4)
		i++;
	if (map[col + 7] > map[col + 11])
		i++;
	if (map[col + 3] > map[col + 7] && map[col + 3] > map[col + 11])
		i++;
	if (views[col + 3] != i)
		return (0);
	return (1);
}

int	check_if_row_correct(int *map, int *views, int row)
{
	int	i;

	i = 1;
	if (map[(row - 1) * 4 + 3] == 4)
		i++;
	if (map[(row - 1) * 4 + 1] > map[(row - 1) * 4])
		i++;
	if (map[(row - 1) * 4 + 2] > map[(row -1) * 4 + 1]
		&& map[(row - 1) * 4 + 2] > map[(row - 1) * 4])
		i++;
	if (views[row + 7] != i)
		return (0);
	i = 1;
	if (map[(row - 1) * 4] == 4)
		i++;
	if (map[(row - 1) * 4 + 2] > map[(row - 1) * 4 + 3])
		i++;
	if (map[(row - 1) * 4 + 1] > map[(row -1) * 4 + 2]
		&& map[(row - 1) * 4 + 1] > map[(row - 1) * 4 + 3])
		i++;
	if (views[row + 11] != i)
		return (0);
	return (1);
}

int	check_if_col_have_two_digit_missing(int *map, int col)
{
	int	i;
	int	count;

	i = col - 1;
	count = 0;
	while (i <= (col + 11))
	{
		if (map[i] != 0)
			count++;
		i += 4;
	}
	if (count == 2)
		return (1);
	return (0);
}

int	check_if_row_have_two_digit_missing(int *map, int row)
{
	int	i;
	int	count;

	i = (row - 1) * 4;
	count = 0;
	while (i <= (((row - 1) * 4) + 3))
	{
		if (map[i] != 0)
			count++;
		i++;
	}
	if (count == 2)
		return (1);
	return (0);
}
