/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaaza <azaaza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 20:20:45 by azaaza            #+#    #+#             */
/*   Updated: 2023/08/26 15:54:19 by azaaza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	count_characters(char **str, char c)
{
	int	count;
	int	i;
	int	j;

	i = 0;
	count = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (str[i][j] == c)
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

int	check_exist_and_duplicates(t_game *game)
{
	int	exit_count;
	int	player_count;
	int	collectible_count;

	exit_count = count_characters(game->map.map, 'E');
	player_count = count_characters(game->map.map, 'P');
	collectible_count = count_characters(game->map.map, 'C');
	if (exit_count == 0 || player_count == 0)
	{
		ft_printf("Error\nNo exit or player found\n");
		return (0);
	}
	if (exit_count > 1 || player_count > 1)
	{
		ft_printf("Error\nDuplicate exit or player found\n");
		return (0);
	}
	if (!(collectible_count > 0))
	{
		ft_printf("Error\nCollectibles not found \n");
		return (0);
	}
	game->map.collectibles = collectible_count;
	return (1);
}
