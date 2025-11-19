/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aareslan <aareslan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 22:51:46 by aareslan          #+#    #+#             */
/*   Updated: 2025/08/15 22:51:46 by aareslan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	open_map_file(const char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	return (fd);
}
