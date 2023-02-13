/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhkim <yeonhkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 16:31:29 by yeonhkim          #+#    #+#             */
/*   Updated: 2023/01/22 19:40:04 by yeonhkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	init_fdf(t_fdf *fdf, char *path)
{
	init_mlx(&fdf->mlx, path);
	init_object(&fdf->obj, do_parsing(path));
	init_camera(&fdf->cam);
	init_settings(&fdf->set);
}

int	main(int argc, char *argv[])
{
	t_fdf		fdf;

	if (argc != 2)
	{
		ft_putstr_fd("\nusage: fdf <mapfile path>\n\n", 2);
		exit(1);
	}
	init_fdf(&fdf, argv[1]);
	set_event_hooks(fdf.mlx.win, &fdf);
	mlx_loop_hook(fdf.mlx.conn, render_next_frame, &fdf);
	mlx_loop(fdf.mlx.conn);
	return (0);
}
