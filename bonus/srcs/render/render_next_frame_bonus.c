/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_next_frame_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhkim <yeonhkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 23:35:35 by yona              #+#    #+#             */
/*   Updated: 2023/01/22 18:56:51 by yeonhkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

static void	clear_img(t_img *img)
{
	int	*ptr;
	int	i;

	ft_memset(img->data, 0, img->data_size);
	ptr = (int *)img->data;
	i = 0;
	while (i < WIN_WIDTH * WIN_HEIGHT)
	{
		*(ptr++) = BACKGROUND_COLOR;
		i++;
	}
}

int	render_next_frame(t_fdf *f)
{
	clear_img(&f->mlx.img);
	render_object(&f->mlx.img, &f->obj, &f->cam);
	if (f->set.axis)
		render_axis(&f->mlx.img, &f->cam);
	render_sidebar(&f->mlx.img);
	if (f->set.manual)
		render_manual_box(&f->mlx.img);
	mlx_put_image_to_window(f->mlx.conn, f->mlx.win, f->mlx.img.obj, 0, 0);
	render_text(&f->mlx, &f->set, &f->obj, &f->cam);
	return (0);
}
