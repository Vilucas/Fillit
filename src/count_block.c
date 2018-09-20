/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_block.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viclucas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 17:38:16 by viclucas          #+#    #+#             */
/*   Updated: 2017/12/13 19:17:42 by vimarkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"

int		count_block(char *str)
{
	int compteur;
	int i;

	i = 0;
	compteur = 0;
	while (str[i])
	{
		if (str[i] == '\n' && (str[i + 1] == '\n' || str[i + 1] == '\0'))
			compteur++;
		i++;
	}
	return (compteur);
}
