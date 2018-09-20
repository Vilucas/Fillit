/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetris3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viclucas <viclucas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 19:58:00 by viclucas          #+#    #+#             */
/*   Updated: 2017/12/13 16:42:27 by vimarkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"

static int			ft_count_x(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\n')
	{
		if (str[i] == '#')
			return (1);
		i++;
	}
	return (0);
}

static int			ft_count_y(char *str, int size)
{
	if (size >= 5)
	{
		if (str[size - 5] == '#')
			return (1);
	}
	if (size >= 10)
	{
		if (str[size - 5] == '#' || str[size - 10] == '#')
			return (1);
	}
	if (size <= 13)
	{
		if (str[size + 5] == '#')
			return (1);
	}
	if (size <= 8)
	{
		if (str[size + 10] == '#')
			return (1);
	}
	return (0);
}

static void			ft_is_char2(char *str, int *i, int *y, int *size)
{
	if (str[*i + 1] != '\n' && str[*i - 1] != '\n' &&
		ft_count_x(str + (*i - 4)) == 1)
	{
		*y = *y + 1;
	}
	else if (str[*i + 1] == '\n')
	{
		*i = *i + 1;
		*y = 0;
		*size = 0;
	}
}

static void			ft_is_char(char *str, int *size, int *i, int *x)
{
	if (ft_count_x(str + *i) == 0 && str[*i - 1] == '\n')
	{
		*i = *i + 4;
		*size = *size + 4;
	}
	if (ft_count_x(str + *i) == 1 &&
			(ft_count_y(str + *i - *size, *size) == 1))
		*x = *x + 1;
}

int					*ft_tetris(char *str)
{
	t_cord	x;
	int		*result;

	x.size = 0;
	x.i = 0;
	x.pos = 0;
	x.x2 = 0;
	x.y2 = 0;
	if (!(result = (int*)malloc(sizeof(int) * count_block(str) * 8)))
		return (NULL);
	while (str[x.i])
	{
		if (str[x.i] == '.')
			ft_is_char(str, &x.size, &x.i, &x.x2);
		else if (str[x.i] == '#')
			ft_needsomeplace(&*result, &x.pos, &x.y2, &x.x2);
		if (str[x.i] == '\n')
		{
			ft_is_char2(str, &x.i, &x.y2, &x.size);
			x.x2 = 0;
		}
		x.size++;
		x.i++;
	}
	return (result);
}
