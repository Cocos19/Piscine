/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_negative.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mprofett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 14:11:56 by mprofett          #+#    #+#             */
/*   Updated: 2022/07/08 12:39:37 by mprofett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_is_negative(int n)
{
	char	negatif;
	char	positif;

	negatif = 'N';
	positif = 'P';
	if (n < 0)
	{
		write (1, &negatif, 1);
	}
	else
	{
		write (1, &positif, 1);
	}
}
/*
int	main()
{
	ft_is_negative(-36);
	return 0;
}*/
