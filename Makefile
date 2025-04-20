# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mait-oub <mait-oub@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/01 20:07:18 by mait-oub          #+#    #+#              #
#    Updated: 2025/03/22 16:37:12 by mait-oub         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MAKEFLAGS += --no-builtin-rules

SRC_DIR = src
OBJ_DIR = obj
INC_DIR = include
LIB_DIR = minilibx-linux

CC = cc
CFLAGS = -Wall -Wextra -Werror -I $(INC_DIR) -I $(LIB_DIR)
LIBFLAGS = -L $(LIB_DIR) -lmlx -lXext -lX11 -lm

NAME = fractol
NAME_MANDATORY = .fractal_mandatory
NAME_BONUS = .fractal_bonus

FRACTALS_DIR = $(SRC_DIR)/fractals
FRACTALS_FILES = \
	$(FRACTALS_DIR)/mandelbrot.c \
	$(FRACTALS_DIR)/julia.c

UTILS_DIR = $(SRC_DIR)/utils
UTILS_LIBC_DIR = $(UTILS_DIR)/libc
UTILS_FILES = \
	$(UTILS_DIR)/error.c \
	$(UTILS_DIR)/init_julia_params.c \
	$(UTILS_LIBC_DIR)/ft_isdigit.c \
	$(UTILS_LIBC_DIR)/ft_strlen.c \
	$(UTILS_LIBC_DIR)/ft_strncmp.c \
	$(UTILS_LIBC_DIR)/ft_strtold.c \
	$(UTILS_DIR)/map_value.c

SRC_FILES = \
	$(SRC_DIR)/fractal_colors.c \
	$(SRC_DIR)/fractal_destroy.c \
	$(SRC_DIR)/fractal_init.c \
	$(SRC_DIR)/fractal_runtime.c \
	$(FRACTALS_FILES) \
	$(SRC_DIR)/fractal_transform.c \
	$(UTILS_FILES)

INC_FILES = \
	$(INC_DIR)/fractal.h \
	$(INC_DIR)/utils.h

MANDATORY_SRCS = \
	$(SRC_FILES) \
	$(SRC_DIR)/main.c \
	$(SRC_DIR)/fractal_hooks.c
BONUS_SRCS = \
	$(SRC_FILES) \
	$(SRC_DIR)/main_bonus.c \
	$(SRC_DIR)/fractal_hooks_bonus.c \
	$(FRACTALS_DIR)/julia_dancing_bonus.c \
	$(FRACTALS_DIR)/tricorn_bonus.c

MANDATORY_OBJS = $(patsubst src/%.c, $(OBJ_DIR)/%.o, $(MANDATORY_SRCS))
BONUS_OBJS = $(patsubst src/%.c, $(OBJ_DIR)/%.o, $(BONUS_SRCS))

PREBUILD = \
	$(OBJ_DIR) \
	$(OBJ_DIR)/fractals \
	$(OBJ_DIR)/utils \
	$(OBJ_DIR)/utils/libc
$(PREBUILD):
	@mkdir -v -p $@

SYMB_LINKS = MANDATORY BONUS
$(SYMB_LINKS):
	@if [ "$(realpath $(NAME))" = "" ]; then \
		echo -n "symlink "; \
		ln -snvf $(NAME_$@) $(NAME); \
	elif [ "$(realpath $(NAME_$@))" != "$(realpath $(NAME))" ]; then \
		echo -n "symlink "; \
		ln -snvf $(NAME_$@) $(NAME); \
	else \
		echo "make: '$(NAME)' is up to date."; \
	fi

.DEFAULT_GOAL = $(NAME_BONUS)
.PHONY: $(SYMB_LINKS) clean mlx

mlx:
	@$(MAKE) -C $(LIB_DIR) MAKEFLAGS=

all: $(NAME_MANDATORY) $(NAME_BONUS)

bonus: $(NAME_BONUS)

$(NAME_MANDATORY): $(INC_FILES) $(MANDATORY_OBJS) | MANDATORY
	@echo "linking '$@' <- $(words $(MANDATORY_OBJS)) objects"
	@$(CC) $(CFLAGS) -o $@ $(MANDATORY_OBJS) $(LIBFLAGS)

$(NAME_BONUS): $(INC_FILES) $(BONUS_OBJS) | BONUS
	@echo "linking '$@' <- $(words $(BONUS_OBJS)) objects"
	@$(CC) $(CFLAGS) -o $@ $(BONUS_OBJS) $(LIBFLAGS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(PREBUILD)
	@echo "compile '$<' -> '$@'"
	@$(CC) $(CFLAGS) -c -o $@ $<

clean:
	@rm -v -rf $(MANDATORY_OBJS) $(BONUS_OBJS)

fclean: clean
	@rm -v -rf $(NAME) $(NAME_MANDATORY) $(NAME_BONUS)

re: fclean all
