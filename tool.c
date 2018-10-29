/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihestin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 10:12:40 by ihestin           #+#    #+#             */
/*   Updated: 2018/01/30 11:34:34 by ihestin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "fillit.h"

void	cal_si(t_tt *t)
{
	int		i;
	int		j;

	i = 4 * t[26][0];
	j = 1;
	while (j * j < i)
		j++;
	t[26][1] = j;
	resize(t);
}

void	affiche(t_tt *t)
{
	char	buffer[250];
	int		i;
	int		j;
	int		cot;
	int		nb;

	cot = t[26][1];
	i = -1;
	while (++i < cot * (cot + 1))
		buffer[i] = (i % (cot + 1) == cot) ? '\n' : '.';
	i = -1;
	while (++i < t[26][0])
	{
		j = -1;
		while (++j < 4)
		{
			nb = t[i][2] + g_tabinfo[t[i][0]].coord[j];
			nb = (nb >> 4) * (cot + 1) + (nb & 15);
			buffer[nb] = 'A' + i;
		}
	}
	write(1, buffer, cot * (cot + 1));
}
