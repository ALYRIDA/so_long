/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aareslan <aareslan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 14:58:40 by aareslan          #+#    #+#             */
/*   Updated: 2025/08/13 14:58:40 by aareslan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_error(const char *msg, int code)
{
	size_t	i;

	i = 0;
	while (msg[i])
		write(2, &msg[i++], 1);
	return (code);
}
