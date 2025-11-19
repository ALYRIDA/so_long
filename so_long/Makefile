# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aareslan <aareslan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/13 21:43:28 by aareslan          #+#    #+#              #
#    Updated: 2025/08/13 21:43:28 by aareslan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror -g

SRC = check_map_rules.c \
      check_wall.c \
      display_map.c \
      flood_fill.c \
      found_collectible.c \
      free_map.c \
      ft_error.c \
      height_width.c \
      is_rectangle.c \
      main.c \
      map.c \
      open_file.c \
      player_position.c \
      process_keypress.c \
      put_image.c \
      read_lines_helper.c \
      setup_window.c \
      str_trim.c \
      clean_exit.c \
      winner_massage.c \
      get_next_line.c \
      get_next_line_utils.c

OBJ = $(SRC:.c=.o)

MLX_DIR = ../minilibx-linux

all: mlx $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -L$(MLX_DIR) -lmlx -lm -lXext -lX11 -o $(NAME)

mlx:
	$(MAKE) -C $(MLX_DIR)

clean:
	$(MAKE) -C $(MLX_DIR) clean
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re mlx
