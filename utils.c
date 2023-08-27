/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaaza <azaaza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 18:58:50 by azaaza            #+#    #+#             */
/*   Updated: 2023/08/27 20:28:14 by azaaza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_characters(t_map *map, char c)
{
	int	count;
	int	i;
	int	j;

	i = 0;
	count = 0;
	while (i < map->rows)
	{
		j = 0;
		while (map->map[i][j])
		{
			if (map->map[i][j] == c)
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

void	handle_collactable(t_game *game, int row, int col)
{
	game->map.map[row][col] = '0';
	game->player.collectables_gathered++;
}