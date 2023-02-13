/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preset_transform_info.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhkim <yeonhkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 14:48:22 by yeonhkim          #+#    #+#             */
/*   Updated: 2023/01/22 18:39:04 by yeonhkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	preset_transform_info_general(int keycode, t_fdf *f)
{
	reset_transform_info(keycode, f);
	if (keycode == KEY_PAD_1)
		f->cam.rot = (t_rotation){90, 90, 0};
	else if (keycode == KEY_PAD_2)
		f->cam.rot = (t_rotation){90, 0, 0};
	else if (keycode == KEY_PAD_3)
		f->cam.rot = (t_rotation){90, -90, 0};
	else if (keycode == KEY_PAD_7)
		f->cam.rot = (t_rotation){-90, 90, 0};
	else if (keycode == KEY_PAD_8)
		f->cam.rot = (t_rotation){-90, 0, 0};
	else if (keycode == KEY_PAD_9)
		f->cam.rot = (t_rotation){-90, -90, 0};
	else if (keycode == KEY_PAD_4)
		f->cam.rot = (t_rotation){0, 90, 0};
	else if (keycode == KEY_PAD_5)
		f->cam.rot = (t_rotation){0, 0, 0};
	else if (keycode == KEY_PAD_6)
		f->cam.rot = (t_rotation){0, -90, 0};
}

void	preset_transform_info_isometric(int keycode, t_fdf *f)
{
	const double	v[3] = {
		45, (atan(1 / sqrt(2))) / M_PI * 180, 30
	};

	reset_transform_info(keycode, f);
	if (keycode == KEY_1)
		f->cam.rot = (t_rotation){-v[0], -v[1], v[2]};
	else if (keycode == KEY_2)
		f->cam.rot = (t_rotation){-v[0], v[1], -v[2]};
	else if (keycode == KEY_3)
		f->cam.rot = (t_rotation){v[0], v[1], v[2]};
	else if (keycode == KEY_4)
		f->cam.rot = (t_rotation){v[0], -v[1], -v[2]};
	else if (keycode == KEY_5)
		f->cam.rot = (t_rotation){-v[0], v[1], v[2]};
	else if (keycode == KEY_6)
		f->cam.rot = (t_rotation){-v[0], -v[1], -v[2]};
	else if (keycode == KEY_7)
		f->cam.rot = (t_rotation){v[0], -v[1], v[2]};
	else if (keycode == KEY_8)
		f->cam.rot = (t_rotation){v[0], v[1], -v[2]};
}
