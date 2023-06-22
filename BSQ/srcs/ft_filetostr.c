/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filetostr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbarbe <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 14:08:02 by tbarbe            #+#    #+#             */
/*   Updated: 2022/07/26 19:33:34 by tbarbe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/bsq.h"

int	ft_openfile(char *src)
{
	int	fd;

	fd = open(src, O_RDONLY);
	if (fd == -1)
	{
		return (-1);
	}
	return (fd);
}

int	ft_closefile(int fd)
{	
	int	value;

	value = close(fd);
	if (value == -1)
	{
		exit (1);
	}
	return (0);
}

int	ft_filelen(int fd)
{
	int		ret;
	char	buf[1];
	int		i;

	ret = 1;
	i = 0;
	while (ret)
	{
		ret = read(fd, buf, 1);
		i++;
	}
	return (i);
}

char	**ft_splitfile(char *src)
{
	char	*str;
	char	**lines;

	str = ft_copyfile(src);
	lines = ft_split(str, "\n");
	free(str);
	return (lines);
}

char	*ft_copyfile(char *src)
{
	int		ret;
	char	*buf;
	int		len;
	int		fd;

	fd = ft_openfile(src);
	if (fd == -1)
		return (NULL);
	len = ft_filelen(fd);
	if (len < 4)
		return (NULL);
	ft_closefile(fd);
	fd = ft_openfile(src);
	if (fd == -1)
		return (NULL);
	buf = (char *) malloc(sizeof(char) * (len + 1));
	if (!buf)
		exit (1);
	ret = read(fd, buf, len);
	ft_closefile(fd);
	buf[ret] = '\0';
	return (buf);
}
