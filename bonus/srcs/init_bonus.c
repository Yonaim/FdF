/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhkim <yeonhkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 11:28:59 by yeonhkim          #+#    #+#             */
/*   Updated: 2023/01/22 18:56:51 by yeonhkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	init_mlx(t_mlx *mlx, char *path)
{
	mlx->conn = mlx_init();
	mlx->win = mlx_new_window(mlx->conn, WIN_WIDTH, WIN_HEIGHT, path);
	mlx->img.obj = mlx_new_image(mlx->conn, WIN_WIDTH, WIN_HEIGHT);
	mlx->img.data = mlx_get_data_addr(mlx->img.obj, &mlx->img.bits_per_pixel, \
		&mlx->img.bytes_per_line, &mlx->img.endian);
	mlx->img.data_size = mlx->img.bytes_per_line * WIN_HEIGHT;
	mlx->img.width = WIN_WIDTH;
	mlx->img.height = WIN_HEIGHT;
}

void	init_settings(t_settings *set)
{
	set->mode = CAMERA_ADJUST_MODE;
	set->manual = false;
	set->axis = true;
}

void	init_object(t_object *obj, t_mesh *mesh)
{
	const double	init_scale = fmax((WIN_WIDTH * 0.3) / mesh->v_per_row, \
									(WIN_HEIGHT * 0.3) / mesh->v_per_col);

	obj->mesh = mesh;
	obj->out = malloc(sizeof(t_vector) * mesh->v_cnt);
	obj->pos = (t_position){0, 0, 0, 1};
	obj->rot = (t_rotation){0, 0, 0};
	obj->scale = init_scale;
	obj->elevation = 1;
}

void	init_camera(t_camera *cam)
{
	cam->pos = (t_position){0, 0, 0, 1};
	cam->rot.x = -45;
	cam->rot.y = -(atan(1 / sqrt(2))) / M_PI * 180;
	cam->rot.z = 30;
	cam->zoom = 1;
}
