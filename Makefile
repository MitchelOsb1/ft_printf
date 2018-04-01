CC = gcc
NAME = libftprintf.a
SRC_DIR = srcs
FILES =	ft_printf.c \
		ft_conv_uipw.c \
		ft_convert.c \
		ft_handl_uip.c \
		ft_handl_wc.c \
		ft_int.c \
		ft_libfunc.c \
		ft_libfunc1.c \
		ft_libfunc2.c \
		ft_libfunc3.c \
		ft_parse.c \
		ft_print.c \
		ft_sortsigns.c \
		ft_str-char.c \
		ft_unint.c \
		ft_wchar.c 

CFLAGS = -Wall -Wextra -Werror
HEAD = ./includes
SRC	:=	$(addprefix $(SRC_DIR)/, $(FILES))
OBJ = $(SRC:.c=.o)

BUILD_PRINT = @echo "\033[0;33mBuilding \"$<\"..."
DONE = @echo "\033[0;32mFt_printf ready to use!"
CLEAN_O = @echo "\033[0;32mObject files removed!"
CLEAN_A = @echo "\033[0;32mExecutable removed!"

all: $(NAME)

$(NAME): $(OBJ)
	@ar rcs $(NAME) $(OBJ)
	$(DONE)

$(OBJ): %.o: %.c
	$(BUILD_PRINT)
	@gcc $(CFLAGS) -I $(HEAD) -c $< -o $@


clean:
	@/bin/rm -rf $(OBJ)
	$(CLEAN_O)

fclean: clean
	@/bin/rm -rf $(NAME)
	$(CLEAN_A)

re: fclean all

.PHONY: all clean fclean re