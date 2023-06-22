/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_numbers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mprofett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 18:07:18 by mprofett          #+#    #+#             */
/*   Updated: 2022/07/24 18:07:20 by mprofett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		strl(char *nbr);
void	print_range(char *str);
void	print_hundreds(char *n, char **u, char **teens, char **tens, char *h);
void	init_buffer(char *buf, char zero, char one, char two);

void	print_start(char *n, char **u, char **teens, char **tens, char **range)
{
	int		i;
	int		j;
	int		index;
	char	buf[3];

	i = (strl(n) / 3) - 1;
	j = strl(n) % 3;
	index = j;
	if (j == 1)
	{	
		init_buffer(buf, '0', '0', n[0]);
		print_hundreds(buf, u, teens, tens, range[0]);
		print_range(range[i + 1]);
	}
	if (j == 2)
	{
		init_buffer(buf, '0', n[0], n[1]);
		print_hundreds(buf, u, teens, tens, range[0]);
		print_range(range[i + 1]);
	}
}

void	print_end(char *n, char **u, char **teens, char **tens, char **range)
{
	int		i;
	int		j;
	int		index;
	char	buf[3];

	i = (strl(n) / 3) - 1;
	j = strl(n) % 3;
	index = j;
	while (i > 0)
	{
		init_buffer(buf, n[index], n[index + 1], n[index + 2]);
		print_hundreds(buf, u, teens, tens, range[0]);
		print_range(range[i]);
		index += 3;
		i--;
	}
	init_buffer(buf, n[index], n[index + 1], n[index + 2]);
	print_hundreds(buf, u, teens, tens, range[0]);
}
