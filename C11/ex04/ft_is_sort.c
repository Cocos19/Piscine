/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mprofett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 19:54:52 by mprofett          #+#    #+#             */
/*   Updated: 2022/07/25 19:54:54 by mprofett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h>

int	cmp_int(int a, int b)
{
	if (a < b)
		return (-1);
	else if (a > b)
		return (1);
	return (0);
}
*/
int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	i;

	i = 0;
	while (i < length - 1 && ((*f)(tab[i], tab[i + 1])) == 0)
		i++;
	if (i < length - 1 && ((*f)(tab[i], tab[i + 1])) > 0)
	{
		while (i < length - 1)
		{	
			if (((*f)(tab[i], tab[i + 1])) < 0)
				return (0);
			i++;
		}
	}
	else if (i < length - 1 && ((*f)(tab[i], tab[i + 1])) < 0)
	{
		while (i < length - 1)
		{	
			if (((*f)(tab[i], tab[i + 1])) > 0)
				return (0);
			i++;
		}
	}
	return (1);
}

/*int	main(void)
{
	int	tab[10] = {0, 1, 2, 3, 3, 5, 6, 7, 9, 9};
	int	tab2[10] = {9, 9, 9, 2, 1, 1, 1, 5, 0, 0};
	int	tab[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

	printf("%d", ft_is_sort(tab, 10, &cmp_int));
	return (0);
}*/
