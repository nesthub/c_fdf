/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf_menu_mouse.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/09 15:01:51 by mlinhard          #+#    #+#             */
/*   Updated: 2016/11/20 21:19:58 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

void	menu_mouserelease(t_data *d, t_menu *m, int x, int y)
{
	((d->l = m->start) && m->u == 1 && mr(ARROWU, x, y)
	&& (m->start = m->start->n)
	&& (m->calcpos = 1)) ?
	(d->loopstop = loop(1) + 60) : 1;
	(m->d == 1 && mr(ARROWD, x, y) && (m->start = m->start->p)
	&& (m->calcpos = 1)) ?
	(d->loopstop = loop(1) + 60) : 1;
	while (d->l && d->l->id <= (m->start->id + 9))
	{
		if (d->mx >= d->l->area[2] && d->mx <= d->l->area[4]
		&& d->my >= d->l->area[3] && d->my <= d->l->area[5])
		{
			if (d->map.status < 1 && (m->over = d->l))
			{
				((m->open = 3)
				&& ((m->yclose = d->l->area[1]) || 1)) ?
				fmap(d, -1, 0) : 1;
				d->loopstop = 0;
				ft_printf("%!./maps/%s", &d->map.path, d->l->path);
				(d->map.status = 1) ? loop(1) : 0;
			}
			break ;
		}
		d->l = d->l->p;
	}
}

void	menu_mouseover(t_data *d, t_menu *m, t_lmenu *l)
{
	while (l && l->id <= (m->start->id + 9))
	{
		if (d->mx >= l->area[2] && d->mx <= l->area[4]
		&& d->my >= l->area[3] && d->my <= l->area[5])
		{
			m->mo = MENU;
			d->loopstop = loop(1) + 50;
			return ;
		}
		l = l->p;
	}
	if (((m->u && mo(ARROWU) && m->mo != ARROWU && (m->mo = ARROWU))
	|| (m->u && !mo(ARROWU) && m->mo == ARROWU && !(m->mo = INIT))
	|| (m->d && mo(ARROWD) && m->mo != ARROWD && (m->mo = ARROWD))
	|| (m->d && !mo(ARROWD) && m->mo == ARROWD && !(m->mo = INIT)))
	&& (d->loopstop = loop(1) + 50))
		return ;
	if (m->mo == MENU && ((m->mo = INIT) || 1))
		d->loopstop = loop(1) + 50;
}
