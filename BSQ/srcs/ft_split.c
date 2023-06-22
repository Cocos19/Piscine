/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbarbe <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 19:52:11 by tbarbe            #+#    #+#             */
/*   Updated: 2022/07/21 14:48:01 by tbarbe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/bsq.h"

int	ft_notincharset(char c, char *charset)
{
	int	i;

	if (charset[0] == 0)
	{
		return (1);
	}
	i = 0;
	while (charset[i])
	{
		if (charset[i] == c)
			return (0);
	i++;
	}
	return (1);
}

int	ft_strlen_charset(char *str, char *charset)
{
	int	i;

	i = 0;
	while (str[i] && ft_notincharset(str[i], charset))
		i++;
	return (i);
}

int	ft_tabsize(char *str, char *charset)
{
	int	i;
	int	size;
	int	lastischarset;

	i = 0;
	size = 0;
	lastischarset = 0;
	while (str[i])
	{
		if (ft_notincharset(str[i], charset) && lastischarset == 0)
			size++;
		lastischarset = ft_notincharset(str[i], charset);
		i++;
	}
	return (size);
}

char	*ft_strcpy_charset(char *src, char *charset)
{
	int		i;
	char	*copy;
	int		size;

	size = ft_strlen_charset(src, charset);
	copy = (char *) malloc(sizeof(char) * (size + 1));
	if (!copy)
		exit (1);
	i = 0;
	while (i < size)
	{
		copy[i] = src[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

char	**ft_split(char *str, char *charset)
{
	char	**split;
	int		i;
	int		lastischarset;
	int		pos;

	split = (char **) malloc(sizeof(char *) * (ft_tabsize(str, charset) + 1));
	if (!split)
		exit (1);
	i = 0;
	lastischarset = 0;
	pos = 0;
	while (str[i])
	{
		if (ft_notincharset(str[i], charset) && lastischarset == 0)
		{
			split[pos] = ft_strcpy_charset(&str[i], charset);
			pos++;
		}
		lastischarset = ft_notincharset(str[i], charset);
		i++;
	}
	split[pos] = 0;
	return (split);
}
