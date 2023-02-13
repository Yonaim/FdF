/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_transform_info.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhkim <yeonhkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 14:48:30 by yeonhkim          #+#    #+#             */
/*   Updated: 2023/01/22 14:48:34 by yeonhkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	reset_transform_info(int keycode, t_fdf *f)
{
	keycode++;
	f->obj.pos = (t_position){0, 0, 0, 1};
	f->obj.rot = (t_rotation){0, 0, 0};
	f->obj.elevation = 1;
	f->cam.pos = (t_position){0, 0, 0, 1};
	f->cam.rot = (t_rotation){0, 0, 0};
	f->cam.zoom = 1;
}
