/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_axis.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhkim <yeonhkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 19:23:57 by yona              #+#    #+#             */
/*   Updated: 2023/01/22 18:40:06 by yeonhkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "render.h"

static int	is_in_window(t_pixel p)
{
	return ((0 <= p.x && p.x <= WIN_WIDTH)
		&& (0 <= p.y && p.y <= WIN_WIDTH));
}

static t_pixel	nearest_outer_point(t_position start, double dx, double dy)
{
	t_position	p;

	if (dx == 0 && dy == 0)
		return ((t_pixel){(int)start.x, (int)start.y, 0});
	if (fabs(dx) < 0.000000001 && fabs(dy) < 0.0000001)
		return ((t_pixel){(int)start.x, (int)start.y, 0});
	p = start;
	while (is_in_window((t_pixel){p.x, p.y, 0}))
	{
		p.x += dx;
		p.y += dy;
	}
	return ((t_pixel){p.x, p.y, 0});
}

int	axis_color(int axis_type)
{
	if (axis_type == X)
		return (AXIS_COLOR_X);
	else if (axis_type == Y)
		return (AXIS_COLOR_Y);
	else if (axis_type == Z)
		return (AXIS_COLOR_Z);
	return (0);
}

void	coordinates_system_info(t_position *origin, t_vector *basis, \
															t_camera *cam)
{
	const t_matrix	m = camera_transform_matrix(cam);

	*origin = linear_transform(m, (t_position){0, 0, 0, 1});
	basis[X] = m.v1;
	basis[Y] = m.v2;
	basis[Z] = m.v3;
}

void	render_axis(t_img *img, t_camera *cam)
{
	t_position	origin;
	t_vector	basis[3];
	t_pixel		endpoint[2];
	int			axis;

	coordinates_system_info(&origin, basis, cam);
	origin.x += WIN_WIDTH / 2;
	origin.y += WIN_HEIGHT / 2;
	axis = X;
	while (axis <= Z)
	{
		endpoint[POS] = nearest_outer_point(origin, \
												basis[axis].x, basis[axis].y);
		endpoint[POS].color = axis_color(axis);
		endpoint[NEG] = nearest_outer_point(origin, \
												-basis[axis].x, -basis[axis].y);
		endpoint[NEG].color = AXIS_COLOR_NEG;
		draw_line(img, (t_pixel){origin.x, origin.y, endpoint[POS].color}, \
																endpoint[POS]);
		draw_line(img, (t_pixel){origin.x, origin.y, AXIS_COLOR_NEG}, \
																endpoint[NEG]);
		axis++;
	}
	draw_thick_point(img, (t_pixel){origin.x, origin.y, ORIGIN_COLOR}, 7);
}
