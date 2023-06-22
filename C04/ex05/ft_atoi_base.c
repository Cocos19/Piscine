/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mprofett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 10:10:54 by mprofett          #+#    #+#             */
/*   Updated: 2022/07/14 18:57:43 by mprofett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	check_if_negative(char *str)
{
	int	result;
	int	i;

	i = 0;
	result = 1;
	while (str[i] == ' ' || str[i] == '\f' || str[i] == '\n'
		|| str[i] == '\r' || str[i] == '\t' || str[i] == '\v')
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			result *= -1;
		i++;
	}
	return (result);
}

int	where_in_base(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (c == base[i])
			return (i);
		i++;
	}
	return (-1);
}

int	ft_strlength(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	check_errors(char *base, int base_length)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	if (base[0] == '\0' || base[1] == '\0')
		return (0);
	while (i < base_length - 1)
	{	
		j = i + 1;
		while (base[j])
		{	
			if (base[i] == base[j] || base[i] == '+' || base[i] == '-'
				|| base[j] == '+' || base[j] == '-' || base[i] <= 32
				|| base[i] == 127 || base[j] <= 32 || base[j] == 127)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	result;

	i = 0;
	result = 0;
	if (check_errors(base, ft_strlength(base)) == 1)
	{
		while (str[i] == ' ' || str[i] == '\f' || str[i] == '\n'
			|| str[i] == '\r' || str[i] == '\t' || str[i] == '\v')
			i++;
		while (str[i] == '-' || str[i] == '+')
			i++;
		while (str[i] && where_in_base(str[i], base) >= 0)
		{
			result *= ft_strlength(base);
			result += where_in_base(str[i], base);
			i++;
		}
		return (result * check_if_negative(str));
	}
	return (0);
}

/*int	main(void)
{
	int	i;
	char	base[17] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B'};
	char	c[30] = {10, 10, 10, 10, '-', '-', '+', 'A', 'B', '9', 'a', 'f', 'a', 'b'};

	i = ft_atoi_base(c, base);
	printf("%d", i);
	return (0);
}*/