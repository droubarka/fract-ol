CC = cc
CFLAGS = -Wall -Wextra -Werror -g
NAME = fractal

CCF = $(CC) $(CFLAGS)

SRC = src/main.c \
	  src/fractal_init.c \
	  src/fractal_loop.c \
	  src/fractal_zoom.c \
	  src/fractal_colors.c \
	  src/utils/remap.c \
	  src/utils/ft_strncmp.c \
	  src/fractals/mandelbrot.c \
	  src/fractals/mandelbrot_hooks.c \
	  src/fractals/julia.c \
	  src/fractals/julia_hooks.c \
	  src/fractals/tricorn.c \
	  src/fractals/tricorn_hooks.c \

OBJ = $(SRC:.c=.o)
INC = -I include -I /usr/include/minilibx-linux
LIB = -L/usr/include/minilibx-linux -lmlx -lX11 -lXext

all: $(OBJ)
	$(CCF) $(INC) $(OBJ) $(LIB) -lm -o $(NAME)

%.o: %.c
	$(CCF) $(INC) -g -c $< -o $@

clean:
	@rm -rfv $(OBJ)

fclean: clean
	@rm -rfv $(NAME)

re: fclean all

.PHONY: all clean fclean re
