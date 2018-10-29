/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihestin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 10:05:14 by ihestin           #+#    #+#             */
/*   Updated: 2018/01/20 09:45:16 by abossard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

typedef unsigned long	t_imap;
typedef unsigned int	t_irmap;
typedef unsigned char	t_cmap;
typedef	union			u_tmap
{
	t_imap				itm;
	t_cmap				ctm[8];
}						t_tmap;
typedef	union			u_trmap
{
	t_irmap				itm;
	t_cmap				ctm[4];
}						t_trmap;
typedef	t_cmap			t_gril[40];
typedef int				t_tt[3];
typedef char			t_tl[5];
typedef struct			s_deftet
{
	t_irmap				id;
	t_imap				form;
	int					fam;
	int					fh;
	int					fl;
	int					coord[4];
	int					nbt;
}						t_deftet;
void					exit_msg(int i);
void					read_fic(char *str, t_tt *tet);
void					ft_init();
void					cal_si(t_tt *tet);
void					g_init(t_gril g, int nb);
int						resolve(t_gril g, t_tt *tet);
void					resize(t_tt *tet);
void					affiche(t_tt *tet);
extern	t_deftet		g_tabinfo[19];

#endif
