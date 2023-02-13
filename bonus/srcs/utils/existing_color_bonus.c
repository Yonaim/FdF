/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   existing_color_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhkim <yeonhkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 11:13:35 by yeonhkim          #+#    #+#             */
/*   Updated: 2023/01/22 18:56:51 by yeonhkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

int	existing_color(t_img *img, int x, int y)
{
	char		*dst;
	int			offset;

	offset = (y * img->bytes_per_line) + (x * (img->bits_per_pixel / 8));
	dst = &img->data[offset];
	return (*(int *)dst);
}
