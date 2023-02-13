/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_object_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhkim <yeonhkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 10:38:24 by yeonhkim          #+#    #+#             */
/*   Updated: 2023/01/22 18:56:51 by yeonhkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"
#include "render_bonus.h"

static void	draw_object(t_img *img, t_vertex *v_arr, int *c_arr, t_mesh *mesh)
{
	const int	w = WIN_WIDTH / 2;
	const int	h = WIN_HEIGHT / 2;
	t_pixel		p[3];
	int			i;

	i = 0;
	while (i < mesh->v_cnt)
	{
		p[ORI] = (t_pixel){v_arr[i].x + w, v_arr[i].y + h, c_arr[i]};
		if ((i + 1) % mesh->v_per_row != 0)
		{
			p[NEXT] = (t_pixel){\
						v_arr[i + 1].x + w, v_arr[i + 1].y + h, c_arr[i + 1]};
			draw_line(img, p[ORI], p[NEXT]);
		}
		if ((i + mesh->v_per_row) < mesh->v_cnt)
		{
			p[BELOW] = (t_pixel){v_arr[i + mesh->v_per_row].x + w, \
				v_arr[i + mesh->v_per_row].y + h, c_arr[i + mesh->v_per_row]};
			draw_line(img, p[ORI], p[BELOW]);
		}
		i++;
	}
}

void	render_object(t_img *img, t_object *obj, t_camera *cam)
{
	const double	origin_dx = (obj->mesh->v_per_row - 1) / 2;
	const double	origin_dy = (obj->mesh->v_per_col - 1) / 2;
	t_matrix		m;
	int				i;

	m = unit_matrix();
	compose_move_matrix(&m, -origin_dx, -origin_dy, 0);
	compose_scale_matrix(&m, 1, 1, obj->elevation);
	m = matmul(m, world_transform_matrix(obj->pos, obj->rot, obj->scale));
	m = matmul(m, camera_transform_matrix(cam));
	i = 0;
	while (i < obj->mesh->v_cnt)
	{
		obj->out[i] = linear_transform(m, obj->mesh->v_arr[i]);
		i++;
	}
	draw_object(img, obj->out, obj->mesh->c_arr, obj->mesh);
}
