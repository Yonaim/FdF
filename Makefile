# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yeonhkim <yeonhkim@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/05 02:56:10 by yeonhkim          #+#    #+#              #
#    Updated: 2023/01/22 19:23:29 by yeonhkim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.DEFAULT_GOAL	= all

CC				= cc
CFLAGS			= -Wall -Wextra -Werror
CPPFLAGS		= -I./lib/libft -I./lib/mlx -I./$(FDF_PATH)/includes
LDFLAGS			= -L./lib/libft -L./lib/mlx -framework OpenGL -framework AppKit
LDLIBS			= -lft -lmlx

# ********************************** LIBRARY ********************************* #

include config/library.mk

# ************************************ FDF *********************************** #

FDF				= fdf

ifdef BONUS
FDF_PATH		= ./bonus
SUFFIX			= _bonus
else
FDF_PATH		= ./mandatory
SUFFIX 			= 
endif

include			config/fdf_srcs.mk

FDF_OBJS		= $(addprefix $(FDF_PATH)/srcs/, $(FDF_SRCS:.c=$(SUFFIX).o))

$(FDF): $(FDF_OBJS)
	$(CC) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS) $^ -o $@

# ********************************* MAKE RULES ******************************* #
# **************************************************************************** #

all:
	make -C $(MLX_PATH) --silent
	make -C $(LIBFT_PATH) --silent
	make $(FDF)

bonus:
	make -C $(LIBFT_PATH) --silent
	make -C $(LIBFT_PATH) --silent
	BONUS=1 make $(FDF)

clean:
	make -C $(LIBFT_PATH) clean --silent
	make -C $(MLX_PATH) clean --silent
	rm -f $(addprefix ./mandatory/srcs/, $(FDF_SRCS:.c=.o))
	rm -f $(addprefix ./bonus/srcs/, $(FDF_SRCS:.c=_bonus.o))

fclean:
	make -C $(LIBFT_PATH) fclean --silent
	make -C $(MLX_PATH) clean --silent
	rm -f $(MLX_PATH)/$(MLX)
	rm -f $(addprefix ./mandatory/srcs/, $(FDF_SRCS:.c=.o))
	rm -f $(addprefix ./bonus/srcs/, $(FDF_SRCS:.c=_bonus.o))
	rm -f $(FDF)

re: 
	make fclean
	make all

# ******************************* TEST RULES ********************************* #

test1:
	./$(FDF) ./test_maps/42.fdf

test2:
	./$(FDF) ./test_maps/elem-fract.fdf

test3:
	./$(FDF) ./test_maps/julia.fdf

# **************************************************************************** #

.PHONY: all clean fclean re bonus test1 test2 test3