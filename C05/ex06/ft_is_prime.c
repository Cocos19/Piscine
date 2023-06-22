/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mprofett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 12:19:52 by mprofett          #+#    #+#             */
/*   Updated: 2022/07/14 12:27:42 by mprofett         ###   ########.fr       */
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

/*int	main(void)
{
	int	nb;
	int	result;

	nb = 18;
	result = ft_is_prime(nb);
	printf("%d", result);
	return (0);
}*/
