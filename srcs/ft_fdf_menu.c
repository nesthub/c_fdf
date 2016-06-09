/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf_menu.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/06 19:43:55 by mlinhard          #+#    #+#             */
/*   Updated: 2016/06/09 11:04:31 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

int		menu_btn(t_data *d, t_lmenu *m)
{
	ft_printf("%d,%d -> %d\n", d->mx, d->my, mo(477, 124, 725, 559));
	return (1);
}

int		menu_data(t_data *d, t_lmenu *new, DIR *dir, struct dirent *f)
{
	(!(d->i = 0) && d->menu.lst) ? flmenu(d) : 0;
	if (!(dir = opendir(MAP_DIR)))
		exit1(1, d, "Cant open maps dir.");
	while ((f = readdir(dir)))
	{
		if (f->d_namlen > 4095 || !ft_strcmp(".", f->d_name)
		|| !ft_strcmp("..", f->d_name) || !ft_strcmp(".DS_Store", f->d_name))
			continue ;
		if (++d->i && !(new = (t_lmenu *)ft_memalloc(sizeof(t_lmenu))))
			exit1(1, d, "Cant malloc t_lmenu struct.");
		ft_memcpy(new->path, f->d_name, f->d_namlen);
		if (!d->menu.lst && (d->menu.lst = new))
			(!(new->p = (t_lmenu *)NULL)) ?
				new->n = (t_lmenu *)NULL : (t_lmenu *)NULL;
		else if ((new->n = d->menu.lst))
			((d->menu.lst->p = new)) ? d->menu.lst = new : (t_lmenu *)NULL;
	}
	closedir(dir);
	new = d->menu.lst;
	d->menu.size = d->i;
	while (((new->id = d->i--) || 1) && new->n)
		new = new->n;
	d->menu.lst = new;
	d->menu.start = new;
	return (1);
}

void	menu_open(t_data *d, t_img *i, t_menu *m)
{
	if (!(i->img))
		i->img = xtoi(i, XPM_MENU);
	i->i = -4;
	while ((i->i += 4) < (i->sl * WIN_Y))
	{
		if (i->str[i->i] == 0 && i->str[i->i + 1] == 0 && i->str[i->i + 2] == 0)
			i->str[i->i + 3] = 255;
		else
			i->str[i->i + 3] = m->fade;
	}
	(m->fade > 0) ? (m->fade -= 15) : 0;
	itow(i->img, m->xpos, m->ypos, "menu xpm");
	(m->fade == 0 && l(1, "MENU", "OPEN") && l(1, "READDIR", MAP_DIR)
	&& menu_data(d, (t_lmenu *)NULL, (DIR *)NULL, (struct dirent *)NULL)
	&& menu_btn(d, (t_lmenu *)NULL))
	 	? (loop(0)) : 1;
}
