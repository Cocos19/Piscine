/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mprofett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 20:33:03 by mprofett          #+#    #+#             */
/*   Updated: 2022/07/20 10:43:11 by mprofett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	str_len(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	get_in_base(char *base, char c)
{
	int	i;

	i = 0;
	while (base[i])
	{	
		if (base[i] == c)
			return (c);
		i++;
	}
	return (-1);
}

int	base_validity(char *base, int base_len)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	if (base[0] == '\0' || base[1] == '\0')
		return (0);
	while (i < base_len - 1)
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

int	size(int nbr, char *base_to)
{
	int	i;

	i = 0;
	if (nbr == 0)
		return (1);
	if (nbr < 0)
		nbr *= -1;
	while (nbr > 0)
	{	
		nbr = nbr / str_len(base_to);
		i++;
	}
	return (i);
}

int	nbr_size(char *str, char *base_from)
{
	int	i;
	int	size;

	i = 0;
	size = 0;
	while (str[i] == ' ' || str[i] == '\f' || str[i] == '\n'
		|| str[i] == '\r' || str[i] == '\t' || str[i] == '\v')
		i++;
	while (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] && get_in_base(base_from, str[i]) >= 0)
	{
		i++;
		size++;
	}
	return (size);
}
