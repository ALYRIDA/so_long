/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aareslan <aareslan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 22:48:03 by aareslan          #+#    #+#             */
/*   Updated: 2025/08/15 22:48:03 by aareslan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <string.h>
# include "get_next_line.h"
# include "../minilibx-linux/mlx.h"

# define TILE_SIZE 32

typedef struct s_game
{
	char	**map;
	int		width;
	int		height;
	int		player_x;
	int		player_y;
	void	*win;
	void	*mlx;
	int		collectibles;
	void	*img_wall;
	void	*img_floor;
	void	*img_collect;
	void	*img_player;
	void	*img_exit;
	int		moves;
}	t_game;

int		ft_error(const char *msg, int code);
void	free_map(char **map);
int		open_map_file(const char *filename);
int		check_wall(char **map);
char	**read_map(const char *filename);
int		check_map_rules(char **map);
void	player_position(t_game *game);
int		is_rectangle(char **map);
void	display_map(t_game *game);
void	winnner_message(void);
int		clean_exit(t_game *game);
int		can_solve(t_game *game);
int		process_keypress(int keycode, t_game *game);
char	*str_trim(const char *s);
void	put_image(t_game *game);
int		found_collectible(t_game *game);
int		get_map_width(char **map);
int		get_map_height(char **map);
void	setup_window(t_game *game);
char	**read_lines_helper(char **map, char *line, int *size, int *capacity);
char	**add_line(char **map, char *line, int *size, int *capacity);

#endif
