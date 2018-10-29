/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_fic.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihestin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 08:48:27 by ihestin           #+#    #+#             */
/*   Updated: 2018/01/17 00:12:18 by abossard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <unistd.h>
#include <fcntl.h>

t_irmap	reduct(t_trmap m)
{
	t_trmap t;
	int		i;

	if (m.itm < 15)
		exit_msg(2);
	while (m.ctm[0] == 0)
		m.itm = (m.itm >> 8);
	i = -1;
	while (++i < 4)
		t.ctm[i] = 1;
	while ((t.itm & m.itm) == 0)
		m.itm = m.itm >> 1;
	t.ctm[0] = m.ctm[0] + (16 * m.ctm[1]);
	t.ctm[1] = m.ctm[2] + (16 * m.ctm[3]);
	t.ctm[2] = 0;
	t.ctm[3] = 0;
	return (t.itm);
}

t_irmap	caltrmap(t_tl *t, int i)
{
	t_trmap	m;
	int		j;
	int		nb;

	i = -1;
	m.itm = 0;
	while (++i < 4)
	{
		if (t[i][4] != '\n')
			exit_msg(2);
		nb = 1;
		j = -1;
		while (++j < 4)
		{
			if (t[i][j] != '.')
			{
				if (t[i][j] == '#')
					m.ctm[i] = m.ctm[i] + nb;
				else
					exit_msg(2);
			}
			nb = nb * 2;
		}
	}
	return (reduct(m));
}

void	insl(char *s, int n, t_tt *t)
{
	t_tl		*tt;
	t_irmap		te;
	int			i;
	int			j;

	if (s[20] != '\n')
		exit_msg(2);
	tt = (t_tl*)s;
	i = 0;
	te = caltrmap(tt, i);
	while (i < 19 && g_tabinfo[i].id != te)
		i++;
	if (i == 19)
		exit_msg(2);
	t[n][0] = i;
	j = n - 1;
	while (j >= 0 && t[j][0] != i)
		j--;
	t[n][1] = j;
	if (j == -1)
		;
	t[n][2] = -1;
	(g_tabinfo[i].nbt)++;
}

void	read_fic(char *nom, t_tt *t)
{
	char	buffer[600];
	int		nb;
	int		i;

	nb = open(nom, O_RDONLY);
	if (nb < 0)
		exit_msg(3);
	i = read(nb, buffer, 600);
	close(nb);
	if (i == 0)
		exit_msg(0);
	if (i < 0 || i % 21 != 20 || i > 545)
		exit_msg(2);
	buffer[i] = '\n';
	nb = i / 21 + 1;
	i = -1;
	while (++i < nb)
		insl(buffer + 21 * i, i, t);
	t[26][0] = nb;
}
