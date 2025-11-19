/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aareslan <aareslan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 22:30:46 by aareslan          #+#    #+#             */
/*   Updated: 2025/08/15 16:44:25 by aareslan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	*load_xpm(t_game *game, const char *path)
{
	int		width;
	int		height;
	void	*img;

	img = mlx_xpm_file_to_image(game->mlx, (char *)path, &width, &height);
	if (!img)
	{
		write(2, "Error: Failed to load texture: ", 31);
		write(2, path, ft_strlen(path));
		write(2, "\n", 1);
		clean_exit(game);
	}
	return (img);
}

void	put_image(t_game *game)
{
	game->img_wall = load_xpm(game, "textures/wall.xpm");
	game->img_floor = load_xpm(game, "textures/floor.xpm");
	game->img_player = load_xpm(game, "textures/player.xpm");
	game->img_exit = load_xpm(game, "textures/exit.xpm");
	game->img_collect = load_xpm(game, "textures/collect.xpm");
}
