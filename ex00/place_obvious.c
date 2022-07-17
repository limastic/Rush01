/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_obvious.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfaust <nfaust@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 18:29:29 by nfaust            #+#    #+#             */
/*   Updated: 2022/07/17 20:11:14 by nfaust           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_get_i_j(int i, int tab[2]);

void	ft_put_1234(int index, char tab[4][4], int tab_i_j[2])
{
	int	j;

	if (tab_i_j[index] < 0)
	{
		tab_i_j[index] *= -1;
		j = 3;
		while (j >= 0)
		{
			if (index)
				tab[j][tab_i_j[index] - 1] = (4 - j) + '0';
			else
				tab[tab_i_j[index] - 1][j] = (4 - j) + '0';
			j--;
		}
	}
	else
	{
		j = 0;
		while (j < 4)
		{
			if (index)
				tab[j][tab_i_j[index] - 1] = (j + 1) + '0';
			else
				tab[tab_i_j[index] - 1][j] = (j + 1) + '0';
			j++;
		}
	}
}

void	ft_add_number(char tab[4][4], int *tab_i_j, char number)
{
	int	j;
	int	index;

	if (tab_i_j[0])
		index = 0;
	else
		index = 1;
	if (tab_i_j[index] < 0)
	{
		tab_i_j[index] *= -1;
		if (index)
			tab[3][tab_i_j[index] - 1] = number + '0';
		else
			tab[tab_i_j[index] - 1][3] = number + '0';
	}
	else
	{
		if (index)
			tab[tab_i_j[index] - 1][0] = number + '0';
		else
		{
			tab[0][tab_i_j[index] - 1] = number + '0';
		}
	}
}

void	ft_fill(int tab_i_j[2], char tab[4][4])
{
	if (tab_i_j[0])
		ft_put_1234(0, tab, tab_i_j);
	else if (tab_i_j[1])
		ft_put_1234(1, tab, tab_i_j);
}

void	ft_place_obvious(char *str, char tab[4][4])
{
	int	i;
	int	tab_i_j[2];
	int	face_2;
	int j;

	i = 0;
	j = 0;
	face_2 = 0;
	while (str[i])
	{
		if (str[i] == '4')
		{
			ft_get_i_j(i, tab_i_j);
			ft_fill(tab_i_j, tab);
		}
		else if (str[i] == '1')
		{
			if (str[i + 4] == '2')
				face_2 = 1;
			ft_get_i_j(i, tab_i_j);
			ft_add_number(tab, tab_i_j, 4);
		}
		if (face_2)
		{
			while (j < 2)
			{
				if (tab_i_j[j])
				{
					tab_i_j[j] *= -1;
				}
				j++;
			}
			face_2 = 0;
			j = 0;
			ft_add_number(tab, tab_i_j, 3);
		}
		i++;
	}
}
