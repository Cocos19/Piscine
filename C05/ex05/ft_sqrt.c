/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mprofett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 12:11:02 by mprofett          #+#    #+#             */
/*   Updated: 2022/07/14 12:19:06 by mprofett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_sqrt(int nb)
{
	int	i;

	i = 1;
	if (nb == 1)
		return (1);
	while (i <= (nb / 2) && i < 46341)
	{	
		if ((i * i) == nb)
			return (i);
		i++;
	}
	return (0);
}

/*int	main(void)
{
	int	nb;
	int	result;

	nb = 2147395600;
	result = ft_sqrt(nb);
	printf("%d", result);
	return (0);
}*/