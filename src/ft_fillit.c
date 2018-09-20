/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viclucas <viclucas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 14:55:23 by vimarkov          #+#    #+#             */
/*   Updated: 2017/12/13 16:45:42 by vimarkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"

char	ft_var2(char **result)
{
	int		i;
	int		j;
	char	var;

	var = 'A';
	i = 0;
	j = 0;
	while (result[i])
	{
		while (result[i][j])
		{
			if ((result[i][j] >= 'A' && result[i][j] <= 'Z')
					&& result[i][j] >= var)
				var = result[i][j];
			j++;
		}
		j = 0;
		i++;
	}
	return (var);
}

void	ft_clear(char **result)
{
	int		i;
	int		j;
	char	var;

	var = ft_var2(result);
	i = 0;
	j = 0;
	while (result[i])
	{
		while (result[i][j])
		{
			if (result[i][j] == var)
				result[i][j] = '.';
			j++;
		}
		j = 0;
		i++;
	}
}

void	ft_free_tab(char **str)
{
	int i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

int		ft_fillit(int *tab, char **result, int size_result, char *str)
{
	t_cord coo;

	coo.x2 = 0;
	coo.y2 = 0;
	if (ft_var2(result) == 'A' + count_block(str) - 1)
		return (1);
	while (coo.y2 < size_result)
	{
		while (coo.x2 < size_result)
		{
			if (ft_treat_block(tab, result, coo, size_result) == 1)
			{
				ft_put_into(tab, result, coo.x2, coo.y2);
				if (ft_fillit(tab + 8, result, size_result, str))
					return (1);
				ft_clear(result);
			}
			coo.x2++;
		}
		coo.x2 = 0;
		coo.y2++;
	}
	return (0);
}

void	ft_start(char *str, int *tab, int size_result)
{
	char **result;

	result = NULL;
	result = ft_tetris_tab(result, size_result);
	while (ft_fillit(tab, result, size_result, str) == 0)
	{
		ft_free_tab(result);
		size_result++;
		result = ft_tetris_tab(result, size_result);
	}
	ft_print(result, size_result);
}
