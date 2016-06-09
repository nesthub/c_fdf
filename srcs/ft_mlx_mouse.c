/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_mouse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/09 10:59:31 by mlinhard          #+#    #+#             */
/*   Updated: 2016/06/09 11:04:47 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

int		mo(int x1, int y1, int x2, int y2)
{
	t_data *d;

	d = data();
	if (d->mx >= x1 && d->mx <= x2 && d->my >= y1 && d->my <= y2)
		return (1);
	return (0);
}
