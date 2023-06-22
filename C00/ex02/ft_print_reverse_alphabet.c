/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mprofett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 10:32:23 by mprofett          #+#    #+#             */
/*   Updated: 2022/07/08 12:36:51 by mprofett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_reverse_alphabet(void)
{	
	char	letter;

	letter = 122;
	while (letter >= 97)
	{
		write (1, &letter, 1);
		letter--;
	}
}
/*

int	main()
{
	ft_print_reverse_alphabet();
	return 0;
}*/
