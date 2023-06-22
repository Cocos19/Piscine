/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mprofett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 19:57:15 by mprofett          #+#    #+#             */
/*   Updated: 2022/07/13 09:36:13 by mprofett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <unistd.h>
//#include <stdio.h>
//#include <string.h>

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' || s2[i] != '\0')
	{	
		if (s1[i] != s2[i])
		{
			return (s1[i] - s2[i]);
		}
		i++;
	}
	return (0);
}

/*int	main(void)
{
	char	s1[5] = "Hellk";
	char	s2[20] = "Hellond";
	int	value;
	int check;

	value = ft_strcmp(s1, s2);
	printf("%d", value);
	write(1, "\n", 1);
	check = strcmp(s1, s2);
	printf("%d", check);
	return (0);
}*/
