/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolve.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viclucas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 12:16:11 by viclucas          #+#    #+#             */
/*   Updated: 2017/12/13 16:46:55 by vimarkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"

int		ft_var(char **tab)
{
	t_cord	coo;
	int		find;

	find = 0;
	coo.count = 0;
	coo.x2 = 0;
	coo.y2 = 0;
	while (tab[coo.y2])
	{
		while (tab[coo.y2][coo.x2])
		{
			if (tab[coo.y2][coo.x2] >= 'A' && tab[coo.y2][coo.x2] <= 'Z')
				coo.count++;
			if (coo.count == 4)
			{
				find++;
				coo.count = 0;
			}
			coo.x2++;
		}
		coo.x2 = 0;
		coo.y2++;
	}
	return (find);
}

void	ft_allocate_result(char ***result, char ***stock)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while ((*stock)[i][j])
	{
		while ((*stock)[i][j])
		{
			if ((*stock)[i][j] >= 'A' && (*stock)[i][j] <= 'Z')
				(*result)[i][j] = (*stock)[i][j];
			j++;
		}
		j = 0;
		i++;
	}
}

char	**ft_tetris_tab(char **result, int size)
{
	int y;
	int i;

	i = 0;
	y = 0;
	if (!(result = (char**)malloc(sizeof(*result) * (size + 1))))
		return (NULL);
	while (y < size)
	{
		if (!(result[y] = (char*)malloc(sizeof(**result) * (size + 2))))
			return (NULL);
		while (i < (size + 1))
		{
			if (i == size)
				result[y][i] = '\n';
			else
				result[y][i] = '.';
			i++;
		}
		result[y][i] = '\0';
		i = 0;
		y++;
	}
	result[y] = NULL;
	return (result);
}

int		ft_treat_block(int *tab, char **result, t_cord coo, int size_result)
{
	int i;
	int x;
	int y;

	i = 0;
	while (i < 8)
	{
		x = tab[i + 1] + coo.x2;
		y = tab[i] + coo.y2;
		if (x >= size_result || y >= size_result)
			return (0);
		if ((result[y][x] >= 'A' && result[y][x] <= 'Z')
				|| result[y][x] == '\n' || result[y][x] == '\0')
		{
			return (0);
		}
		i = i + 2;
	}
	return (1);
}

void	ft_put_into(int *tab, char **result, int x2, int y2)
{
	int i;
	int y;
	int x;
	int var;

	var = 'A' + ft_var(result);
	i = 0;
	while (i < 8)
	{
		x = tab[i + 1] + x2;
		y = tab[i] + y2;
		result[y][x] = var;
		i = i + 2;
	}
}
