/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mprofett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 11:04:04 by mprofett          #+#    #+#             */
/*   Updated: 2022/07/24 11:04:06 by mprofett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*cpy_str(int position, char *file);
int		str_len(int position, char *file);

void	init_units(int i, char **units, char *file)
{
	int	pos;

	pos = file[i] - 48;
	i++;
	while (file[i] && (file[i] >= '0' && file[i] <= '9'))
		i++;
	while (file[i] && (file[i] == ' ' || file[i] == ':'))
		i++;
	units[pos] = cpy_str(i, file);
}

void	init_teens(int i, char **teens, char *file)
{
	int	pos;

	pos = file[i + 1] - 48;
	i += 2;
	while (file[i] && file[i] >= '0' && file[i] <= '9')
		i++;
	while (file[i] && (file[i] == ' ' || file[i] == ':'))
		i++;
	teens[pos] = cpy_str(i, file);
}

void	init_tens(int i, char **tens, char *file)
{
	int	pos;

	pos = file[i] - 48;
	i += 2;
	while (file[i] && file[i] >= '0' && file[i] <= '9')
		i++;
	while (file[i] && (file[i] == ' ' || file[i] == ':'))
		i++;
	tens[pos] = cpy_str(i, file);
}

void	init_range(int i, char **range, char *file)
{
	int	pos;
	int	count;

	count = 0;
	i++;
	while (file[i] == '0')
	{
		i++;
		count++;
	}
	pos = count / 3;
	while (file[i] && file[i] >= '0' && file[i] <= '9')
		i++;
	while (file[i] && (file[i] == ' ' || file[i] == ':'))
		i++;
	range[pos] = cpy_str(i, file);
}
