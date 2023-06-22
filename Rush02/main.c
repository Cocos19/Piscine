/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mprofett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 10:39:12 by mprofett          #+#    #+#             */
/*   Updated: 2022/07/24 10:39:14 by mprofett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*copy_file(char *file_name, int file_size);
int		get_file_size(char *file_name);
int		check_errors(int argc, char **argv);
int		check_tabs(char **u, char **teens, char **tens, char **range);
void	init_tab(char **u, char **teens, char **tens, char **r, char *file);
void	print_start(char *n, char **u, char **teens, char **tens, char **range);
void	print_end(char *n, char **u, char **teens, char **tens, char **range);

void	new_dic(char **u, char **teens, char **tens, char **r, char *file)
{
	file = copy_file(argv[1], get_file_size(argv[1]));
	init_tab(units, teens, tens, range, file);
	free(file);
	if (check_tabs(units, teens, tens, range) == 0)
		return (0);
	else
	{
		print_start(argv[2], units, teens, tens, range);
		print_end(argv[2], units, teens, tens, range);
	}
}

void	org_dic(char **u, char **teens, char **tens, char **r, char *file)
{
	file = copy_file("numbers.dict", get_file_size("numbers.dict"));
	init_tab(units, teens, tens, range, file);
	free(file);
	if (check_tabs(units, teens, tens, range) == 0)
		return (0);
	else
	{
		print_start(argv[1], units, teens, tens, range);
		print_end(argv[1], units, teens, tens, range);
	}
}

int	main(int argc, char **argv)
{
	char	*file;
	char	*units[11];
	char	*teens[11];
	char	*tens[11];
	char	*range[11];

	if (argc == 3)
	{	
		if (check_errors(argc, argv[2]) == 0)
			return (0);
		new_dic(units, teens, tens, range, file);
		return (0);
	}
	else if (argc == 2)
	{
		if (check_errors(argc, argv[1]) == 0)
			return (0);
		org_dic(units, teens, tens, range, file);
		return (0);
	}
	file = NULL;
	write(1, "Incorrect number of arguments", 50);
	return (0);
}
