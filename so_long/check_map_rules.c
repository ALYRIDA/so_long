/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_rules.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aareslan <aareslan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 16:24:01 by aareslan          #+#    #+#             */
/*   Updated: 2025/08/15 16:24:09 by aareslan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	allowed_char(char c)
{
	return (c == '0' || c == '1' || c == 'C' || c == 'E' || c == 'P');
}

int	check_map_rules_helper(char **map, int *p, int *c, int *e)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (!allowed_char(map[i][j]))
				return (0);
			if (map[i][j] == 'P')
				(*p)++;
			else if (map[i][j] == 'C')
				(*c)++;
			else if (map[i][j] == 'E')
				(*e)++;
			j++;
		}
		i++;
	}
	return (1);
}

int	check_map_rules(char **map)
{
	int	p;
	int	c;
	int	e;

	p = 0;
	c = 0;
	e = 0;
	if (!check_map_rules_helper(map, &p, &c, &e))
		return (0);
	return (p == 1 && e == 1 && c >= 1);
}
