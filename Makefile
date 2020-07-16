# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rstarfir <rstarfir@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/06 20:25:07 by rstarfir          #+#    #+#              #
#    Updated: 2020/07/15 19:35:46 by rstarfir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
LIBFT = libft
MLX = minilibx
SRCDIR = srcs
OBJDIR = temp
FFLAGS = -Wall -Wextra -Werror
LFLAGS = -L $(LIBFT) -lft
MLXFLAGS = -L $(MLX) -lmlx -framework OpenGL -framework AppKit
HEADER_FILES = ./includes/fdf.h\

FILES = change_coord.c \
		button_press.c \
		draw.c \
		image.c \
		init.c \
		main.c \
		map_check.c \
		memory_allocation.c
SRCS = $(addprefix $(SRCDIR)/,$(FILES))
OBJS = $(addprefix $(OBJDIR)/,$(FILES:.c=.o))
INCLUDES = includes

all: libft.a libmlx.a $(NAME)

$(NAME): $(OBJS) $(HEADER_FILES)
	@gcc $(FFLAGS) -o $(NAME) $(OBJS) $(LFLAGS) $(MLXFLAGS)

libft.a:
	@make -C $(LIBFT)

libmlx.a:
	@make -C $(MLX)

$(OBJDIR)/%.o: $(SRCDIR)/%.c $(HEADER_FILES)
	mkdir -p temp
	@gcc $(FFLAGS) -I $(LIBFT) -I $(MLX) -I $(INCLUDES) -o $@ -c $<


clean: 
	
	@rm -rf $(OBJDIR)
	@make -C $(LIBFT) clean
	@make -C $(MLX) clean

fclean: clean
	@rm -rf $(NAME)
	@make -C $(LIBFT) fclean

re: fclean all

.PHONY: all clean fclean re
