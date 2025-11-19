/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_keypress.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aareslan <aareslan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 14:33:37 by aareslan          #+#    #+#             */
/*   Updated: 2025/08/15 13:17:53 by aareslan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_putnbr(int n)
{
	char	c;

	if (n >= 10)
		ft_putnbr(n / 10);
	c = (n % 10) + '0';
	write(1, &c, 1);
}

static void	print_moves(int moves)
{
	write(1, "Moves: ", 7);
	ft_putnbr(moves);
	write(1, "\n", 1);
}

int	close_game(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	free_map(game->map);
	exit(0);
	return (0);
}

static void	count_moves(t_game *game, int new_x, int new_y)
{
	char	target;

	target = game->map[new_y][new_x];
	if (target == '1')
		return ;
	if (target == 'C')
		game->map[new_y][new_x] = '0';
	if (target == 'E')
	{
		if (!found_collectible(game))
		{
			winnner_message();
			clean_exit(game);
		}
		else
			return ;
	}
	game->map[game->player_y][game->player_x] = '0';
	game->map[new_y][new_x] = 'P';
	game->player_x = new_x;
	game->player_y = new_y;
	game->moves++;
	print_moves(game->moves);
	display_map(game);
}

int	process_keypress(int keycode, t_game *game)
{
	if (keycode == 65307)
		clean_exit(game);
	else if (keycode == 119)
		count_moves(game, game->player_x, game->player_y - 1);
	else if (keycode == 115)
		count_moves(game, game->player_x, game->player_y + 1);
	else if (keycode == 97)
		count_moves(game, game->player_x - 1, game->player_y);
	else if (keycode == 100)
		count_moves(game, game->player_x + 1, game->player_y);
	return (0);
}
