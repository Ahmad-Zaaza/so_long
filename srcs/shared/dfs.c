/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmadzaaza <ahmadzaaza@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 22:16:53 by azaaza            #+#    #+#             */
/*   Updated: 2023/11/08 23:58:06 by ahmadzaaza       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_mandatory.h"

static int	is_valid_path(t_map *map, int **visited, int row, int col)
{
	if (map->map[row][col] == '1' || visited[row][col] == 1)
		return (0);
	return (1);
}

void	free_visited(int **visited, int size)
{
	int	i;

	i = 0;
	while (i < size)
		free(visited[i++]);
	free(visited);
}

static void	init_moves(int (*moves)[4][2])
{
	(*moves)[0][0] = 0;
	(*moves)[0][1] = 1;
	(*moves)[1][0] = 0;
	(*moves)[1][1] = -1;
	(*moves)[2][0] = 1;
	(*moves)[2][1] = 0;
	(*moves)[3][0] = -1;
	(*moves)[3][1] = 0;
}

int	dfs(t_game *game, int *collected, int row, int col)
{
	int	moves[4][2];
	int	i;
	int	new_row;
	int	new_col;

	init_moves(&moves);
	game->visited_arr[row][col] = 1;
	if (game->map.map[row][col] == 'C')
		*collected += 1;
	if (*collected == game->map.collectibles && game->map.map[row][col] == 'E')
		return (1);
	i = 0;
	while (i < 4)
	{
		new_row = row + moves[i][0];
		new_col = col + moves[i][1];
		if (is_valid_path(&game->map, game->visited_arr, new_row, new_col))
			if (dfs(game, collected, new_row, new_col))
				return (1);
		i++;
	}
	return (0);
}

int	**create_visited_arr(t_game *game)
{
	int	**visited;
	int	i;

	visited = (int **)malloc(sizeof(int *) * game->map.rows);
	if (!visited)
		return (NULL);
	i = 0;
	while (i < game->map.rows)
	{
		visited[i] = (int *)malloc(game->map.columns * sizeof(int));
		if (!visited[i])
		{
			free(visited);
			return (NULL);
		}
		i++;
	}
	return (visited);
}
