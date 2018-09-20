/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimarkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 14:53:49 by vimarkov          #+#    #+#             */
/*   Updated: 2017/12/14 18:26:05 by vimarkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"

char	*ft_open(t_cord x, char *argv)
{
	char	*p;

	x.size_result = 2;
	x.ret = 0;
	if (!(p = (char*)malloc(sizeof(char) * BUFF_SIZE + 1)))
		return (NULL);
	x.fd = open(argv, O_RDONLY);
	if (x.fd == -1)
	{
		write(1, "error\n", 6);
		return (0);
	}
	if (!(x.ret = read(x.fd, p, BUFF_SIZE)))
	{
		write(1, "error\n", 6);
		return (0);
	}
	p[x.ret] = '\0';
	if (close(x.fd) == -1)
		return (0);
	return (p);
}

int		ft_param(int argc)
{
	if (argc != 2)
	{
		ft_putstr("usage: ./fillit source_file\n");
		return (0);
	}
	return (1);
}

int		ft_limit(char *str)
{
	if (count_block(str) > 26)
	{
		write(1, "error\n", 6);
		return (0);
	}
	return (1);
}

int		main(int argc, char **argv)
{
	t_cord	x;

	x.size_result = 2;
	if (ft_param(argc) == 0)
		return (0);
	if (!(x.p = ft_open(x, argv[1])))
		return (0);
	if (ft_limit(x.p) == 0)
		return (0);
	if (!(ft_check_all(x.p)))
	{
		write(1, "error\n", 6);
		return (0);
	}
	if (!(x.tetris = (int*)malloc(sizeof(int) * count_block(x.p) * 8)))
		return (0);
	x.tetris = ft_tetris(x.p);
	if (count_block(x.p) == 1)
	{
		ft_one_piece(x.p, x.tetris, x.size_result);
		return (0);
	}
	ft_start(x.p, x.tetris, x.size_result);
	free(x.p);
	return (0);
}
