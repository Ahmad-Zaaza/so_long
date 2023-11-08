/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmadzaaza <ahmadzaaza@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 20:20:45 by azaaza            #+#    #+#             */
/*   Updated: 2023/11/08 23:42:17 by ahmadzaaza       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_mandatory.h"

static int	is_walls(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	check_if_rectangular(t_map map)
{
	size_t	first_row_len;
	int		row;

	first_row_len = ft_strlen(map.map[0]);
	row = 1;
	while (row < map.rows)
	{
		if (ft_strlen(map.map[row]) != first_row_len)
		{
			print_error("Map is not rectangular");
			return (0);
		}
		row++;
	}
	return (1);
}

int	check_enclosed_by_walls(t_map map)
{
	int	row;

	row = 0;
	if (!is_walls(map.map[0]) || !is_walls(map.map[map.rows - 1]))
	{
		print_error("Map is not enclosed by walls");
		return (0);
	}
	while (row < map.rows)
	{
		if (map.map[row][0] != '1' || map.map[row][map.columns - 1] != '1')
		{
			print_error("Map is not enclosed by walls");
			return (0);
		}
		row++;
	}
	return (1);
}

static int	has_valid_paths(t_game *game)
{
	int	collected;
	int	row;
	int	col;

	game->visited_arr = create_visited_arr(game);
	if (!game->visited_arr)
		return (0);
	row = 0;
	col = 0;
	collected = 0;
	while (row < game->map.rows)
	{
		while (col < game->map.columns)
			game->visited_arr[row][col++] = 0;
		row++;
	}
	if (dfs(game, &collected, game->player.row, game->player.col))
	{
		free_visited(game->visited_arr, game->map.rows);
		return (1);
	}
	free_visited(game->visited_arr, game->map.rows);
	print_error("Map has no valid paths");
	return (0);
}

void	validate_map(t_game *game)
{
	if (!check_exist_and_duplicates(game) || !check_if_rectangular(game->map)
		|| !check_enclosed_by_walls(game->map) || !has_valid_paths(game))
	{
		cleanup_map(game);
		exit(1);
	}
}
