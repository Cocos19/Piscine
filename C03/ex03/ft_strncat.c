/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mprofett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 19:57:15 by mprofett          #+#    #+#             */
/*   Updated: 2022/07/14 09:16:51 by mprofett         ###   ########.fr       */
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

char	*ft_strncat(char *dest, char *src, unsigned int nb )
{
	int				size;
	unsigned int	i;

	i = 0;
	size = ft_strlen(dest);
	while (i < nb && src[i])
	{
		dest[size] = src[i];
		size++;
		i++;
	}
	dest[size] = '\0';
	return (dest);
}

/*int	main(void)
{
	char	dest[30] = "}ellsklw";
	char	src[10] = "loliaknd";

	ft_strncat(dest, src, 10);
	printf("%s", dest);
	return (0);
}*/
