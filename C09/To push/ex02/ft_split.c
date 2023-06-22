/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mprofett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 10:43:32 by mprofett          #+#    #+#             */
/*   Updated: 2022/07/25 13:28:14 by mprofett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
//#include <stdio.h>

int	char_in_charset(char c, char *charset)
{
	int		i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

int	get_char_s(char *str, char *charset, int i)
{
	int	size;

	size = 0;
	while (str[i] && char_in_charset(str[i], charset) == 0)
	{	
		size++;
		i++;
	}
	return (size);
}

int	get_nbr_str(char *str, char *charset)
{
	int	size;
	int	i;

	i = 0;
	size = 0;
	while (str[i])
	{
		while (char_in_charset(str[i], charset) > 0 && str[i])
			i++;
		if (char_in_charset(str[i], charset) == 0 && str[i])
		{
			size++;
			while (char_in_charset(str[i], charset) == 0 && str[i])
				i++;
		}
		i++;
	}
	return (size);
}

char	*ft_fill_str(char *str, char *charset, int i)
{
	char	*result;
	int		j;

	j = 0;
	result = (char *)malloc(sizeof(char) * (get_char_s(str, charset, i) + 1));
	if (!result)
		return (NULL);
	while (str[i] && char_in_charset(str[i], charset) == 0)
	{	
		result[j] = str[i];
		i++;
		j++;
	}
	result[j] = '\0';
	if (result == 0)
	{
		result[0] = '\0';
		return (result);
	}
	return (result);
}

char	**ft_split(char *str, char *charset)
{
	char	**result;
	int		i;
	int		j;

	i = 0;
	j = 0;
	result = (char **)malloc(sizeof(char *) * (get_nbr_str(str, charset) + 1));
	if (!result)
		return (NULL);
	while (j < get_nbr_str(str, charset) && str[i])
	{	
		while (char_in_charset(str[i], charset) > 0 && str[i])
			i++;
		if (str[i])
		{
			result[j] = ft_fill_str(str, charset, i);
			if (!result[j])
				return (NULL);
			j++;
		}
		while (char_in_charset(str[i], charset) == 0 && str[i])
			i++;
	}
	result[j] = 0;
	return (result);
}

/*int	main(void)
{
	char	str[50] = "test, blablabla, , tut,,,\0utu, \0Test, , , ,,lol";
	char	charset[20] = ", ";
	char	**result;
	int		i;

	i = 0;
	result = ft_split(str, charset);
	while (result[i])
	{
		printf("%s\n", result[i]);
		i++;
	}
	return (0);
}*/