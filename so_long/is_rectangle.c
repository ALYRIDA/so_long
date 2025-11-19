/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_rectangle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aareslan <aareslan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 10:43:38 by aareslan          #+#    #+#             */
/*   Updated: 2025/08/14 10:43:38 by aareslan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_rectangle(char **map)
{
	int	row_len;
	int	i;
	int	j;

	if (!map || !map[0])
		return (0);
	row_len = 0;
	while (map[0][row_len])
		row_len++;
	i = 1;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
			j++;
		if (j != row_len)
			return (0);
		i++;
	}
	return (1);
}
