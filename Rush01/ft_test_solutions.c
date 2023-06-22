/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_solutions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mprofett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 22:07:29 by mprofett          #+#    #+#             */
/*   Updated: 2022/07/17 22:07:32 by mprofett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	third_digit_to_test_on_a_col(int sum, int *map, int col);
int	third_digit_to_test_on_a_row(int sum, int *map, int row);
int	check_if_col_correct(int *map, int *views, int col);
int	check_if_row_correct(int *map, int *views, int row);

int	test_first_solution_on_a_row(int *test, int *views, int row)
{
	int	i;
	int	a;
	int	b;
	int	check;

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
	check = check_if_row_correct(test, views, row);
	return (check);
}

int	test_second_solution_on_a_row(int *test, int *views, int row)
{
	int	i;
	int	a;
	int	b;
	int	check;

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
	check = check_if_row_correct(test, views, row);
	return (check);
}

int	test_first_solution_on_a_col(int *test, int *views, int col, int sum)
{
	int	i;
	int	a;
	int	b;
	int	check;

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
	check = check_if_col_correct(test, views, col);
	return (check);
}

int	test_second_solution_on_a_col(int *test, int *views, int col, int sum)
{
	int	i;
	int	a;
	int	b;
	int	check;

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
	check = check_if_col_correct(test, views, col);
	return (check);
}
