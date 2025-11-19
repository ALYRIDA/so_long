/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aareslan <aareslan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 14:33:55 by aareslan          #+#    #+#             */
/*   Updated: 2025/08/14 14:33:55 by aareslan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	*strtrim_without_newline(char *line)
{
	size_t	len;
	size_t	i;
	char	*dup;

	len = 0;
	while (line[len] && line[len] != '\n')
		len++;
	dup = malloc(len + 1);
	if (!dup)
		return (NULL);
	i = 0;
	while (i < len)
	{
		dup[i] = line[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

static char	**make_new_map(char **old, int old_size, int new_size)
{
	char	**new_map;
	int		i;

	new_map = malloc(sizeof(char *) * new_size);
	if (!new_map)
		return (NULL);
	i = 0;
	while (i < old_size)
	{
		new_map[i] = old[i];
		i++;
	}
	return (new_map);
}

char	**add_line(char **map, char *line, int *size, int *capacity)
{
	char	**tmp;
	char	*dup;

	if (*size >= *capacity)
	{
		tmp = make_new_map(map, *size, (*capacity) * 2);
		if (!tmp)
		{
			free_map(map);
			return (NULL);
		}
		free(map);
		map = tmp;
		*capacity *= 2;
	}
	dup = strtrim_without_newline(line);
	if (!dup)
	{
		free_map(map);
		return (NULL);
	}
	map[*size] = dup;
	(*size)++;
	return (map);
}

static char	**read_lines(int fd)
{
	char	**map;
	char	*line;
	int		size;
	int		capacity;

	size = 0;
	capacity = 8;
	map = malloc(sizeof(char *) * capacity);
	if (!map)
		return (NULL);
	line = get_next_line(fd);
	while (line)
	{
		map = read_lines_helper(map, line, &size, &capacity);
		if (!map)
			return (NULL);
		line = get_next_line(fd);
	}
	map[size] = NULL;
	return (map);
}

char	**read_map(const char *filename)
{
	int		fd;
	char	**map;

	fd = open_map_file(filename);
	if (fd < 0)
		return (NULL);
	map = read_lines(fd);
	close(fd);
	return (map);
}
