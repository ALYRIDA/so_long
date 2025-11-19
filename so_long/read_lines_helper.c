/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_lines_helper.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aareslan <aareslan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 14:39:38 by aareslan          #+#    #+#             */
/*   Updated: 2025/08/14 14:42:04 by aareslan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**read_lines_helper(char **map, char *line, int *size, int *capacity)
{
	char	**tmp;

	tmp = add_line(map, line, size, capacity);
	free(line);
	if (!tmp)
	{
		free_map(map);
		return (NULL);
	}
	return (tmp);
}
