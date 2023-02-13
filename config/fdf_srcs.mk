# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    fdf_srcs.mk                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yeonhkim <yeonhkim@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/22 15:15:31 by yeonhkim          #+#    #+#              #
#    Updated: 2023/01/22 18:27:57 by yeonhkim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FDF_SRCS		= \
					main.c \
					init.c \
					$(addprefix $(CALCULATE_PATH)/, $(CALCULATE_SRCS)) \
					$(addprefix $(DRAW_PATH)/, $(DRAW_SRCS)) \
					$(addprefix $(EVENT_PATH)/, $(EVENT_SRCS)) \
					$(addprefix $(PARSE_PATH)/, $(PARSE_SRCS)) \
					$(addprefix $(RENDER_PATH)/, $(RENDER_SRCS)) \
					$(addprefix $(UTILS_PATH)/, $(UTILS_SRCS))

# ************************************ SRCS ********************************** #

CALCULATE_PATH	=	calculate
CALCULATE_SRCS	= \
					camera_transformation_matrix.c \
					compose_matrix.c \
					linear_transform.c \
					matmul.c \
					unit_matrix.c \
					world_transformation_matrix.c \

DRAW_PATH		=	draw
DRAW_SRCS 		= \
					alpha_blending_color.c \
					draw_line.c \
					draw_thick_point.c \


EVENT_PATH 		=	event
EVENT_SRCS 		= \
					adjust_transform_info.c \
					change_settings.c \
					destroy_hook.c \
					keypress_hook.c \
					mouse_hook.c \
					reset_transform_info.c \
					set_event_hooks.c \
					preset_transform_info.c \

PARSE_PATH 		=	parse
PARSE_SRCS 		= \
					convert_map_to_mesh.c \
					do_parsing.c \
					parse_file_to_map.c \

RENDER_PATH 	= 	render
RENDER_SRCS 	= \
					render_axis.c \
					render_manual_box.c \
					render_next_frame.c \
					render_object.c \
					render_sidebar.c \
					render_text.c \

UTILS_PATH 		= 	utils
UTILS_SRCS 		= \
					count_strs.c \
					exit_by_error.c \
					free_strs.c \
					sign.c \
					existing_color.c \
					put_pixel_to_image.c \
					put_text.c
