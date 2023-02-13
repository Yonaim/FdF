/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress_hook_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhkim <yeonhkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 03:08:17 by yona              #+#    #+#             */
/*   Updated: 2023/01/22 18:56:51 by yeonhkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

static int	type_of_keycode(int keycode)
{
	if (keycode == KEY_ESC)
		return (0);
	else if (keycode == KEY_F1 || keycode == KEY_TAB || keycode == KEY_ALT)
		return (1);
	else if (keycode == KEY_R)
		return (2);
	else if (keycode == KEY_D || keycode == KEY_A || keycode == KEY_W || \
			keycode == KEY_S || keycode == KEY_Z || keycode == KEY_X || \
			keycode == KEY_O || keycode == KEY_I || keycode == KEY_L || \
			keycode == KEY_K || keycode == KEY_MORE || keycode == KEY_LESS || \
			keycode == KEY_PLUS || keycode == KEY_MINUS)
		return (3);
	else if (keycode == KEY_1 || keycode == KEY_2 || keycode == KEY_3 || \
			keycode == KEY_4 || keycode == KEY_5 || keycode == KEY_6 || \
			keycode == KEY_7 || keycode == KEY_8 || keycode == KEY_9 || \
			keycode == KEY_0)
		return (4);
	else if (keycode != 90 && \
							KEY_PAD_1 <= keycode && keycode <= KEY_PAD_9)
		return (5);
	else
		return (-1);
}

int	keypress_hook(int keycode, t_fdf *f)
{
	const int				keycode_type = type_of_keycode(keycode);
	const t_event_handle	event_func[6] = {
		NULL, change_settings, \
		reset_transform_info, adjust_transform_info,
		preset_transform_info_isometric, preset_transform_info_general
	};

	if (keycode_type == 0)
		exit(0);
	else if (keycode_type == -1)
		return (0);
	else
		event_func[keycode_type](keycode, f);
	return (0);
}
