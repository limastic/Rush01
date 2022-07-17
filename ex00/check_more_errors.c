/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_more_errors.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfaust <nfaust@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 02:01:07 by nfaust            #+#    #+#             */
/*   Updated: 2022/07/17 19:00:32 by nfaust           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_put_error(void)
{
	char	*error;
	int		i;

	error = "Error\n";
	i = 0;
	while (error[i])
	{
		write(1, &error[i], 1);
		i++;
	}
}

int	ft_char_is_numeric_under_five(char cha)
{
	if ('0' >= cha || cha > '4')
	{
		return (0);
	}
	return (1);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_check_for_forbidden_pairs(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((i < 8 || i > 16) && i < 24)
		{
			if (str[i] == '4' && str[i + 8] != '1')
				return (1);
			else if (str[i] == '3' && str[i + 8] == '3')
				return (1);
			else if (str[i] == '1' && str[i + 8] == '1')
				return (1);
		}
		else if (i == 8)
			i = 16;
		else if (i == 24)
			return (0);
		i += 2;
	}
	return (0);
}
