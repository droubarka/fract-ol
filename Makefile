# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mait-oub <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/01 20:07:18 by mait-oub          #+#    #+#              #
#    Updated: 2025/03/22 16:37:12 by mait-oub         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MAKEFLAGS += --no-builtin-rules

SRC_DIR = src
OBJ_DIR = obj
INC_DIR = include
LIB_DIR = ~/goinfre/usr/include/minilibx-linux

CC = cc
CFLAGS = -Wall -Wextra -Werror -I $(INC_DIR) -I $(LIB_DIR)
LIBFLAGS = -L $(LIB_DIR) -lmlx -lXext -lX11

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
	$(SRC_DIR)/fractal_hooks.c \
	$(SRC_DIR)/fractal_init.c \
	$(SRC_DIR)/fractal_runtime.c \
	$(FRACTALS_FILES) \
	$(SRC_DIR)/fractal_transform.c \
	$(UTILS_FILES)

INC_FILES = \
	$(INC_DIR)/fractal.h \
	$(INC_DIR)/utils.h

MANDATORY_SRCS = $(SRC_FILES) $(SRC_DIR)/main.c
BONUS_SRCS = $(SRC_FILES) $(SRC_DIR)/main_bonus.c $(FRACTALS_DIR)/tricorn.c

MANDATORY_OBJS = $(patsubst src/%.c, $(OBJ_DIR)/%.o, $(MANDATORY_SRCS))
BONUS_OBJS = $(patsubst src/%.c, $(OBJ_DIR)/%.o, $(BONUS_SRCS))

PREBUILD = $(OBJ_DIR) $(OBJ_DIR)/fractals $(OBJ_DIR)/utils $(OBJ_DIR)/utils/libc
$(PREBUILD):
	@mkdir -v -p $@

SYMB_LINKS = MANDATORY BONUS
$(SYMB_LINKS):
	@if [ "$(realpath $(NAME))" = "" ]; then \
		ln -svf $(NAME_$@) $(NAME); \
	elif [ "$(realpath $(NAME_$@))" != "$(realpath $(NAME))" ]; then \
		ln -svf $(NAME_$@) $(NAME); \
	else \
		echo "make: '$(NAME)' is up to date."; \
	fi

.DEFAULT_GOAL = all
.PHONY: clean $(SYMB_LINKS)

all: $(NAME_MANDATORY)

bonus: $(NAME_BONUS)

$(NAME_MANDATORY): $(INC_FILES) $(MANDATORY_OBJS) | MANDATORY
	$(CC) $(CFLAGS) -o $@ $(MANDATORY_OBJS) $(LIBFLAGS)

$(NAME_BONUS): $(INC_FILES) $(BONUS_OBJS) | BONUS
	$(CC) $(CFLAGS) -o $@ $(BONUS_OBJS) $(LIBFLAGS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(PREBUILD)
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	@rm -v -rf $(MANDATORY_OBJS) $(BONUS_OBJS)

fclean: clean
	@rm -v -rf $(NAME) $(NAME_MANDATORY) $(NAME_BONUS)

re: fclean all
