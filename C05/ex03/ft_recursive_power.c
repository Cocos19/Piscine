/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mprofett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 21:19:11 by mprofett          #+#    #+#             */
/*   Updated: 2022/07/13 21:28:54 by mprofett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_recursive_power(int nb, int power)
{
	int	i;
	int	total;

	i = nb;
	total = nb;
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	if (nb == 0)
		return (0);
	if (power > 1)
	{	
		power--;
		total = i * ft_recursive_power(nb, power);
	}
	return (total);
}

/*int	main(void)
{
	int	nb;
	int	power;
	int	total;

	nb = -7;
	power = 2;
	total = ft_recursive_power(nb, power);
	printf("%d", total);
	return (0);
}*/
