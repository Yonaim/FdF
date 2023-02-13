/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixel_to_image.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhkim <yeonhkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 11:13:45 by yeonhkim          #+#    #+#             */
/*   Updated: 2022/12/30 11:13:53 by yeonhkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	put_pixel_to_image(t_img *img, int x, int y, int color)
{
	char		*dst;
	int			offset;

	if (x > WIN_WIDTH || y > WIN_HEIGHT || x < 0 || y < 0)
		return ;
	offset = (y * img->bytes_per_line) + (x * (img->bits_per_pixel / 8));
	if (0 <= offset && offset < (img->width * img->height) * 4)
	{
		dst = &img->data[offset];
		*(unsigned int *)dst = color;
	}
	else
		return ;
}
