/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhkim <yeonhkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 03:08:08 by yona              #+#    #+#             */
/*   Updated: 2023/01/22 16:02:46 by yeonhkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	mouse_hook(int button, int x, int y, t_fdf *f)
{
	x++;
	y++;
	if (button == MOUSE_WHEEL_UP && f->cam.zoom < 20)
		f->cam.zoom *= 1.2;
	else if (button == MOUSE_WHEEL_DOWN && f->cam.zoom > 0.1)
		f->cam.zoom /= 1.2;
	return (0);
}
