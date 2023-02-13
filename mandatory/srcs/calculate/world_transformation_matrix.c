/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world_transformation_matrix.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhkim <yeonhkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 07:26:11 by yeonhkim          #+#    #+#             */
/*   Updated: 2023/01/22 14:49:02 by yeonhkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_matrix	world_transform_matrix(t_position pos, t_rotation rot, double scale)
{
	t_matrix		m;

	m = unit_matrix();
	compose_rotate_matrix(&m, rot.x, rot.y, rot.z);
	compose_move_matrix(&m, pos.x, pos.y, pos.z);
	compose_scale_matrix(&m, scale, scale, scale);
	return (m);
}
