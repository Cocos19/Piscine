/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mprofett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 09:16:52 by mprofett          #+#    #+#             */
/*   Updated: 2022/07/20 10:43:02 by mprofett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
//#include <stdio.h>

int	str_len(char *str);
int	get_in_base(char *base, char c);
int	base_validity(char *base, int base_len);
int	nbr_size(char *str, char *base_from);
int	size(int nbr, char *base_to);

int	where_in_base(char *base, char c)
{
	int	i;

	i = 0;
	while (base[i])
	{	
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

char	*fill_nbr_s(char *result, char *str, char *base_from)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	result[0] = '+';
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-' && result[0] == '+')
			result[0] = '-';
		else if (str[i] == '-' && result[0] == '-')
			result[0] = '+';
		i++;
	}
	while (str[i] && get_in_base(base_from, str[i]) > 0)
	{
		result[j] = str[i];
		i++;
		j++;
	}
	return (result);
}

int	ft_atoi(char *str, char *base_from)
{
	int	i;
	int	nbr;

	i = 1;
	nbr = 0;
	while (str[i])
	{
		nbr *= str_len(base_from);
		nbr += where_in_base(base_from, str[i]);
		i++;
	}
	if (str[0] == '-')
		nbr *= -1;
	return (nbr);
}

char	*putnb(int nbr, int size, char *result, char *base_to)
{
	int				i;
	unsigned int	n;

	i = size;
	if (nbr < 0)
	{
		i++;
		size += 1;
		nbr *= -1;
	}
	n = nbr;
	if (n == 0)
		result[0] = base_to[0];
	while (n > 0)
	{
		result[i - 1] = base_to[n % str_len(base_to)];
		n = n / str_len(base_to);
		i--;
	}
	result[size] = '\0';
	return (result);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	char	*result;
	char	*nbr_s;
	int		nbr_int;

	if (base_validity(base_from, str_len(base_from)) == 0
		|| base_validity(base_to, str_len(base_to)) == 0)
		return (NULL);
	if (nbr_size(nbr, base_from) == 0)
		return (NULL);
	nbr_s = (char *)malloc((sizeof(char) * (nbr_size(nbr, base_from) + 2)));
	nbr_s = fill_nbr_s(nbr_s, nbr, base_from);
	nbr_int = ft_atoi(nbr_s, base_from);
	free(nbr_s);
	if (nbr_int < 0)
	{
		result = (char *)malloc(sizeof(char) * (size(nbr_int, base_to) + 2));
		result[0] = '-';
	}
	else
		result = (char *)malloc(sizeof(char) * (size(nbr_int, base_to) + 1));
	result = putnb(nbr_int, size(nbr_int, base_to), result, base_to);
	return (result);
}

/*int main(void)
{
    char    base_from[17] = "0123456789ABCDEF";
    char    base_to[30] = "abcdefg";
    char    nbr[50] = "     --++---+012235545---+  ";
    char    *result;
	int		i;

	i = 0;
    result = ft_convert_base(nbr, base_from, base_to);
	while (result[i])
	{
		printf("%c", result[i]);
		i++;
	}
	return (0);
}*/
