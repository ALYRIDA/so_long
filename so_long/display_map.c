/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aareslan <aareslan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 16:21:03 by aareslan          #+#    #+#             */
/*   Updated: 2025/08/15 16:21:19 by aareslan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	draw_cell(t_game *game, void *img, int x, int y)
{
	mlx_put_image_to_window(
		game->mlx,
		game->win,
		img,
		x * TILE_SIZE,
		y * TILE_SIZE
		);
}

void	display_map(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] != '1')
				draw_cell(game, game->img_floor, x, y);
			if (game->map[y][x] == '1')
				draw_cell(game, game->img_wall, x, y);
			else if (game->map[y][x] == 'P')
				draw_cell(game, game->img_player, x, y);
			else if (game->map[y][x] == 'E')
				draw_cell(game, game->img_exit, x, y);
			else if (game->map[y][x] == 'C')
				draw_cell(game, game->img_collect, x, y);
			x++;
		}
		y++;
	}
}
