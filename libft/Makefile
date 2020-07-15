# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rstarfir <rstarfir@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/03 22:22:01 by rstarfir          #+#    #+#              #
#    Updated: 2020/07/14 14:40:29 by rstarfir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CHAR_FOLDER = ft_isalpha.c \
		ft_isdigit.c \
		ft_isalnum.c \
		ft_isascii.c \
		ft_isprint.c \
		ft_isspace.c \
		ft_toupper.c \
		ft_tolower.c

LIST_FOLDER = ft_lstnew.c \
		ft_lstdelone.c \
		ft_lstdel.c \
		ft_lstadd.c \
		ft_lstmap.c \
		ft_lstiter.c 

MATH_FOLDER = ft_islower.c \
		ft_isupper.c \
		ft_range.c \
		ft_sqrt.c

MEMORY_FOLDER = ft_memset.c \
		ft_bzero.c \
		ft_memcpy.c \
		ft_memccpy.c \
		ft_memmove.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_memalloc.c \
		ft_memdel.c \
		ft_countmem.c\
		ft_freememmass.c

PRINT_FOLDER = ft_putchar.c \
		ft_putstr.c \
		ft_putendl.c \
		ft_putnbr.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c

STR_FOLDER = ft_strlen.c \
		ft_strdup.c \
		ft_strcpy.c \
		ft_strncpy.c \
		ft_strcat.c \
		ft_strncat.c \
		ft_strlcat.c \
		ft_strchr.c \
		ft_strrchr.c \
		ft_strstr.c \
		ft_strnstr.c \
		ft_strcmp.c \
		ft_strncmp.c \
		ft_strnew.c \
		ft_strdel.c \
		ft_strclr.c \
		ft_striter.c \
		ft_striteri.c \
		ft_strmap.c \
		ft_strmapi.c \
		ft_strequ.c \
		ft_strnequ.c \
		ft_strsub.c \
		ft_strjoin.c \
		ft_strtrim.c \
		ft_strsplit.c \
		get_next_line.c

UTILS_FOLDER = ft_atoi.c\
		ft_itoa.c\
		ft_atoi_16.c \
		ft_swap.c

SRCS = $(CHAR_FOLDER) $(LIST_FOLDER) $(MATH_FOLDER) $(MEMORY_FOLDER) \
			$(PRINT_FOLDER) $(STR_FOLDER) $(UTILS_FOLDER)

INC = -I./includes

OBJECTS = $(SRCS:%.c=%.o)

vpath %.c char
vpath %.c list
vpath %.c math
vpath %.c memory
vpath %.c print
vpath %.c str
vpath %.c utils

GCCF = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJECTS)
	@ar rc $(NAME) $(OBJECTS)
	@ranlib $(NAME)

%.o: %.c
		@clang $(GCCF) $(INC) -c $< -o $@


clean: 
	@rm -f $(OBJECTS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
