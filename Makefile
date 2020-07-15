# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rstarfir <rstarfir@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/06 20:25:07 by rstarfir          #+#    #+#              #
#    Updated: 2020/07/15 16:25:45 by rstarfir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
LIBFT = libft
MLX = minilibx
FFLAGS = -Wall -Wextra -Werror
LFLAGS = -L $(LIBFT) -lft
MLXFLAGS = -L $(MLX) -lmlx -framework OpenGL -framework AppKit
HEADER_FILES = ./includes/fdf.h
FILES = ./main.c ./map_check.c ./memory_allocation.c ./image.c ./draw.c ./init.c ./button_press.c ./change_coord.c 
OBJS = $(FILES:%.c=%.o)
INCLUDES = includes

all: libft.a libmlx.a $(NAME)

$(NAME): $(OBJS) $(HEADER_FILES)
	@gcc $(FFLAGS) -o $(NAME) $(OBJS) $(LFLAGS) $(MLXFLAGS)

libft.a:
	@make -C $(LIBFT)

libmlx.a:
	@make -C $(MLX)

%.o: %.c $(HEADER_FILES)
	@gcc $(FFLAGS) -I $(LIBFT) -I $(MLX) -I $(INCLUDES) -o $@ -c $<


clean: 
	
	@rm -rf $(OBJS)
	@make -C $(LIBFT) clean
	@make -C $(MLX) clean

fclean: clean
	@rm -rf $(NAME)
	@make -C $(LIBFT) fclean

re: fclean all

.PHONY: all clean fclean re