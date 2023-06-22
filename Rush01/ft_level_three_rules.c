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

int test_first_solution_on_a_col(int *test, int col, int sum);
int test_second_solution_on_a_col(int *test, int col, int sum);
int test_first_solution_on_a_row(int *test, int row, int sum);
int test_second_solution_on_a_row(int *test, int row, int sum);
int *ft_copymap(int *map);
int *apply_first_solution_on_a_col(int *test, int col, int sum);
int *apply_second_solution_on_a_col(int *test, int col, int sum);
int *apply_first_solution_on_a_row(int *test, int row, int sum);
int *apply_second_solution_on_a_row(int *test, int row, int sum);
int check_if_col_have_two_digit_missing(int *map, int col);
int check_if_row_have_two_digit_missing(int *map, int row);
int get_sum_of_two_digit_on_a_col(int *map, int col);
int get_sum_of_two_digit_on_a_row(int *map, int row);

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
	{
    	free(test1);
        free(test2);
        return (map);
    }
    else if (solution1 == 1)
	{
		map = apply_first_solution_on_a_row(test1, row, sum);
        free(test1);
        free(test2);
		return (map);
	}
	map = apply_second_solution_on_a_row(test2, row, sum);
    free(test1);
    free(test2);
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
	{
    	free(test1);
        free(test2);
        return (map);
    }
    else if (solution1 == 1)
	{
		map = apply_first_solution_on_a_col(test1, col, sum);
		free(test1);
        free(test2);
        return (map);
	}
	map = apply_second_solution_on_a_col(test2, col, sum);
	free(test1);
    free(test2);
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
