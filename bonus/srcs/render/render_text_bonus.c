/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_text_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhkim <yeonhkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 15:19:53 by yeonhkim          #+#    #+#             */
/*   Updated: 2023/01/22 18:56:51 by yeonhkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

static void	put_position_info(t_mlx *mlx, t_position pos, int x, int y)
{
	char	*str_x;
	char	*str_y;
	char	*str_z;

	str_x = ft_itoa(pos.x);
	str_y = ft_itoa(pos.y);
	str_z = ft_itoa(pos.z);
	put_text(mlx, x, y, "pos.x:");
	put_text(mlx, x, y + 20, "pos.y:");
	put_text(mlx, x, y + 40, "pos.z:");
	put_text(mlx, x + 50, y, str_x);
	put_text(mlx, x + 50, y + 20, str_y);
	put_text(mlx, x + 50, y + 40, str_z);
	free(str_x);
	free(str_y);
	free(str_z);
}

static void	put_rotation_info(t_mlx *mlx, t_rotation rot, int x, int y)
{
	char	*str_x;
	char	*str_y;
	char	*str_z;

	str_x = ft_itoa(rot.x);
	str_y = ft_itoa(rot.y);
	str_z = ft_itoa(rot.z);
	put_text(mlx, x, y, "rot.x:");
	put_text(mlx, x, y + 20, "rot.y:");
	put_text(mlx, x, y + 40, "rot.z:");
	put_text(mlx, x + 50, y, str_x);
	put_text(mlx, x + 50, y + 20, str_y);
	put_text(mlx, x + 50, y + 40, str_z);
	free(str_x);
	free(str_y);
	free(str_z);
}

static void	render_text_manual(t_mlx *mlx)
{
	const t_pixel	start = {SIDEBAR_WIDTH + (WIN_WIDTH - SIDEBAR_WIDTH \
					- MANUAL_WIDTH) / 2, (WIN_HEIGHT - MANUAL_HEIGHT) / 2, 0};

	put_text(mlx, start.x + (MANUAL_WIDTH / 2) - 30, start.y + 35, "Manual");
	put_text(mlx, start.x + 40, start.y + 70, \
	"Welcome to Yonazang's wonderful FDF!");
	put_text(mlx, start.x + 40, start.y + 90, \
	"FDF is a program that reads a map and shows it as a wire frame 3D model.");
	put_text(mlx, start.x + 40, start.y + 110, "In French, 'wireframe model' \
								is 'fil de fer' and FDF is derived from this.");
	put_text(mlx, start.x + 40, start.y + 150, \
			"Mouse Scroll: Zoom in / Zoom out");
	put_text(mlx, start.x + 40, start.y + 190, \
			"+, -: Adjust elevation of object");
	put_text(mlx, start.x + 40, start.y + 230, \
			"TAB: Change mode (Position & Rotation)");
	put_text(mlx, start.x + 40, start.y + 250, \
			"   (OBJECT ADJUST MODE <-> CAMERA ADJUST MODE)");
	put_text(mlx, start.x + 40, start.y + 290, \
			"W, A, S, D, Z, X: Adjust Position");
	put_text(mlx, start.x + 40, start.y + 310, \
			"   Note: Orthogonal projections do not have perspective");
	put_text(mlx, start.x + 40, start.y + 350, \
			"I, O, K, L, <, >: Adjust Rotation");
	put_text(mlx, start.x + MANUAL_WIDTH - 140, start.y + (MANUAL_HEIGHT) - 20, \
			"Press F1 to close");
}

static void	render_text_sidebar(t_mlx *mlx, t_object *obj, t_camera *cam)
{
	mlx_string_put(mlx->conn, mlx->win, 40, 40, COLOR_CYAN, "Yonazang's");
	mlx_string_put(mlx->conn, mlx->win, 30, 60, COLOR_CYAN, "wonderful FDF");
	put_text(mlx, 20, 165, "TAB: Change Mode");
	put_text(mlx, 20, 185, "ALT: Axis ON/OFF");
	put_text(mlx, 10, 100, "*** Press F1 to");
	put_text(mlx, 30, 120, "open Manual ***");
	put_text(mlx, 30, 230, "[Pre-set Key]");
	put_text(mlx, 25, 260, "KEY R");
	put_text(mlx, 20, 280, ": Reset All");
	put_text(mlx, 25, 310, "KEY 1~8");
	put_text(mlx, 20, 330, ": Isometric View");
	put_text(mlx, 25, 360, "NUMPAD 1~9");
	put_text(mlx, 20, 380, ": General View");
	put_text(mlx, 45, WIN_HEIGHT - 365, "[Status]");
	put_text(mlx, 20, WIN_HEIGHT - 330, "---- OBJECT ----");
	put_position_info(mlx, obj->pos, 40, WIN_HEIGHT - 300);
	put_rotation_info(mlx, obj->rot, 40, WIN_HEIGHT - 230);
	put_text(mlx, 20, WIN_HEIGHT - 160, "---- CAMERA ----");
	put_position_info(mlx, cam->pos, 40, WIN_HEIGHT - 130);
	put_rotation_info(mlx, cam->rot, 40, WIN_HEIGHT - 60);
}

void	render_text(t_mlx *mlx, t_settings *set, t_object *obj, t_camera *cam)
{
	if (set->manual)
		render_text_manual(mlx);
	render_text_sidebar(mlx, obj, cam);
	mlx_string_put(mlx->conn, mlx->win, WIN_WIDTH - 80, 30, COLOR_RED, \
																"RED:   x");
	mlx_string_put(mlx->conn, mlx->win, WIN_WIDTH - 80, 50, COLOR_GREEN, \
																"GREEN: y");
	mlx_string_put(mlx->conn, mlx->win, WIN_WIDTH - 80, 70, COLOR_BLUE, \
																"BLUE:  z");
	if (set->mode == CAMERA_ADJUST_MODE)
		put_text(mlx, WIN_WIDTH - 160, WIN_HEIGHT - 20, "[CAMERA ADJUST MODE]");
	else
		put_text(mlx, WIN_WIDTH - 160, WIN_HEIGHT - 20, "[OBJECT ADJUST MODE]");
}
