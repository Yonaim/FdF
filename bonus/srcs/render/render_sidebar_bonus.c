/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_sidebar_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhkim <yeonhkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 16:30:28 by yeonhkim          #+#    #+#             */
/*   Updated: 2023/01/22 18:56:51 by yeonhkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

static void	draw_sidebar_internal_line(t_img *img)
{
	draw_line(img, (t_pixel){20, 20, COLOR_YELLO}, \
							(t_pixel){130, 20, COLOR_YELLO});
	draw_line(img, (t_pixel){20, 70, COLOR_YELLO}, \
							(t_pixel){130, 70, COLOR_YELLO});
	draw_line(img, (t_pixel){20, 20, COLOR_YELLO}, \
							(t_pixel){20, 70, COLOR_YELLO});
	draw_line(img, (t_pixel){130, 20, COLOR_YELLO}, \
							(t_pixel){130, 70, COLOR_YELLO});
	draw_line(img, (t_pixel){0, 140, COLOR_WHITE}, \
							(t_pixel){SIDEBAR_WIDTH, 140, COLOR_WHITE});
	draw_line(img, (t_pixel){0, 200, COLOR_WHITE}, \
							(t_pixel){SIDEBAR_WIDTH, 200, COLOR_WHITE});
	draw_line(img, (t_pixel){0, 405, COLOR_WHITE}, \
							(t_pixel){SIDEBAR_WIDTH, 405, COLOR_WHITE});
}

void	render_sidebar(t_img *img)
{
	int	x;
	int	y;
	int	blended_color;

	y = 0;
	while (y < SIDEBAR_HEIGHT)
	{
		x = 0;
		while (x < SIDEBAR_WIDTH)
		{
			if (y < 1 || y >= SIDEBAR_HEIGHT - 1 \
				|| x < 1 || x >= SIDEBAR_WIDTH - 1)
				put_pixel_to_image(img, x, y, SIDEBAR_COLOR_BORDER);
			else
			{
				blended_color = alpha_blending_color \
					(SIDEBAR_COLOR_INSIDE, existing_color(img, x, y), 0.6);
				put_pixel_to_image(img, x, y, blended_color);
			}
			x++;
		}
		y++;
	}
	draw_sidebar_internal_line(img);
}
