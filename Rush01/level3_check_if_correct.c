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

int	test_first_solution_on_a_row(int *test, int *views, int row, int sum)
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

int	test_second_solution_on_a_row(int *test, int *views, int row, int sum)
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

int	*test_two_solutions_on_a_row(int *map, int *views, int row, int sum)
{
	int	*test1;
	int	*test2;
	int	solution1;
	int	solution2;

	test1 = ft_copymap(map);
	test2 = ft_copymap(map);
	solution1 = test_first_solution_on_a_row(test1, views, row, sum);
	solution2 = test_second_solution_on_a_row(test2, views, row, sum);
	if (solution1 + solution2 == 2 || solution1 + solution2 == 0)
		return (map);
	else if (solution1 == 1)
	{
		map = apply_first_solution_on_a_row(test1, row, sum);
		return (map);
	}
	map = apply_second_solution_on_a_row(test2, row, sum);
	return (map);
}

int	*test_two_solutions_on_a_col(int *map, int *views, int col, int sum)
{
	int	*test1;
	int	*test2;
	int	solution1;
	int	solution2;

	test1 = ft_copymap(map);
	test2 = ft_copymap(map);
	solution1 = test_first_solution_on_a_col(test1, views, col, sum);
	solution2 = test_second_solution_on_a_col(test2, views, col, sum);
	if (solution1 + solution2 == 2 || solution1 + solution2 == 0)
		return (map);
	else if (solution1 == 1)
	{
		map = apply_first_solution_on_a_col(test1, col, sum);
		return (map);
	}
	map = apply_second_solution_on_a_col(test2, col, sum);
	return (map);
}

int	*apply_level_three_rules_on_rows(int *map, int *views)
{
	int	i;
	int	row;
	int	sum;

	sum = 0;
	i = 0;
	row = i + 1;
	while (i < 4)
	{
		row = i + 1;
		if (check_if_row_have_two_digit_missing(map, row) == 1)
		{	
			sum = get_sum_of_two_digit_on_a_row(map, row);
			map = test_two_solutions_on_a_row(map, views, row, sum);
		}
		i++;
	}
	return (map);
}

int	*apply_level_three_rules_on_cols(int *map, int *views)
{
	int	i;
	int	col;
	int	sum;

	sum = 0;
	i = 0;
	col = i + 1;
	while (i < 4)
	{
		col = i + 1;
		if (check_if_col_have_two_digit_missing(map, col) == 1)
		{	
			sum = get_sum_of_two_digit_on_a_col(map, col);
			map = test_two_solutions_on_a_col(map, views, col, sum);
		}
		i++;
	}
	return (map);
}

int	*apply_level_three_rules(int *map, int *views)
{
	map = apply_level_three_rules_on_cols(map, views);
	map = apply_level_three_rules_on_rows(map, views);
	return (map);
}
