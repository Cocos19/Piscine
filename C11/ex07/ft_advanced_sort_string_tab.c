/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_string_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mprofett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 19:38:04 by mprofett          #+#    #+#             */
/*   Updated: 2022/07/27 19:38:06 by mprofett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h>

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' || s2[i] != '\0')
	{	
		if (s1[i] != s2[i])
		{
			return (s1[i] - s2[i]);
		}
		i++;
	}
	return (0);
}*/

int	ft_tab_len(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

char	**swap_str(char **tab, int i, int j)
{
	char	*buffer;

	buffer = tab[i];
	tab[i] = tab[j];
	tab[j] = buffer;
	return (tab);
}

void	ft_advanced_sort_string_tab(char **tab, int (*cmp)(char *, char *))
{
	int	i;
	int	j;
	int	len;

	i = 0;
	j = 1;
	len = ft_tab_len(tab);
	while (i < len - 1)
	{
		j = i + 1;
		while (j < len)
		{
			if ((*cmp)(tab[i], tab[j]) > 0)
				tab = swap_str(tab, i, j);
			j++;
		}
		i++;
	}
}

/*int main(void)
{
    char    *tab[6];
    char    str1[6] = "Salut";
    char    str2[3] = "Ca";
    char    str3[3] = "Va";
    char    str4[4] = "Les";
    char    str5[6] = "Potos";
    int i;
    int (*ptr)(char *, char *);

    ptr = &ft_strcmp;
    i = 0;
    tab[0] = str1;
    tab[1] = str2;
    tab[2] = str3;
    tab[3] = str4;
    tab[4] = str5;
    tab[5] = 0;
    ft_advanced_sort_string_tab(tab, ptr);
    while (tab[i])
    {
        printf("%s\n", tab[i]);
        i++;
    }
    return (0);
}*/
