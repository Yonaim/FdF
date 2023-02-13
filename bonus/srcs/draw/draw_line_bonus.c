/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhkim <yeonhkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 07:31:01 by yeonhkim          #+#    #+#             */
/*   Updated: 2023/01/22 18:56:51 by yeonhkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

static int	is_this_line_in_window(t_pixel p1, t_pixel p2)
{
	if (p1.x < 0 && p2.x < 0)
		return (false);
	else if (p1.x > WIN_WIDTH && p2.x > WIN_WIDTH)
		return (false);
	else if (p1.y < 0 && p2.y < 0)
		return (false);
	else if (p1.y > WIN_HEIGHT && p2.y > WIN_HEIGHT)
		return (false);
	return (true);
}

static int	interpolate_color(t_pixel m, t_line l, t_pixel end)
{
	int		x_remain;
	int		y_remain;
	double	ratio_from_end;

	if (l.start_color == l.end_color)
		return (l.start_color);
	if (l.w != 0)
	{
		x_remain = end.x - m.x;
		ratio_from_end = (double)x_remain / l.w;
	}
	else
	{
		y_remain = end.y - m.y;
		ratio_from_end = (double)y_remain / l.h;
	}
	return (alpha_blending_color(l.start_color, l.end_color, ratio_from_end));
}

static void	draw_line_big_angle(t_img *img, t_line l, t_pixel p1, t_pixel p2)
{
	int	d;

	if (l.w == 0)
	{
		while (p1.y != p2.y)
		{
			put_pixel_to_image(img, p1.x, p1.y, interpolate_color(p1, l, p2));
			p1.y += l.dy;
		}
		return ;
	}
	d = 2 * l.w - l.h;
	while (!(p1.x == p2.x && p1.y == p2.y))
	{
		p1.y += l.dy;
		if (d < 0)
			d += 2 * l.w;
		else
		{
			p1.x += l.dx;
			d += 2 * (l.w - l.h);
		}
		put_pixel_to_image(img, p1.x, p1.y, interpolate_color(p1, l, p2));
	}
}

static void	draw_line_small_angle(t_img *img, t_line l, t_pixel p1, t_pixel p2)
{
	int	d;

	d = 2 * l.h - l.w;
	while (!(p1.x == p2.x && p1.y == p2.y))
	{
		p1.x += l.dx;
		if (d < 0)
			d += 2 * l.h;
		else
		{
			p1.y += l.dy;
			d += 2 * (l.h - l.w);
		}
		put_pixel_to_image(img, p1.x, p1.y, interpolate_color(p1, l, p2));
	}
}

void	draw_line(t_img *img, t_pixel start, t_pixel end)
{
	t_line	line;

	if (is_this_line_in_window(start, end) == false)
		return ;
	put_pixel_to_image(img, start.x, start.y, start.color);
	if (start.x == end.x && start.y == end.y)
		return ;
	line.w = abs(end.x - start.x);
	line.h = abs(end.y - start.y);
	line.dx = sign(end.x - start.x);
	line.dy = sign(end.y - start.y);
	if (line.dx < 0)
	{
		line.start_color = end.color;
		line.end_color = start.color;
	}
	else
	{
		line.start_color = start.color;
		line.end_color = end.color;
	}
	if (line.w > line.h)
		draw_line_small_angle(img, line, start, end);
	else
		draw_line_big_angle(img, line, start, end);
}
