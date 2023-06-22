/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                  :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: mprofett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 09:37:04 by mprofett          #+#    #+#             */
/*   Updated: 2022/07/12 10:47:36 by mprofett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	check_if_alphanum(char c)
{
	int	check;

	check = 1;
	if (c < 48)
		check = 0;
	if (c > 57 && c < 65)
		check = 0;
	if (c > 90 && c < 97)
		check = 0;
	if (c > 122)
		check = 0;
	return (check);
}

char	*ft_strcapitalize(char *str)
{
	int		i;
	char	buffer;

	i = 0;
	if (str[0] >= 'a' && str[0] <= 'z')
	{
		buffer = str[i];
		str[i] = buffer - 32;
	}
	while (str[i])
	{
		if (check_if_alphanum(str[i]) == 0)
		{	
			if (str[i + 1] >= 97 && str[i + 1] <= 122)
				str[i + 1] = str[i + 1] -32;
		}
		else
		{
			if (str[i + 1] >= 65 && str[i + 1] <= 90)
				str[i + 1] = str[i + 1] + 32;
		}
	i++;
	}
	return (str);
}

/*int	main(void)
{
	char	str[30] = "Sa?c av 45a-pAs s ";

	ft_strcapitalize(str);
	printf("%s", str);
	return (0);
}*/
