# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mosborne <mosborne@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/03 20:02:51 by mosborne          #+#    #+#              #
#    Updated: 2018/01/21 18:45:22 by mosborne         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = printf

GCC = gcc

FLAGS = -Wall -Wextra -Werror

SRCS = ft_printf.c ft_print.c ft_parse.c ft_convert.c ft_print.c ft_tools.c

INCUDES = ft_printf.h

all: $(NAME)

$(NAME):
	@$(MAKE) -C ./libft
	@gcc $(FLAGS) $(SRCS) -I $(INCLUDES) -L./libft/ -lft -o $(NAME)

clean:
	@$(MAKE) clean -C ./libft
	@rm -rf $(NAME)

fclean: clean
	@$(MAKE) fclean -C ./libft

re: fclean all