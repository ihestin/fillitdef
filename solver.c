/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihestin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 13:29:35 by ihestin           #+#    #+#             */
/*   Updated: 2018/01/24 13:29:40 by ihestin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		findplace(t_gril g, t_tt *t, int i, int p)
{
	t_deftet	*d;
	t_imap		te;
	t_imap		*gr;

	p = (t[i][2] == -1 && t[i][1] != -1) ? t[t[i][1]][2] : t[i][2];
	d = g_tabinfo + t[i][0];
	te = d->form;
	while (((++p >> 4) + d->fh) <= t[26][1])
	{
		gr = (t_imap*)(g + 2 * (p >> 4));
		while (((p & 15) + d->fl <= t[26][1]))
		{
			if (((d->form << (p & 15)) & (*gr)) == 0)
			{
				t[i][2] = p;
				(*gr) = (*gr) ^ (d->form << (p & 15));
				return (1);
			}
			p++;
		}
		p = p | 15;
	}
	return (0);
}

void	enleve(t_gril g, t_tt *t, int i)
{
	t_imap	te;
	t_imap	*gr;
	int		coor;
	int		dg;
	int		dt;

	coor = t[i][2];
	dg = coor >> 3;
	dt = coor & 7;
	te = g_tabinfo[t[i][0]].form;
	te = (dt == 0) ? te : te << dt;
	gr = (t_imap*)(g + dg);
	(*gr) = (*gr) ^ te;
	t[i + 1][2] = -1;
}

int		resolve(t_gril g, t_tt *t)
{
	int i;

	i = 0;
	t[0][2] = -1;
	while (i >= 0 && i < t[26][0])
		if (findplace(g, t, i, i))
			i++;
		else
		{
			if (--i >= 0)
				enleve(g, t, i);
		}
	if (i < 0)
		return (1);
	return (0);
}
