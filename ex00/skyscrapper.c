/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skyscrapper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfaust <nfaust@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 11:57:39 by nfaust            #+#    #+#             */
/*   Updated: 2022/07/17 17:35:32 by nfaust           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void	ft_solve(char *str, char tab[4][4]);
int		ft_check_for_errors(int argc, char **argv);

void	ft_delete_spaces(char *str, char *dest)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] != 32)
		{
			dest[j] = str[i];
			j++;
		}
		i++;
	}
}

void	ft_put_tab(char tab[4][4])
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < 4)
	{
		while (j < 4)
		{
			write(1, &tab[i][j], 1);
			if (j < 3)
				write(1, " ", 1);
			j++;
		}
		i++;
		j = 0;
		write(1, "\n", 1);
	}
}

void	ft_create_tab(char tab[4][4])
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < 4)
	{
		while (j < 4)
		{
			if (tab[i][j] == 0)
				tab[i][j] = 0 + '0';
			j++;
		}
		i++;
		j = 0;
	}
}

int	main(int argc, char *argv[])
{
	char	tab[4][4];
	char	dest[17];

	if (ft_check_for_errors(argc, argv))
		return (0);
	ft_delete_spaces(argv[1], dest);
	ft_solve(dest, tab);
	ft_create_tab(tab);
	ft_put_tab(tab);
}
