# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rstarfir <rstarfir@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/06 20:25:07 by rstarfir          #+#    #+#              #
#    Updated: 2020/07/14 14:53:02 by rstarfir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

LIBFT = Libft

MLX = minilibx

CC = gcc

SRCDIR = srcs

INCDIR = -I $(MLX) -I $(LIBFT) -I ./includes

LIBDIR = -L $(MLX) -L $(LIBFT)

LIB = -lft -lmlx

CFLAGS = -Wall -Werror -Wextra $(INCDIR)

HEADER_FILES = ./includes/fdf.h

MLXFLAGS = -L -lmlx -framework OpenGL -framework AppKit

FILES = change_coord.c \
		button_press.c \
		draw.c \
		image.c \
		init.c \
		main.c \
		map_check.c \
		memory_allocation.c

SRCS = $(addprefix $(SRCDIR)/,$(FILES))

OBJS = $(addprefix $(SRCDIR)/,$(FILES:.c=.o))

all: libft.a $(NAME)

$(NAME): $(OBJS) $(HEADER_FILES)
	@$(CC) $(CFLAGS) $(LIBDIR) $(LIB) $(OBJS) $(MLXFLAGS) -o $@ -c $<

libft.a:
	@make -C $(LIBFT)

libmlx.a:
	@make -C $(MLX)

%.o: %.c
	$(CC) $(CFLAGS)  $(INCDIR) $(LIBDIR) $(MLXFLAGS) $(SRCS) -o $@ -c $<


clean: 
	
	@rm -rf $(OBJS)
	@make -C $(LIBFT) clean
	@make -C $(MLX) clean

fclean: clean
	@rm -rf $(NAME)
	@make -C $(LIBFT) fclean

re: fclean all

.PHONY: all clean fclean re
