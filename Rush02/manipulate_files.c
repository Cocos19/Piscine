/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mprofett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 18:15:49 by mprofett          #+#    #+#             */
/*   Updated: 2022/07/23 18:15:51 by mprofett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

int	get_file_size(char *file_name)
{
	int		size;
	int		fd;
	int		i;
	char	buffer[2];

	size = 0;
	i = 0;
	fd = open(file_name, O_RDONLY);
	size += read(fd, buffer, 1);
	while (size > i)
	{	
		i = size;
		size += read(fd, buffer, 1);
	}
	if (close(fd) == -1)
		size = -1;
	return (size);
}

char	*copy_file(char *file_name, int file_size)
{
	int		fd;
	int		ret;
	char	*cpy;

	cpy = (char *)malloc(sizeof(char) * (file_size + 1));
	if (!cpy)
		return (NULL);
	fd = open(file_name, O_RDONLY);
	ret = read(fd, cpy, file_size);
	cpy[file_size + 1] = '\0';
	if (close(fd) == -1)
		return (NULL);
	return (cpy);
}

int	strl(char *nbr)
{
	int	i;

	i = 0;
	while (nbr[i])
		i++;
	return (i);
}

void	ft_putstr(char *str)
{
	int	n;

	n = 0;
	while (str[n])
	{
		write(1, &(str[n]), 1);
		n++;
	}
}
