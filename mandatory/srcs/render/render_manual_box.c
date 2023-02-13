/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_manual_box.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhkim <yeonhkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 14:55:50 by yeonhkim          #+#    #+#             */
/*   Updated: 2023/01/22 14:55:51 by yeonhkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	render_manual_box(t_img *img)
{
	const t_pixel	start = \
		{SIDEBAR_WIDTH + (WIN_WIDTH - SIDEBAR_WIDTH - MANUAL_WIDTH) / 2,
		(WIN_HEIGHT - MANUAL_HEIGHT) / 2, 0};
	int				x;
	int				y;
	int				blended_color;

	y = -1;
	while (++y < MANUAL_HEIGHT)
	{
		x = -1;
		while (++x < MANUAL_WIDTH)
		{
			if (y < 1 || y >= MANUAL_HEIGHT - 1 \
				|| x < 1 || x >= MANUAL_WIDTH - 1)
				put_pixel_to_image(img, start.x + x, start.y + y, COLOR_WHITE);
			else
			{
				blended_color = alpha_blending_color(MANUAL_COLOR_INSIDE, \
						existing_color(img, start.x + x, start.y + y), 0.5);
				put_pixel_to_image(img, start.x + x, start.y + y, \
												blended_color);
			}
		}
	}
}
