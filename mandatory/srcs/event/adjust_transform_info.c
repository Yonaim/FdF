/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adjust_transform_info.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhkim <yeonhkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 06:03:43 by yona              #+#    #+#             */
/*   Updated: 2023/01/22 17:43:39 by yeonhkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	adjust_pos_or_rot_value(int keycode, \
					t_position *pos, t_rotation *rot)
{
	pos->x += (keycode == KEY_D) * 5;
	pos->x -= (keycode == KEY_A) * 5;
	pos->y += (keycode == KEY_W) * 5;
	pos->y -= (keycode == KEY_S) * 5;
	pos->z += (keycode == KEY_Z) * 5;
	pos->z -= (keycode == KEY_X) * 5;
	rot->x += (keycode == KEY_O) * 5;
	rot->x -= (keycode == KEY_I) * 5;
	rot->y += (keycode == KEY_L) * 5;
	rot->y -= (keycode == KEY_K) * 5;
	rot->z += (keycode == KEY_MORE) * 5;
	rot->z -= (keycode == KEY_LESS) * 5;
}

void	adjust_transform_info(int keycode, t_fdf *f)
{
	if (keycode == KEY_PLUS)
		f->obj.elevation += 0.5;
	else if (keycode == KEY_MINUS)
		f->obj.elevation -= 0.5;
	else
	{
		if (f->set.mode == CAMERA_ADJUST_MODE)
			adjust_pos_or_rot_value(keycode, &f->cam.pos, &f->cam.rot);
		else
			adjust_pos_or_rot_value(keycode, &f->obj.pos, &f->obj.rot);
	}
}
