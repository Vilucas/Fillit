/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viclucas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 17:44:38 by viclucas          #+#    #+#             */
/*   Updated: 2017/12/14 16:57:59 by vimarkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# define BUFF_SIZE 600

typedef struct	s_cord
{
	int		x2;
	int		y2;
	int		i;
	int		pos;
	int		size;
	int		count;
	int		fd;
	int		ret;
	int		size_result;
	int		y;
	char	*p;
	int		*tetris;
}				t_cord;

void			ft_putstr(char *str);
char			*ft_open(t_cord x, char *argv);
void			ft_one_piece(char *str, int *tab, int size_result);
void			ft_putchar(char c);
void			ft_start(char*str, int *tab, int size_result);
void			ft_free_tab(char **str);
void			ft_print(char **result, int mal);
void			ft_put_into(int *tab, char **result, int x2, int y2);
int				ft_treat_block(int *tab, char **result, t_cord coo,
				int size_result);
char			**ft_tetris_tab(char **result, int size);
void			ft_needsomeplace(int *result, int *pos, int *y, int *x);
int				ft_check_all(char *p);
int				ft_fillit(int *tab, char **result, int size_result, char *str);
int				*ft_tetris(char *str);
int				count_block(char *str);

#endif
