/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mprofett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 16:01:50 by mprofett          #+#    #+#             */
/*   Updated: 2022/07/18 20:30:06 by mprofett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
//#include <stdio.h>

int	str_len(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	total_len(char **strs, char *sep)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (strs[i])
	{
		len += str_len(strs[i]);
		i++;
	}
	len = len + (str_len(sep) * (i - 1));
	return (len);
}

char	*str_cat(char *str, char *src)
{
	int	i;
	int	str_size;

	i = 0;
	str_size = str_len(str);
	while (src[i])
	{
		str[str_size + i] = src[i];
		i++;
	}
	str[str_size + i] = 0;
	return (str);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	char	*result;

	i = 0;
	if (!strs)
		return (NULL);
	if (total_len(strs, sep) == -1)
		return (NULL);
	if (size == 0)
		return (NULL);
	result = (char *)malloc(sizeof(char) * (total_len(strs, sep) + 1));
	if (!result)
		return (NULL);
	result[0] = 0;
	while (i < size)
	{
		result = str_cat(result, strs[i]);
		if (i < size - 1)
			result = str_cat(result, sep);
		i++;
	}
	result[str_len(result)] = '\0';
	return (result);
}

/*int	main(int argc, char **argv)
{
	char	*sep = ", ";
	char	*result;

	result = ft_strjoin(argc, argv, sep);
	printf("%s", result);
	free(result);
	return (0);
}*/