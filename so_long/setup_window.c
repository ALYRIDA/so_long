/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_window.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aareslan <aareslan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 22:48:17 by aareslan          #+#    #+#             */
/*   Updated: 2025/08/15 22:48:18 by aareslan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	setup_window(t_game *game)
{
	int	map_width;
	int	map_height;

	map_width = 0;
	map_height = 0;
	while (game->map[0][map_width])
		map_width++;
	while (game->map[map_height])
		map_height++;
	game->width = map_width;
	game->height = map_height;
	game->mlx = mlx_init();
	if (!game->mlx)
		ft_error("Error: Failed to init MLX\n", 1);
	game->win = mlx_new_window(
			game->mlx,
			game->width * TILE_SIZE,
			game->height * TILE_SIZE,
			"So Long"
			);
	if (!game->win)
		ft_error("Error: Failed to create window\n", 1);
	put_image(game);
	display_map(game);
}
