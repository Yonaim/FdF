/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_settings_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhkim <yeonhkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 06:03:04 by yona              #+#    #+#             */
/*   Updated: 2023/01/22 18:56:51 by yeonhkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	change_settings(int keycode, t_fdf *f)
{
	if (keycode == KEY_F1)
		f->set.manual = (f->set.manual == false);
	else if (keycode == KEY_TAB && f->set.mode == CAMERA_ADJUST_MODE)
		f->set.mode = OBJECT_ADJUST_MODE;
	else if (keycode == KEY_TAB && f->set.mode == OBJECT_ADJUST_MODE)
		f->set.mode = CAMERA_ADJUST_MODE;
	else if (keycode == KEY_ALT)
		f->set.axis = (f->set.axis == false);
}
