# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mosborne <mosborne@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/03 20:02:51 by mosborne          #+#    #+#              #
#    Updated: 2018/03/29 13:34:29 by mosborne         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

GCC = gcc

FLAGS = -Wall -Wextra -Werror

SRCS = srcs/ft_printf.c srcs/ft_print.c srcs/ft_parse.c srcs/ft_convert.c \
 srcs/ft_int.c srcs/ft_str-char.c srcs/ft_unint.c srcs/ft_sortsigns.c \
 srcs/ft_libfunc.c srcs/ft_handl_uip.c srcs/ft_conv_uipw.c \
 srcs/ft_wchar.c srcs/ft_handl_wc.c srcs/ft_libfunc1.c srcs/ft_libfunc2.c \
 srcs/ft_libfunc3.c

INCUDES = includes/ft_printf.h

all: $(NAME)

$(NAME):
	@$(GCC) $(FLAGS) -c $(SRCS)
	@ar rcs $(NAME) *.o
	@ranlib $(NAME)

clean:
	@rm -rf *.o

fclean: clean
	@rm -rf $(NAME)

re: fclean all