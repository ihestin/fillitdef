/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abossard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 21:05:54 by abossard          #+#    #+#             */
/*   Updated: 2018/01/23 15:54:23 by abossard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "fillit.h"

void	g_init(t_gril gril, int l)
{
	t_trmap mg;
	int		i;

	i = 0;
	while (i < 4)
		mg.ctm[i++] = 255;
	i = 0;
	while (i < 8)
		*((t_irmap *)(gril + i++ * 4)) = mg.itm;
	mg.itm = mg.itm << l;
	i = 0;
	while (i < l)
		*((t_irmap *)(gril + i++ * 2)) = mg.itm;
}

void	map(int i)
{
	t_tmap	orig;
	t_tmap	dest;

	orig.itm = g_tabinfo[i].id;
	dest.itm = 0;
	dest.ctm[0] = orig.ctm[0] % 16;
	dest.ctm[2] = orig.ctm[0] / 16;
	dest.ctm[4] = orig.ctm[1] % 16;
	dest.ctm[6] = orig.ctm[1] / 16;
	g_tabinfo[i].form = dest.itm;
}

void	ft_init(void)
{
	int i;

	i = 0;
	while (i < 19)
	{
		map(i);
		i++;
	}
}
