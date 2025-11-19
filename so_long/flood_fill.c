/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aareslan <aareslan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 21:53:55 by aareslan          #+#    #+#             */
/*   Updated: 2025/08/14 09:53:24 by aareslan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	**map_dup(char **map, int h)
{
	char	**copy;
	int		i;

	copy = malloc(sizeof(char *) * (h + 1));
	if (!copy)
		return (NULL);
	i = 0;
	while (i < h)
	{
		copy[i] = str_trim(map[i]);
		if (!copy[i])
		{
			free_map(copy);
			return (NULL);
		}
		i++;
	}
	copy[h] = NULL;
	return (copy);
}

static void	fill(char **map, int x, int y)
{
	if (y < 0 || map[y] == NULL || x < 0 || map[y][x] == '\0')
		return ;
	if (map[y][x] == '1' || map[y][x] == 'F')
		return ;
	map[y][x] = 'F';
	fill(map, x + 1, y);
	fill(map, x - 1, y);
	fill(map, x, y + 1);
	fill(map, x, y - 1);
}

int	can_solve(t_game *game)
{
	char	**copy;
	int		i;
	int		j;

	copy = map_dup(game->map, game->height);
	if (!copy)
		return (0);
	fill(copy, game->player_x, game->player_y);
	i = 0;
	while (copy[i])
	{
		j = 0;
		while (copy[i][j])
		{
			if (copy[i][j] == 'C' || copy[i][j] == 'E')
			{
				free_map(copy);
				return (0);
			}
			j++;
		}
		i++;
	}
	free_map(copy);
	return (1);
}
