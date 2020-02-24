# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: poatmeal <poatmeal@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/09 17:39:46 by poatmeal          #+#    #+#              #
#    Updated: 2020/02/15 13:53:41 by poatmeal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean

INCLUDES = ./

SRCS = ft_countmem.c \
ft_isprint.c \
ft_memcmp.c \
ft_putchar.c \
ft_putnbr_fd.c \
ft_strclr.c \
ft_strequ.c \
ft_strlen.c \
ft_strncpy.c \
ft_strsplit.c \
ft_toupper.c \
ft_isalnum.c \
ft_itoa.c \
ft_memcpy.c \
ft_putchar_fd.c \
ft_putstr.c \
ft_strcmp.c \
ft_striter.c \
ft_strmap.c \
ft_strnequ.c \
ft_strstr.c \
ft_isalpha.c \
ft_memalloc.c \
ft_memdel.c \
ft_putendl.c \
ft_putstr_fd.c \
ft_strcpy.c \
ft_striteri.c \
ft_strmapi.c \
ft_strnew.c \
ft_strsub.c \
ft_atoi.c \
ft_isascii.c \
ft_memccpy.c \
ft_memmove.c \
ft_putendl_fd.c \
ft_strcat.c \
ft_strdel.c \
ft_strjoin.c \
ft_strncat.c \
ft_strnstr.c \
ft_strtrim.c \
ft_bzero.c \
ft_isdigit.c \
ft_memchr.c \
ft_memset.c \
ft_putnbr.c \
ft_strchr.c \
ft_strdup.c \
ft_strlcat.c \
ft_strncmp.c \
ft_strrchr.c \
ft_tolower.c \
ft_lstnew.c \
ft_lstdelone.c \
ft_lstdel.c \
ft_lstadd.c \
ft_lstiter.c \
ft_lstmap.c \
ft_freememmass.c \
ft_swap.c \
ft_range.c \
ft_sqrt.c \
get_next_line.c \
ft_atoi_16.c

OBJ = $(SRCS:.c=.o)

NAME = libft.a

all: $(NAME)

$(NAME): $(OBJ) libft.h
	gcc -Wall -Wextra -Werror -c $(SRCS) -I $(INCLUDES)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean: 
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
