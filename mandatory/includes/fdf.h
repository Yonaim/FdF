/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhkim <yeonhkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 15:10:45 by yeonhkim          #+#    #+#             */
/*   Updated: 2023/01/22 19:39:32 by yeonhkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

/*-------------- STANDARD HEADERS ---------------*/

# include <fcntl.h>
# include <mlx.h>
# include <math.h>
# include <stdbool.h>
# include <limits.h>

/*-------------- USER DEFINED HEADERS ------------*/

# include "libft.h"
# include "color.h"
# include "event.h"

/*----------- DEFINE MACRO CONSTANTS ------------*/

# define WIN_WIDTH 					1000
# define WIN_HEIGHT 				800

# define BACKGROUND_COLOR			COLOR_BLACK
# define TEXT_COLOR					COLOR_WHITE

# define AXIS_COLOR_X				COLOR_RED
# define AXIS_COLOR_Y 				COLOR_GREEN
# define AXIS_COLOR_Z 				COLOR_BLUE
# define AXIS_COLOR_NEG				COLOR_GRAY
# define ORIGIN_COLOR 				COLOR_WHITE

# define MAP_COLOR_HIGH				COLOR_PINK
# define MAP_COLOR_MIDDLE			COLOR_YELLO
# define MAP_COLOR_LOW				COLOR_CYAN

# define SIDEBAR_WIDTH				150
# define SIDEBAR_HEIGHT				WIN_HEIGHT
# define SIDEBAR_BORDER_THIKNESS	3
# define SIDEBAR_COLOR_INSIDE		COLOR_BLACK
# define SIDEBAR_COLOR_BORDER		COLOR_WHITE

# define MANUAL_WIDTH				600
# define MANUAL_HEIGHT				400
# define MANUAL_COLOR_INSIDE		COLOR_BLACK
# define MANUAL_COLOR_BORDER		COLOR_WHITE

enum e_mode {
	CAMERA_ADJUST_MODE,
	OBJECT_ADJUST_MODE
};

/*------------- STRUCT DECLARATIONS --------------*/

/**
 * @brief mlx
 * 
 */
typedef struct s_img {
	void			*obj;
	char			*data;
	int				data_size;
	int				width;
	int				height;
	int				bits_per_pixel;
	int				bytes_per_line;
	int				endian;
}	t_img;

typedef struct s_mlx {
	void	*conn;
	void	*win;
	t_img	img;
}	t_mlx;

/*------------------------------------------------*/

/**
 * @brief map parsing
 * 
 */
typedef struct s_map {
	int	*values;
	int	width;
	int	height;
	int	max_value;
	int	min_value;
}	t_map;

/*------------------------------------------------*/

/**
 * @brief Drawing line
 * 
 */
typedef struct s_line {
	int	h;
	int	w;
	int	dx;
	int	dy;
	int	start_color;
	int	end_color;
}	t_line;

/*------------------------------------------------*/

/**
 * @brief coordinates of each space:
 * world_point is point of world space,
 * screen_point is point of screen space
 */
typedef struct s_world_point {
	double	x;
	double	y;
	double	z;
	double	w;
}	t_world_point;

typedef struct s_screen_point {
	int	x;
	int	y;
	int	color;
}	t_screen_point;

typedef t_world_point	t_vector;	// vector of world space
typedef t_world_point	t_position;	// point of world space
typedef t_screen_point	t_pixel;	// point of screen space

/*------------------------------------------------*/

/**
 * @brief linear transform 
 * 
 */
typedef struct s_matrix {
	t_vector	v1;
	t_vector	v2;
	t_vector	v3;
	t_vector	v4;
}	t_matrix;

/*------------------------------------------------*/

/**
 * @brief elements of object
 * 
 */
typedef t_world_point	t_vertex;	// point of world space

typedef struct s_mesh {
	t_vertex	*v_arr;
	int			*c_arr;
	int			v_cnt;
	int			v_per_row;
	int			v_per_col;
}	t_mesh;

typedef struct s_rotation {
	double	x;
	double	y;
	double	z;
}	t_rotation;

/*------------------------------------------------*/

/**
 * @brief Objects in world space
 * (Camera is object, too. 
 * but it is special object that has no modeling(mesh)
 * and exist only one in each world space)
 */
typedef struct s_object {
	t_mesh		*mesh;
	t_position	pos;
	t_rotation	rot;
	double		scale;
	double		elevation;
	t_vector	*out;
}	t_object;

typedef struct s_camera {
	t_position	pos;
	t_rotation	rot;
	double		zoom;
}	t_camera;

/*------------------------------------------------*/

/**
 * @brief FDF program
 * 
 */
typedef struct s_settings {
	int	mode;
	int	manual;
	int	axis;
}	t_settings;

typedef struct s_fdf {
	t_mlx		mlx;
	t_object	obj;
	t_camera	cam;
	t_settings	set;
}	t_fdf;

/*----------------- TYPE DEFINE ------------------*/

typedef void			(*t_event_handle)(int keycode, t_fdf *f);

/*-------------- FUNCTION PROTOTYPES -------------*/

/* parse */
t_mesh		*do_parsing(char *path);
void		parse_file_to_map(char *path, struct s_map *map);
void		convert_map_to_mesh(t_map *map, t_mesh *mesh);

/* calculate */
void		compose_rotate_matrix(t_matrix *m, double x, double y, double z);
t_matrix	unit_matrix(void);
void		compose_scale_matrix(t_matrix *m, double x, double y, double z);
void		compose_rotate_matrix(t_matrix *m, double x, double y, double z);
void		compose_move_matrix(t_matrix *m, double x, double y, double z);
t_vector	linear_transform(t_matrix m, t_vector v);
t_matrix	matmul(t_matrix m1, t_matrix m2);
t_matrix	world_transform_matrix(t_position pos, t_rotation rot, \
																double scale);
t_matrix	camera_transform_matrix(t_camera *cam);

/* draw */
void		draw_line(t_img *img, t_pixel start, t_pixel end);
void		draw_thick_point(t_img *img, t_pixel center, int thickness);
int			alpha_blending_color(int color1, int color2, double alpha);

/* render */
int			render_next_frame(t_fdf *f);
void		render_text(t_mlx *mlx, t_settings *set, t_object *obj, \
															t_camera *cam);
void		render_object(t_img *img, t_object *obj, t_camera *cam);
void		render_sidebar(t_img *img);
void		render_manual_box(t_img *img);
void		render_axis(t_img *img, t_camera *cam);

/* event hook */
void		set_event_hooks(void *mlx_win, t_fdf *p);
int			keypress_hook(int keycode, t_fdf *f);
int			mouse_hook(int button, int x, int y, t_fdf *f);
int			destroy_hook(void *parm);

void		preset_transform_info_isometric(int keycode, t_fdf *f);
void		reset_transform_info(int keycode, t_fdf *f);
void		adjust_transform_info(int keycode, t_fdf *f);
void		preset_transform_info_general(int keycode, t_fdf *f);
void		change_settings(int keycode, t_fdf *f);

/* init */
void		init_fdf(t_fdf *fdf, char *path);
void		init_mlx(t_mlx *mlx, char *path);
void		init_object(t_object *obj, t_mesh *mesh);
void		init_camera(t_camera *cam);
void		init_settings(t_settings *set);
double		get_object_initial_scale(int width, int height);

/* utils */
void		exit_by_error(char *msg);
int			sign(int n);
int			count_strs(char **strs);
void		free_strs(char **strs);
void		put_text(t_mlx *mlx, int x, int y, char *str);
int			existing_color(t_img *img, int x, int y);
void		put_pixel_to_image(t_img *img, int x, int y, int color);

/*------------------------------------------------*/

#endif
