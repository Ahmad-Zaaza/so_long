/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmadzaaza <ahmadzaaza@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 22:16:53 by azaaza            #+#    #+#             */
/*   Updated: 2023/10/21 16:33:34 by ahmadzaaza       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"


/**
  This is to check if we can go further.
  we go further only if the cell isn't a wall or we previously visited it before
*/
static int	is_valid_path(t_map *map, int **visited, int row, int col)
{
	if (map->map[row][col] == '1' || visited[row][col] == 1)
		return (0);
	return (1);
}

/**
  The great algorithm!

  The first call of this function is when we have the `row` and `col` of the player,
	as our starting point.
  Because the player can only go one tile at a time,
	a breakdown of the possible moves would look like:

  [x, y] (x for row, y for column)
  ----.
  [0, 1] -> go down on the y axis by one
  [0, -1]-> go up on the y axis by one
  [1, 0] -> go right on the x axis by one
  [-1, 0] -> go left on the x axis by one (0)

  This function calls it self in a recursive way until we find an exit and we gathered all the collectables.
*/
int	dfs(t_game *game, int *collected, int **visited, int row, int col)
{
	int	moves[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
	int	i;
	int	new_row;
	int	new_col;

	visited[row][col] = 1;
	if (game->map.map[row][col] == 'C')
		*collected += 1;
	if (*collected == game->map.collectibles && game->map.map[row][col] == 'E')
		return (1);
	i = 0;
	while (i < 4)
	{
		new_row = row + moves[i][0];
		new_col = col + moves[i][1];
		if (is_valid_path(&game->map, visited, new_row, new_col))
			if (dfs(game, collected, visited, new_row, new_col))
				return (1);
		i++;
	}
	return (0);
}

/**
  Creating the virtual map!

  The job of this array is first to mimic the actual map that we have. and to tell
  us if we have visited a specific tile before.
*/
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

void	free_visited(int **visited, int size)
{
	int i;
	i = 0;
	while (i < size)
	{
		free(visited[i]);
		i++;
	};
	free(visited);
}