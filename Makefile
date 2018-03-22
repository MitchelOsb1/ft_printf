# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mosborne <mosborne@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/03 20:02:51 by mosborne          #+#    #+#              #
#    Updated: 2018/03/21 18:12:50 by mosborne         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = printf.a

GCC = gcc

FLAGS = -Wall -Wextra -Werror

SRCS = ft_printf.c ft_print.c ft_parse.c ft_convert.c ft_int.c ft_str-char.c ft_unint.c ft_sortsigns.c ft_libfunc.c ft_handl_uip.c ft_conv_uipw.c main.c ft_wchar.c ft_handl_wc.c

INCUDES = ft_printf.h

all: $(NAME)

$(NAME):
	@$(GCC) $(FLAGS) -c $(SRCS) libft/*.c
	@ar rcs $(NAME) *.o
	@ranlib $(NAME)

clean:
	@rm -rf *.o

fclean: clean
	@$(MAKE) fclean -C ./libft/
	@rm -rf $(NAME)

re: fclean all