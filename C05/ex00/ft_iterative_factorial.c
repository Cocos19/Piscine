/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mprofett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 20:30:42 by mprofett          #+#    #+#             */
/*   Updated: 2022/07/13 20:46:53 by mprofett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_iterative_factorial(int nb)
{
	int	total;
	int	i;

	i = 1;
	total = 1;
	if (nb < 0 || nb > 12)
		return (0);
	while (i <= nb)
	{	
		total *= i;
		i++;
	}
	return (total);
}

/*int	main(void)
{
	int	nb;
	int	total;

	nb = 0;
	total = ft_iterative_factorial(nb);
	printf("%d", total);
	return (0);
}*/
