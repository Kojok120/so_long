# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kokamoto <kojokamo120@gmail.com>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/29 22:03:04 by kokamoto          #+#    #+#              #
#    Updated: 2025/01/04 16:38:51 by kokamoto         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror
MLX_FLAGS = -lX11 -lXext

# Directories
SRC_DIR = src
OBJ_DIR = obj
LIBFT_DIR = libft
MLX_DIR = minilibx-linux

# Source files
SRC_FILES = game_exit.c \
           handle_keys.c \
           init.c \
           main.c \
           map_draw.c \
           map_read.c \
		   validate_map.c \
		   validate_reachable.c

SRC = $(addprefix $(SRC_DIR)/, $(SRC_FILES))
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC_FILES:.c=.o))

# Libraries
LIBFT = $(LIBFT_DIR)/libft.a
MLX = $(MLX_DIR)/libmlx.a

all: $(NAME)

# Create object directory
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Compile source files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -I$(SRC_DIR) -I$(LIBFT_DIR) -I$(MLX_DIR) -c $< -o $@

# Build libraries
$(LIBFT):
	make -C $(LIBFT_DIR)

$(MLX):
	make -C $(MLX_DIR)

# Build so_long
$(NAME): $(LIBFT) $(MLX) $(OBJ)
	$(CC) $(OBJ) -L$(LIBFT_DIR) -lft -L$(MLX_DIR) -lmlx $(MLX_FLAGS) -o $(NAME)

clean:
	rm -rf $(OBJ_DIR)
	make -C $(LIBFT_DIR) clean
	make -C $(MLX_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
