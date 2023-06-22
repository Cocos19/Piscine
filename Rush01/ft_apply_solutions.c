/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply_solutions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mprofett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 22:04:22 by mprofett          #+#    #+#             */
/*   Updated: 2022/07/17 22:04:28 by mprofett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	third_digit_to_test_on_a_col(int sum, int *map, int col);
int	third_digit_to_test_on_a_row(int sum, int *map, int row);

int	*ft_copymap(int *map)
{
	int	*copy;
	int	i;

	copy = (int *)malloc(sizeof(int) * (16 + 1));
	i = 0;
	while (i < 16)
	{
		copy[i] = map[i];
		i++;
	}
	return (copy);
}

int	*apply_first_solution_on_a_col(int *test, int col, int sum)
{
	int	i;
	int	a;
	int	b;

	b = third_digit_to_test_on_a_row(sum, test, col);
	a = 10 - b - sum;
	i = col - 1;
	while (i <= (col + 11))
	{
		if (test[i] == 0 && a > 0 && b > 0)
		{	
			test[i] = b;
			b = 0;
		}
		if (test[i] == 0 && b == 0 && a > 0)
		{
			test[i] = a;
			a = 0;
		}
	i += 4;
	}
	return (test);
}

int	*apply_second_solution_on_a_col(int *test, int col, int sum)
{
	int	i;
	int	a;
	int	b;

	b = third_digit_to_test_on_a_row(sum, test, col);
	a = 10 - b - sum;
	i = col - 1;
	while (i <= (col + 11))
	{
		if (test[i] == 0 && a > 0 && b > 0)
		{	
			test[i] = a;
			a = 0;
		}
		if (test[i] == 0 && b > 0 && a == 0)
		{
			test[i] = b;
			b = 0;
		}
	i += 4;
	}
	return (test);
}

int	*apply_first_solution_on_a_row(int *test, int row, int sum)
{
	int	i;
	int	a;
	int	b;

	b = third_digit_to_test_on_a_row(sum, test, row);
	a = 10 - b - sum;
	i = (row - 1) * 4;
	while (i <= ((row - 1) * 4) + 3)
	{
		if (test[i] == 0 && a > 0 && b > 0)
		{	
			test[i] = b;
			b = 0;
		}
		if (test[i] == 0 && b == 0 && a > 0)
		{
			test[i] = a;
			a = 0;
		}
		i++;
	}
	return (test);
}

int	*apply_second_solution_on_a_row(int *test, int row, int sum)
{
	int	i;
	int	a;
	int	b;

	b = third_digit_to_test_on_a_row(sum, test, row);
	a = 10 - b - sum;
	i = (row - 1) * 4;
	while (i <= ((row - 1) * 4) + 3)
	{
		if (test[i] == 0 && a > 0 && b > 0)
		{	
			test[i] = a;
			a = 0;
		}
		if (test[i] == 0 && b > 0 && a == 0)
		{
			test[i] = b;
			b = 0;
		}
		i++;
	}
	return (test);
}
