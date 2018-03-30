# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mosborne <mosborne@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/03 20:02:51 by mosborne          #+#    #+#              #
#    Updated: 2018/03/30 16:19:24 by mosborne         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

GCC = gcc

FLAGS = -Wall -Wextra -Werror
SRCS_DIR = srcs
SRCS = ft_printf.c ft_print.c ft_parse.c ft_convert.c ft_int.c ft_str-char.c \
 ft_unint.c ft_sortsigns.c ft_libfunc.c ft_handl_uip.c ft_conv_uipw.c \
 ft_wchar.c ft_handl_wc.c ft_libfunc1.c ft_libfunc2.c ft_libfunc3.c \

SRC := $(addprefix $(SRCS_DIR)/, $(SRCS))
OBJS = $(SRC:.c=.o)

INCLUDES = ./includes/ft_printf.h

all: $(NAME)

$(NAME):
	@$(GCC) $(FLAGS) -I $(INCLUDES) -c $(SRC)
	@ar rcs $(NAME) *.o

clean:
	@/bin/rm -rf *.o

fclean: clean
	@/bin/rm -rf $(NAME)

re: fclean all
