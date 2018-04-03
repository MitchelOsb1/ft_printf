CC = gcc
NAME = libftprintf.a
SRC_DIR = srcs
FILES =	ft_printf.c \
		ft_conv_uipw.c \
		ft_convert.c \
		ft_handl_uip.c \
		ft_int.c \
		ft_libfunc.c \
		ft_libfunc1.c \
		ft_libfunc2.c \
		ft_libfunc3.c \
		ft_parse.c \
		ft_print.c \
		ft_sortsigns.c \
		ft_str_char.c \
		ft_unint.c \
		ft_wchar.c 

CFLAGS = -Wall -Wextra -Werror
HEAD = ./includes
SRC	:=	$(addprefix $(SRC_DIR)/, $(FILES))
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@ar rcs $(NAME) $(OBJ)

$(OBJ): %.o: %.c
	@gcc $(CFLAGS) -I $(HEAD) -c $< -o $@


clean:
	@/bin/rm -rf $(OBJ)

fclean: clean
	@/bin/rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re