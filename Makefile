CC = cc
CFLAGS = -Wall -Wextra -Werror -g
NAME = fractal

CCF = $(CC) $(CFLAGS)

SRC = src/main.c src/fractal_init.c src/fractals/mandelbrot.c src/utils/ft_strncmp.c
OBJ = $(SRC:.c=.o)
INC = -I include -I /usr/include/minilibx-linux
LIB = -L/usr/include/minilibx-linux -lmlx -lX11 -lXext

all: $(OBJ)
	$(CCF) $(INC) $(OBJ) $(LIB) -o $(NAME)

%.o: %.c
	$(CCF) $(INC) -c $< -o $@

clean:
	@rm -rfv $(OBJ)

fclean: clean
	@rm -rfv $(NAME)

re: fclean all

.PHONY: all clean fclean re
