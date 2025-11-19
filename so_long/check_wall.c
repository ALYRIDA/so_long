/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_wall.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aareslan <aareslan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 22:52:27 by aareslan          #+#    #+#             */
/*   Updated: 2025/08/15 22:52:27 by aareslan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_horizontal_walls(char **map, int height, int width)
{
	int	i;

	i = 0;
	while (i < width)
	{
		if (map[0][i] != '1' || map[height - 1][i] != '1')
			return (0);
		i++;
	}
	return (1);
}

static int	check_vertical_walls(char **map, int height, int width)
{
	int	i;

	i = 0;
	while (i < height)
	{
		if (map[i][0] != '1' || map[i][width - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	check_wall(char **map)
{
	int	height;
	int	width;

	if (!map || !map[0])
		return (0);
	height = 0;
	while (map[height])
		height++;
	width = 0;
	while (map[0][width])
		width++;
	if (!check_horizontal_walls(map, height, width))
		return (0);
	if (!check_vertical_walls(map, height, width))
		return (0);
	return (1);
}
