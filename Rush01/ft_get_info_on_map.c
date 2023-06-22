/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_info_on_map.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mprofett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 22:09:48 by mprofett          #+#    #+#             */
/*   Updated: 2022/07/17 22:09:51 by mprofett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	get_sum_of_two_digit_on_a_col(int *map, int col)
{
	int	i;
	int	a;
	int	b;

	a = 0;
	b = 0;
	i = col - 1;
	while (i <= (col + 11))
	{
		if (map[i] != 0 && b == 0 && a > 0)
			b = map[i];
		if (map[i] != 0 && a == 0)
			a = map[i];
		i += 4;
	}
	return (a + b);
}

int	get_sum_of_two_digit_on_a_row(int *map, int row)
{
	int	i;
	int	a;
	int	b;

	a = 0;
	b = 0;
	i = (row - 1) * 4;
	while (i <= (((row - 1) * 4) + 3))
	{
		if (map[i] != 0 && b == 0 && a > 0)
			b = map[i];
		if (map[i] != 0 && a == 0)
			a = map[i];
		i++;
	}
	return (a + b);
}

int	third_digit_to_test_on_a_row(int sum, int *map, int row)
{
	int	i;

	i = (row - 1) * 4;
	if (sum == 3 || sum == 7)
		return (sum / 2);
	else if (sum == 4 || sum == 6)
		return ((sum / 2) + 1);
	else
	{
		while (i <= (((row - 1) * 4) + 3))
		{
			if ((map[i] != 0))
			{
				if (map[i] == 4 || map[i] == 1)
					return (2);
				else
					return (1);
			}
			i++;
		}
	}
	return (0);
}

int	third_digit_to_test_on_a_col(int sum, int *map, int col)
{
	int	i;

	i = col - 1;
	if (sum == 3 || sum == 7)
		return (sum % 2);
	else if (sum == 4 || sum == 6)
		return ((sum / 2) + 1);
	else
	{
		while (i <= (col + 11))
		{
			if ((map[i] != 0))
			{
				if (map[i] == 4 || map[i] == 1)
					return (2);
				else
					return (1);
			}
			i++;
		}
	}
	return (0);
}
