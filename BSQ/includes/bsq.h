/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbarbe <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 13:15:53 by tbarbe            #+#    #+#             */
/*   Updated: 2022/07/26 19:29:54 by tbarbe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef BSQ_H
# define BSQ_H
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_pos
{
	int	x;
	int	y;
}	t_pos;

typedef struct s_cel
{
	char	type;
	t_pos	pos;
}	t_cel;

typedef struct s_square
{
	int		size;
	t_pos	pos;
}	t_square;

typedef struct s_types
{
	char	empty;
	char	obst;
	char	full;
}	t_types;

typedef struct s_grid
{
	t_pos		size;
	t_cel		*cels;
	t_types		types;
	t_square	result;
}	t_grid;

int		ft_strlen(char *str);
int		ft_linelen(char *str);
void	ft_putchar(char c);
void	ft_putstr(char *str);
void	free_strtab(char **strs);
void	ft_putnbr(int n);
char	*ft_copyfile(char *src);
char	**ft_splitfile(char *src);
char	**ft_split(char *str, char *charset);
int		ft_atoi(char *str);
t_grid	ft_initgrid(char *str);
int		ft_checkgrid(t_grid *grid, char *str);
t_cel	*ft_loadcels(t_grid grid, char *str);
char	ft_gettype(t_grid grid, int x, int y);
void	ft_settype(t_grid *grid, int x, int y, char type);
int		ft_goodzone(t_grid grid, t_pos pos);
void	ft_celsfindsizes(t_grid *grid);
void	ft_writesquare(t_grid *grid);
void	ft_putgrid(t_grid grid);
void	free_strs(char **strs);
#endif
