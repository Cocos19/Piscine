/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mprofett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 21:08:42 by mprofett          #+#    #+#             */
/*   Updated: 2022/07/13 21:29:28 by mprofett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_iterative_power(int nb, int power)
{
	int	total;

	total = nb;
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	while (power > 1)
	{	
		total *= nb;
		power--;
	}
	return (total);
}

/*int	main(void)
{
	int	nb;
	int	power;
	int	total;

	nb = 5;
	power = 13;
	total = ft_iterative_power(nb, power);
	printf("%d", total);
}*/
