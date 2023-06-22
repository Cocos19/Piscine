/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mprofett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 19:57:15 by mprofett          #+#    #+#             */
/*   Updated: 2022/07/13 09:36:22 by mprofett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <unistd.h>
//#include <stdio.h>
//#include <string.h>

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while ((s1[i] || s2[i]) && (i < n))
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
	char	s1[5] = "Hdell";
	char	s2[20] = "Hellknd";
	int	value;
	int check;

	value = ft_strncmp(s1, s2, 3);
	printf("%d", value);
	write(1, "\n", 1);
	check = strncmp(s1, s2, 3);
	printf("%d", check);
	return (0);
}*/
