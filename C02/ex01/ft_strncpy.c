/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mprofett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 19:21:40 by mprofett          #+#    #+#             */
/*   Updated: 2022/07/12 21:06:47 by mprofett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while ((i < n) && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{	
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

/*
int    main(void)
{
    char    src[7] = {'S', 'a', 'l', 'u', 't', 'c', '\0'};
    char    dest[10] = "okbonjou";

    printf("%s", src); 
    ft_strncpy(dest, src, 15);
    printf("%s", src);
    printf("\n");
    printf("%s", dest);
    return (0);
}*/
