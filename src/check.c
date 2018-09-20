/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viclucas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 12:30:27 by viclucas          #+#    #+#             */
/*   Updated: 2017/12/13 17:47:15 by vimarkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"

static int		ft_strlen2(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n' && str[i + 1] == '\n')
			return (i);
		i++;
	}
	return (i);
}

int				ft_check_diez(char *str)
{
	int i;
	int count;

	count = 0;
	i = 0;
	while (i < 20)
	{
		if (str[i] == '#')
		{
			if (str[i + 1] == '#')
				count++;
			if (str[i + 5] == '#' && i < 15)
				count++;
			if (str[i - 5] == '#' && i > 4)
				count++;
			if (str[i - 1] == '#')
				count++;
		}
		i++;
	}
	if (count == 6 || count == 8)
		return (1);
	return (0);
}

static int		ft_check_block(char *str)
{
	int i;
	int x;

	x = 0;
	i = 0;
	while (i < 20 && str[i])
	{
		if (i != 4 && i != 9 && i != 14 && i != 19)
			if (str[i] != '.' && str[i] != '#')
				return (0);
		if (i == 4 || i == 9 || i == 14 || i == 19)
			if (str[i] != '\n')
				return (0);
		if (str[i] == '#')
			x++;
		i++;
	}
	if (i != 20 || x != 4)
		return (0);
	return (1);
}

int				ft_check_tetri(char *p, int u, int *i)
{
	while (u)
	{
		if (ft_check_diez(p + *i) == 0)
			return (0);
		*i = *i + 21;
		u--;
	}
	return (1);
}

int				ft_check_all(char *p)
{
	int		i;
	int		u;

	i = 0;
	u = count_block(p);
	if (!p || (p[0] != '.' && p[0] != '#'))
		return (0);
	while (p[i])
	{
		if (ft_check_block(p + i) == 0)
			return (0);
		if (ft_strlen2(p + i) > 20)
			return (0);
		i = i + ft_strlen2(p + i) + 1;
		if (p[i] == '\n' && p[i + 1] == '\0')
			return (0);
		i++;
	}
	i = 0;
	if (ft_check_tetri(p, u, &i) == 0)
		return (0);
	return (1);
}
