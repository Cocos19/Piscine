/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mprofett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 09:37:04 by mprofett          #+#    #+#             */
/*   Updated: 2022/07/11 10:33:54 by mprofett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <unistd.h>
//#include <stdio.h>

int	lenght(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

int	ft_str_is_lowercase(char *str)
{
	int	test;
	int	i;
	int	max;

	test = 1;
	i = 0;
	max = lenght(str);
	while (i < max)
	{
		if (str[i] >= 'a' && str[i] <= 'z')
		{
			test = 1;
		}
		else
		{
			test = 0;
			i = max;
		}
		i++;
	}
	return (test);
}

/*
int	main(void)
{
	char	str[30] = "saucavapas";
	int		check;

	check = ft_str_is_lowercase(str);
	printf("%d", check);
	return (0);
}*/
