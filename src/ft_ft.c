/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viclucas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 16:15:33 by viclucas          #+#    #+#             */
/*   Updated: 2017/12/13 16:46:25 by vimarkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
		ft_putchar(str[i++]);
}

void	ft_print(char **result, int mal)
{
	int var1;
	int var2;

	var1 = 0;
	var2 = 0;
	while (var1 < mal)
	{
		while (var2 < mal + 1)
		{
			ft_putchar(result[var1][var2]);
			var2++;
		}
		var2 = 0;
		var1++;
	}
}

void	ft_one_piece(char *str, int *tab, int size_result)
{
	char	**result;
	t_cord	coo;

	coo.x2 = 0;
	coo.y2 = 0;
	result = NULL;
	result = ft_tetris_tab(result, size_result);
	if (ft_treat_block(tab, result, coo, size_result) == 1)
	{
		ft_put_into(tab, result, 0, 0);
		ft_print(result, size_result);
		ft_free_tab(result);
		return ;
	}
	else
	{
		ft_free_tab(result);
		ft_one_piece(str, tab, size_result + 1);
	}
}

void	ft_needsomeplace(int *result, int *pos, int *y, int *x)
{
	result[*pos] = *y;
	*pos = *pos + 1;
	result[*pos] = *x;
	*pos = *pos + 1;
	*x = *x + 1;
}
