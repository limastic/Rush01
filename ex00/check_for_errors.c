/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_for_errors.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfaust <nfaust@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 20:53:52 by nfaust            #+#    #+#             */
/*   Updated: 2022/07/17 18:54:05 by nfaust           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_put_error(void);

int		ft_char_is_numeric_under_five(char cha);

int		ft_strlen(char *str);

int		ft_check_for_forbidden_pairs(char *str);

void	ft_init_counters(int counters[4])
{
	int	i;

	i = 0;
	while (i < 4)
	{
		counters[i] = 0;
		i++;
	}
}

int	ft_check_alternation(char **argv)
{
	int	i;

	i = 0;
	while (argv[1][i])
	{
		if ((i % 2 == 0 && ! ft_char_is_numeric_under_five(argv[1][i]))
		|| (i % 2 == 1 && argv[1][i] != 32))
		{
			return (1);
		}
		i++;
	}
	return (0);
}

int	ft_check_for_errors(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_put_error();
		return (1);
	}
	else if (ft_strlen(argv[1]) != 31)
	{
		ft_put_error();
		return (1);
	}
	if (ft_check_alternation(argv))
	{
		ft_put_error();
		return (1);
	}
	if (ft_check_for_forbidden_pairs(argv[1]))
	{
		ft_put_error();
		return (1);
	}
	return (0);
}
