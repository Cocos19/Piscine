/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do-op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mprofett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 10:40:11 by mprofett          #+#    #+#             */
/*   Updated: 2022/07/26 10:40:12 by mprofett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int		plus(int a, int b);
int		minus(int a, int b);
int		multiply(int a, int b);
int		divide(int a, int b);
int		modulo(int a, int b);
int		ft_atoi(char *str);
void	ft_putnbr(int nb);

int	check_validity(int argc, char **argv)
{
	if (argc != 4)
		return (0);
	if (argv[2][0] == '/' && ft_atoi(argv[3]) == 0)
	{
		write(1, "Stop : division by zero\n", 24);
		return (0);
	}
	if (argv[2][0] == '%' && ft_atoi(argv[3]) == 0)
	{
		write(1, "Stop : modulo by zero\n", 22);
		return (0);
	}
	if (!(argv[2][0] == '+') && !(argv[2][0] == '-') && !(argv[2][0] == '*')
		&& !(argv[2][0] == '/') && !(argv[2][0] == '%'))
	{
		write(1, "0\n", 2);
		return (0);
	}
	return (1);
}

int	operate(char **argv, int (**tab)(int, int))
{
	int	result;

	result = 0;
	if (argv[2][0] == '+')
		result = (tab[0](ft_atoi(argv[1]), ft_atoi(argv[3])));
	else if (argv[2][0] == '-')
		result = (tab[1](ft_atoi(argv[1]), ft_atoi(argv[3])));
	else if (argv[2][0] == '*')
		result = tab[2](ft_atoi(argv[1]), ft_atoi(argv[3]));
	else if (argv[2][0] == '/')
		result = (tab[3](ft_atoi(argv[1]), ft_atoi(argv[3])));
	else if (argv[2][0] == '%')
		result = (tab[4](ft_atoi(argv[1]), ft_atoi(argv[3])));
	return (result);
}

int	main(int argc, char **argv)
{
	int	(*tab[5])(int, int);
	int	result;

	tab[0] = &plus;
	tab[1] = &minus;
	tab[2] = &multiply;
	tab[3] = &divide;
	tab[4] = &modulo;
	result = 0;
	if (check_validity(argc, argv) == 0)
		return (0);
	result = operate(argv, tab);
	ft_putnbr(result);
	write(1, "\n", 1);
	return (0);
}
