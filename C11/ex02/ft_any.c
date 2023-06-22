/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_any.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mprofett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 16:31:09 by mprofett          #+#    #+#             */
/*   Updated: 2022/07/28 11:46:20 by mprofett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

/*int str_is_numeric(char *str)
{
    int i;

    i = 0;
    while (str[i] == 0)
    {
        if (str[i] < '0' && str[i] > '9')
            return (0);
		i++;
	}
	return (1);
}
*/
int	ft_any(char **tab, int (*f)(char *))
{
	int	i;

	i = 0;
	while (!(tab[i] == 0))
	{
		if (((*f)(tab[i]) != 0))
			return (1);
		i++;
	}
	return (0);
}

/*int	main(void)
{
	char *tab[5];
	char str0[5] = "01234";
	char str1[5] = "01234";
	char str2[5] = "01234";
	char str3[5] = "01234";

	tab[0] = str0;
	tab[1] = str1;
	tab[2] = str2;
	tab[3] = str3;
	tab[4] = 0;
	printf("%d", ft_any(tab, &str_is_numeric));
	return (0);
}*/
