/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mprofett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 10:32:23 by mprofett          #+#    #+#             */
/*   Updated: 2022/07/09 11:12:46 by mprofett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_numbers(void)
{	
	char	number;

	number = 48;
	while (number <= 57)
	{
		write (1, &number, 1);
		number++;
	}
}
/*
int	main()
{
	ft_print_numbers();
	return 0;
}*/
