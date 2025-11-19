/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aareslan <aareslan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 13:32:41 by aareslan          #+#    #+#             */
/*   Updated: 2025/08/14 13:32:41 by aareslan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		return (ft_error("Usage: ./so_long map.ber\n", 1));
	game.map = read_map(argv[1]);
	if (!game.map)
		return (ft_error("Error: Failed to read map\n", 1));
	game.height = get_map_height(game.map);
	game.width = get_map_width(game.map);
	if (!is_rectangle(game.map)
		|| !check_wall(game.map)
		|| !check_map_rules(game.map))
		return (ft_error("Error: Invalid map\n", 1));
	player_position(&game);
	game.moves = 0;
	if (!can_solve(&game))
		return (ft_error("Error: Map not solvable\n", 1));
	setup_window(&game);
	mlx_key_hook(game.win, process_keypress, &game);
	mlx_hook(game.win, 17, 0, clean_exit, &game);
	mlx_loop(game.mlx);
	free_map(game.map);
	return (0);
}
