/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_transformation.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yona <yona@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 07:27:08 by yeonhkim          #+#    #+#             */
/*   Updated: 2023/01/21 03:13:24 by yona             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_matrix	camera_transform_matrix(t_camera *cam)
{
	t_matrix	m;

	m = unit_matrix();
	compose_scale_matrix(&m, cam->zoom, cam->zoom, cam->zoom);
	compose_move_matrix(&m, -cam->pos.x, -cam->pos.y, -cam->pos.z);
	compose_rotate_matrix(&m, -cam->rot.x, -cam->rot.y, -cam->rot.z);
	return (m);
}
