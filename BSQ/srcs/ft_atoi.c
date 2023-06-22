/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbarbe <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 21:32:24 by tbarbe            #+#    #+#             */
/*   Updated: 2022/07/12 21:39:37 by tbarbe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bsq.h"

int	ft_strtoint(char *str, int size)
{
	int	i;
	int	n;
	int	m;

	i = 0;
	m = 1;
	n = 0;
	while (i < size)
	{
		n += (str[size - i] - 48) * m;
		m *= 10;
		i++;
	}
	return (n);
}

int	ft_whitespace(char c)
{
	if (c == ' '
		|| c == '\t'
		|| c == '\n'
		|| c == '\v'
		|| c == '\f'
		|| c == '\r')
		return (1);
	return (0);
}

int	ft_atoi(char *str)
{
	int	i;
	int	j;
	int	s;

	i = 0;
	s = 1;
	while (ft_whitespace(str[i]))
		i ++;
	while (str[i] == '-' || str [i] == '+')
	{
		if (str[i] == '-')
			s = -s;
		i ++;
	}
	j = i -1;
	while (str[i] >= '0' && str[i] <= '9' && i < ft_strlen(str) - 3)
	{
		i ++;
	}
	if (i == j)
		return (0);
	return (ft_strtoint(&str[j], i - j - 1) * s);
}
