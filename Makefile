# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mosborne <mosborne@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/03 20:02:51 by mosborne          #+#    #+#              #
#    Updated: 2018/03/06 12:21:04 by mosborne         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = printf

GCC = gcc

FLAGS = -Wall -Wextra -Werror

SRCS = ft_printf.c ft_print.c ft_parse.c ft_convert.c ft_int.c ft_string.c

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