/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aareslan <aareslan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 13:41:59 by aareslan          #+#    #+#             */
/*   Updated: 2025/08/14 13:42:32 by aareslan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**new_map(int initial_capacity)
{
	char	**map;
	int		i;

	map = malloc(sizeof(char *) * initial_capacity);
	if (!map)
		return (NULL);
	i = 0;
	while (i < initial_capacity)
	{
		map[i] = NULL;
		i++;
	}
	return (map);
}
