/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   found_collectible.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aareslan <aareslan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 23:29:57 by aareslan          #+#    #+#             */
/*   Updated: 2025/08/13 23:30:10 by aareslan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	found_collectible(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'C')
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}
