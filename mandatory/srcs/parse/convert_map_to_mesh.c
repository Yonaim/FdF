/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_map_to_mesh.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yona <yona@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 03:33:22 by yeonhkim          #+#    #+#             */
/*   Updated: 2023/01/21 22:36:42 by yona             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	init_mesh(t_mesh *mesh, int width, int height)
{
	mesh->v_cnt = (width) * (height);
	mesh->v_arr = ft_calloc(mesh->v_cnt, sizeof(t_vector));
	mesh->c_arr = ft_calloc(mesh->v_cnt, sizeof(t_vector));
	mesh->v_per_row = width;
	mesh->v_per_col = height;
}

static int	color_depend_on_value(int cur, int min, int max)
{
	const int	a = cur - min;
	const int	b = max - cur;

	if (a > 2 * b)
		return (MAP_COLOR_HIGH);
	else if (b > 2 * a)
		return (MAP_COLOR_LOW);
	else
		return (MAP_COLOR_MIDDLE);
}

void	convert_map_to_mesh(t_map *map, t_mesh *mesh)
{
	t_vector	*v_ptr;
	int			*c_ptr;
	int			i;
	int			j;

	init_mesh(mesh, map->width, map->height);
	v_ptr = mesh->v_arr;
	c_ptr = mesh->c_arr;
	i = -1;
	while (++i < map->height)
	{
		j = -1;
		while (++j < map->width)
		{
			v_ptr->x = j;
			v_ptr->y = i;
			v_ptr->z = map->values[i * map->width + j];
			v_ptr->w = 1;
			*c_ptr = color_depend_on_value(\
				v_ptr->z, map->min_value, map->max_value);
			v_ptr++;
			c_ptr++;
		}
	}
}
