/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mprofett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 17:02:32 by mprofett          #+#    #+#             */
/*   Updated: 2022/07/25 17:02:34 by mprofett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h>

int	str_is_numeric(char *str)
{
	int	i;
	int count;

	i = 0;
	count = 0;
	printf("%s\n", str);
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
		{
			return (1);
		}
		i++;
	}
	return (count);
}*/

int	ft_count_if(char **tab, int length, int (*f)(char *))
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (i < length - 1)
	{
		if (f(tab[i]) != 0)
			count++;
		i++;
	}
	return (count);
}

/*int	main(void)
{
	char *tab[5];
	char str0[6] = "01234";
	char str1[6] = "456j8";
	char str2[6] = "98765";
	char str3[6] = "012j4";

	tab[0] = str0;
	tab[1] = str1;
	tab[2] = str2;
	tab[3] = str3;
	tab[4] = 0;
	printf("%d", ft_count_if(tab, 5, &str_is_numeric));
	return (0);
}*/
