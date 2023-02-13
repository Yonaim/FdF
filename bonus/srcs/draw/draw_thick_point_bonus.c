/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_thick_point_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhkim <yeonhkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 11:14:06 by yeonhkim          #+#    #+#             */
/*   Updated: 2023/01/22 18:56:51 by yeonhkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	draw_thick_point(t_img *img, t_pixel center, int thickness)
{
	int	dx;
	int	dy;

	dy = -(thickness / 2);
	while (dy < thickness / 2)
	{
		dx = -(thickness / 2);
		while (dx < thickness / 2)
		{
			put_pixel_to_image(img, center.x + dx, center.y + dy, center.color);
			put_pixel_to_image(img, center.x - dx, center.y - dy, center.color);
			dx++;
		}
		dy++;
	}
}
