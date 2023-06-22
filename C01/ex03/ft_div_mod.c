/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mprofett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 11:56:43 by mprofett          #+#    #+#             */
/*   Updated: 2022/07/09 18:38:31 by mprofett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
#include <stdio.h>
*/
void	ft_div_mod(int a, int b, int *div, int *mod)
{
	*div = a / b;
	*mod = a % b;
}
/*
int	main()
{
	int	a;
	int	b;
	int	*div;
	int	*mod;
	int	division;
	int reste;

	a = 42;
	b = 23;
	div = &division;
	mod = &reste;
	ft_div_mod(a, b, div, mod);
	printf("%d\n%d", *div, *mod);
	return 0;
}*/
