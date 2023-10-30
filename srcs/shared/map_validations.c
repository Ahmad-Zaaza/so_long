/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmadzaaza <ahmadzaaza@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 20:20:45 by azaaza            #+#    #+#             */
/*   Updated: 2023/10/31 00:43:38 by ahmadzaaza       ###   ########.fr       */
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

/**
  Rectangular shape check!

  We can check the map is rectangular by getting the length of the first row as a reference.
  All subsequent rows should have the same length. otherwise it might look like a spaghetti (yum).

*/
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

/**
  Cage check!

  What cage means is actually the first and the last rows are constructed of character '1',
	also the first
  and the last characters of each row are also walls.

  This would only give honest answer when the map is rectangular. because we're using the
  columns count for getting the last col of the row. that's why we do it after. (consistency is key!)
*/
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

/**
  Did i say stuck ?!

  Now comes the hard part. the flexing part.
  We have to check the player can grab every collectable. and can also reach the exit.

  We do it by simulating the player movements,  putting ourselfs in his shoe,
	going in every direction until
  we reach our destination.

  In our blessed journey, we hum hum every collectable,
	keeping track of it. We don't give up
  until we get every last one of them. And only then, the exit appears!

  First we create our virtual map, we call it visited,
	because it's job is to only tell us if we have
  stepped into a specific tile of the map or not (0 | 1). we fill it with 0s for a start,
	then we start the journey.

  btw, the whole mumbo jumbo bullshit i just wrote,
	is the implementation of a so called "Depth first search" algorithm.
  It was just a poor effort from me to flex on you.
*/
static int	has_valid_paths(t_game *game)
{
	int	**visited;
	int	collected;
	int	row;
	int	col;

	visited = create_visited_arr(game);
	if (!visited)
		return (0);
	row = 0;
	col = 0;
	collected = 0;
	while (row < game->map.rows)
	{
		while (col < game->map.columns)
		{
			visited[row][col] = 0;
			col++;
		}
		row++;
	}
	if (dfs(game, &collected, visited, game->player.row, game->player.col))
	{
		free_visited(visited, game->map.rows);
		return (1);
	}
	free_visited(visited, game->map.rows);
	print_error("Map has no valid paths");
	return (0);
}

/**
  Map validation:

  After dumping the map queue into a 2d string array,
	we start our series of validations.

  We validate that the map only have one exit and one player. And have a rectangular shape.

  We also check that it's encloesd by walls so we don't get lost in the vortex.

  Lastly,
	the map should have valid paths to the collectibles and the exit (unless you wanna get stuck).
*/
void	validate_map(t_game *game)
{
	if (!check_exist_and_duplicates(game) || !check_if_rectangular(game->map)
		|| !check_enclosed_by_walls(game->map) || !has_valid_paths(game))
	{
		cleanup_map(game);
		exit(1);
	}
}
