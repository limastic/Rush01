/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diheidjiej.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfaust <nfaust@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 18:31:59 by nfaust            #+#    #+#             */
/*   Updated: 2022/07/17 18:32:04 by nfaust           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_get_i_j(int i, int tab[2])
{
	if (i < 4)
	{
		tab[0] = 0;
		tab[1] = i + 1;
	}
	else if (i < 8)
	{
		tab[0] = 0;
		tab[1] = (i - 3) * -1;
	}
	else if (i < 12)
	{
		tab[0] = i - 7;
		tab[1] = 0;
	}
	else
	{
		tab[0] = (i - 11) * -1;
		tab[1] = 0;
	}
}