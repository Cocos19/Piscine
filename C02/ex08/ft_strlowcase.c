/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mprofett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 09:37:04 by mprofett          #+#    #+#             */
/*   Updated: 2022/07/11 10:35:27 by mprofett         ###   ########.fr       */
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

char	*ft_strlowcase(char *str)
{
	int		test;
	int		i;
	int		max;
	char	buffer;

	test = 1;
	i = 0;
	max = lenght(str);
	while (i < max)
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
		{
			buffer = str[i];
			str[i] = buffer + 32;
		}
		i++;
	}
	return (str);
}

/*
int	main(void)
{
	char	str[30] = "Sa?ucavapas";

	ft_strlowcase(str);
	printf("%s", str);

	return (0);
}*/
