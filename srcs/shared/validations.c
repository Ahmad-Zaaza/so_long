/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validations.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmadzaaza <ahmadzaaza@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 03:00:03 by azaaza            #+#    #+#             */
/*   Updated: 2023/10/30 02:22:12 by ahmadzaaza       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

/**
Map name validation:

Validate that the map ends with `.ber` extension.

We basically compare the last 4 characters of the given name to `.ber`. It should match.
*/

static void	validate_map_name(char *name)
{
	int	len;

	len = ft_strlen(name);
	if (ft_strcmp(name + len - 4, ".ber") != 0)
	{
		print_error("Invalid map name");
		exit(1);
	}
}

/**
Map line validation:

Makes sure that the given line has only the supported characters.

'1' for a wall.
'0' for a path.
'P' for a player.
'C' for a collectable.
'E' for an exit.

*/

static void	validate_line(char *line, t_map_queue *queue)
{
	int		i;
	int		len;
	char	*trimmed;

	i = 0;
	trimmed = ft_strtrim(line, "\n");
	len = ft_strlen(trimmed);
	while (i < len)
	{
		if (trimmed[i] != '1' && trimmed[i] != '0' && trimmed[i] != 'C'
			&& trimmed[i] != 'E' && trimmed[i] != 'P')
		{
			print_error("Invalid character in map");
			free(trimmed);
			free(line);
			cleanup_queue(queue);
			exit(1);
		}
		i++;
	}
	free(trimmed);
}

/**
Map parsing:

After making sure that the given map name is valid,
	we attempt to read the file line by line.
We make sure that the line is valid. then enqueue it to the queue object. which we then dump into
a 2d string array which represents the rows and cols in the game.

We also keep track of the rows and cols count in the game object.

Then,
	we extract the player and exit coordinates from the array and store it in the game object.
*/

static void	parse_map(char *name, t_game *game)
{
	int		fd;
	char	*line;

	if ((fd = open(name, O_RDONLY)) < 0)
	{
		print_error(strerror(errno));
		exit(1);
	}
	line = get_next_line(fd);
	while (line)
	{
		validate_line(line, &game->queue);
		enqueue(&game->queue, ft_strtrim(line, "\n"));
		free(line);
		line = get_next_line(fd);
	}
	if (close(fd) < 0)
	{
		print_error(strerror(errno));
		cleanup_queue(&game->queue);
		exit(1);
	}
	parse_map_from_queue(game);
	extract_exit_and_player_from_map(game);
}

/**
Arguments validation:

- We only accept one argument which is the path to the desired map.

First,  we validate the map name,
	and make sure that it ends with a `.ber` extension.

Secondly, we read the file defined in the path,
	then extract each line which represents a row in the game map.
we make sure that the line only contains supported characters. then add it to the queue object which we parse
to construct our game information (map, player).

Lastly, we make sure that the map is enclosed by walls, has a rectangular shape,
	and has valid paths
towards the loot and exit.

*/
void	validate_args(int argc, char **argv, t_game *game)
{
	if (argc != 2)
	{
		print_error("Invalid number of arguments. Usage: ./so_long <path_to_map>");
		exit(1);
	}
	validate_map_name(argv[1]);
	init_map(&game->map);
	init_map_queue(&game->queue);
	parse_map(argv[1], game);
	validate_map(game);
}
