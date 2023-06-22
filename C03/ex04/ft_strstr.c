/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mprofett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 19:57:15 by mprofett          #+#    #+#             */
/*   Updated: 2022/07/14 19:27:55 by mprofett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_strlen(char *str)
{
	int	n;

	n = 0;
	while (str[n])
		n++;
	return (n);
}

char	*compare(char *str, char *to_find, int position)
{
	int		i;
	int		j;
	char	*c;

	i = 0;
	j = position;
	c = 0;
	while (str[j] == to_find[i])
	{
		if (to_find[i + 1] == '\0')
			return (&str[position]);
		i++;
		j++;
	}
	return (c);
}

char	*ft_strstr(char *str, char *to_find)
{
	int		i;
	char	*c;

	i = 0;
	c = 0;
	if (to_find[0] == '\0')
		return (str);
	while (str[i])
	{
		if (str[i] == to_find[0])
		{	
			c = compare(str, to_find, i);
			if (c != 0)
				return (c);
		}
		i++;
	}
	return (c);
}

/*int	main(void)
{
	char	str[30] = "kwkfkwkaawkn";
	char	to_find[4] = "aaw";
	char	*result;

	result = ft_strstr(str, to_find);
	printf("%c", *result);
	printf("%p", result);
	printf("\n");
	printf("%p", str + 7);
	printf("%s", result);
	printf("\n");
	return (0);
}*/
