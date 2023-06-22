/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mprofett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 12:19:52 by mprofett          #+#    #+#             */
/*   Updated: 2022/07/14 12:40:44 by mprofett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_is_prime(int nb)
{
	int	i;

	i = 2;
	if (nb < 0)
		nb *= -1;
	if (nb == 1 || nb == 0)
		return (0);
	while (i != nb)
	{	
		if ((nb % i) == 0)
			return (0);
		i++;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	int	i;

	i = 0;
	if (nb < 3)
		return (2);
	if ((nb % 2) == 0)
		nb += 1;
	while (ft_is_prime(nb + i) != 1)
		i += 2;
	return (nb + i);
}

/*int	main(void)
{
	int	nb;
	int	result;

	nb = 2147483630;
	result = ft_find_next_prime(nb);
	printf("%d", result);
	return (0);
}*/
