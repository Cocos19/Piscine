/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mprofett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 20:47:23 by mprofett          #+#    #+#             */
/*   Updated: 2022/07/13 21:07:59 by mprofett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_recursive_factorial(int nb)
{
	int	total;
	int	i;

	i = nb;
	if (nb < 0)
		return (0);
	if (nb == 0 || nb == 1)
		return (1);
	total = i * ft_recursive_factorial(nb - 1);
	return (total);
}

/*int	main(void)
{
	int	nb;
	int	total;

	nb = 1;
	total = ft_recursive_factorial(nb);
	printf("%d", total);
	return (0);
}*/
