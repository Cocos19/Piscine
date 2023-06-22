/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                        :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: mprofett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 19:57:15 by mprofett          #+#    #+#             */
/*   Updated: 2022/07/16 10:40:14 by mprofett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

unsigned int	ft_strlen(char *str)
{
	int	n;

	n = 0;
	while (str[n] != '\0')
		n++;
	return (n);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	length;

	i = 0;
	length = 0;
	while (dest[length] && length < size)
		length++;
	while (length + i < size - 1 && src[i])
	{
		dest[length + i] = src[i];
		i++;
	}
	if (length < size)
		dest[length + i] = '\0';
	return (length + ft_strlen(src));
}

/*int	main(void)
{
	char	dest[8] = {'d', 'b'};
	char	src[5] = {'a', 'b', 'i', 'p', 'k'};
	int	strlcat;

	strlcat = ft_strlcat(dest, src, 8);
	printf("%s", dest);
	printf("%d", strlcat);
	return (0);
}*/
