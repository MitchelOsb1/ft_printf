# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mosborne <mosborne@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/03 20:02:51 by mosborne          #+#    #+#              #
#    Updated: 2018/03/21 18:29:05 by mosborne         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = printf.a

GCC = gcc

FLAGS = -Wall -Wextra -Werror

SRCS = srcs/ft_printf.c srcs/ft_print.c srcs/ft_parse.c srcs/ft_convert.c \
 srcs/ft_int.c srcs/ft_str-char.c srcs/ft_unint.c srcs/ft_sortsigns.c \
 srcs/ft_libfunc.c srcs/ft_handl_uip.c srcs/ft_conv_uipw.c \
 srcs/ft_wchar.c srcs/ft_handl_wc.c \

INCUDES = includes/ft_printf.h

all: $(NAME)

$(NAME):
	@$(GCC) $(FLAGS) -c $(SRCS) ./srcs/libft/*.c
	@ar rcs $(NAME) *.o
	@ranlib $(NAME)

clean:
	@rm -rf *.o

fclean: clean
	@$(MAKE) fclean -C ./srcs/libft/
	@rm -rf $(NAME)

re: fclean all