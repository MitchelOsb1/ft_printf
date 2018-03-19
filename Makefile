# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mosborne <mosborne@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/03 20:02:51 by mosborne          #+#    #+#              #
#    Updated: 2018/03/19 08:01:27 by mosborne         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = printf

GCC = gcc

FLAGS = -Wall -Wextra -Werror

SRCS = ft_printf.c ft_print.c ft_parse.c ft_convert.c ft_int.c ft_str-char.c ft_unint.c ft_sortsigns.c ft_libfunc.c ft_handl_ui.c ft_con_ui.c main.c

INCUDES = ft_printf.h

all: $(NAME)

$(NAME):
	@$(MAKE) -C ./libft/
	@gcc $(FLAGS) $(SRCS) -L./libft/ -lft -o $(NAME)
	@echo "printf created"

clean:
	@$(MAKE) clean -C ./libft/
	@rm -rf $(NAME)

fclean: clean
	@$(MAKE) fclean -C ./libft/

re: fclean all