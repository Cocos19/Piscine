/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mprofett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 19:27:38 by mprofett          #+#    #+#             */
/*   Updated: 2022/07/23 19:27:41 by mprofett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

void	init_units(int i, char **units, char *file);
void	init_teens(int i, char **teens, char *file);
void	init_tens(int i, char **tens, char *file);
void	init_range(int i, char **range, char *file);

int	str_len(int position, char *file)
{
	int	i;

	i = position;
	while (file[i] && file[i] > ' ' && file[i] != ':')
		i++;
	return (i - position);
}

char	*cpy_str(int position, char *file)
{
	char	*str;
	int		i;

	i = 0;
	str = (char *)malloc(sizeof(char) * (str_len(i, file) + 1));
	if (!str)
		return (NULL);
	while (file[position + i] && i < str_len(position, file))
	{
		str[i] = file[position + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

int	check_if_relevant(int position, char *file)
{
	int	i;

	i = position;
	if ((file[i] >= '0' || file[i] <= '9')
		&& !(file[i + 1] >= '0' && file [i + 1] <= '9'))
		return (1);
	if ((file[i] >= '2' && file[i] <= '9')
		&& file[i + 1] == '0' && (file[i + 2] == ' ' || file[i + 2] == ':'))
		return (20);
	if (file[i] == '1')
	{
		if ((file[i + 1] >= '0' && file[i + 1] <= '9')
			&& !(file[i + 2] >= '0' && file[i + 2] <= '9'))
			return (10);
		i++;
		while (file[i] == '0')
		{
			if ((file[i + 1] == ' ' || file[i + 1] <= ':'))
				return (100);
			i++;
		}
	}
	return (-1);
}

void	init_tab(char **u, char **teens, char **tens, char **r, char *file)
{
	int	i;
	int	position;

	i = 0;
	position = 0;
	while (file[i])
	{
		if (check_if_relevant(i, file) > 0)
		{
			position = check_if_relevant(i, file);
			if (position == 1)
				init_units(i, u, file);
			if (position == 10)
				init_teens(i, teens, file);
			if (position == 20)
				init_tens(i, tens, file);
			if (position == 100)
				init_range(i, r, file);
		}
		while (file[i] && file[i] != '\n')
			i++;
		i++;
	}
}
