/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validations.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmadzaaza <ahmadzaaza@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 03:00:03 by azaaza            #+#    #+#             */
/*   Updated: 2023/10/21 16:09:02 by ahmadzaaza       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

/**
Map name validation:

Validate that the map ends with `.ber` extension.

We basically compare the last 4 characters of the given name to `.ber`. It should match.
*/

static int	validate_map_name(char *name)
{
	int	len;

	len = ft_strlen(name);
	if (ft_strcmp(name + len - 4, ".ber") != 0)
	{
		ft_printf("Error\nInvalid map name\n");
		return (0);
	}
	return (1);
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

static int	validate_line(char *line)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(line);
	while (i < len)
	{
		if (line[i] != '1' && line[i] != '0' && line[i] != 'C' && line[i] != 'E'
			&& line[i] != 'P')
		{
			ft_printf("Error\nInvalid character in map\n");
			free(line);
			return (0);
		}
		i++;
	}
	return (1);
}

/**
Map parsing:

After making sure that the given map name is valid, we attempt to read the file line by line.
We make sure that the line is valid. then enqueue it to the queue object. which we then dump into
a 2d string array which represents the rows and cols in the game.

We also keep track of the rows and cols count in the game object.

Then, we extract the player and exit coordinates from the array and store it in the game object.
*/

int	parse_map(char *name, t_game *game)
{
	int		fd;
	char	*line;

	init_map(&game->map);
	init_map_queue(&game->queue);
	if ((fd = open(name, O_RDONLY)) < 0)
	{
		ft_printf("Error\n Cannot open map or invalid map name\n");
		return (0);
	}
	line = get_next_line(fd);
	while (line)
	{
		if (!validate_line(ft_strtrim(line, "\n")))
			return (0);
		enqueue(&game->queue, ft_strtrim(line, "\n"));
		free(line);
		line = get_next_line(fd);
	}
	if (close(fd) < 0)
	{
		ft_printf("Error\n Cannot close map\n");
		return (0);
	}
	parse_map_from_queue(game);
	extract_exit_and_player_from_map(game);
	return (1);
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
int	validate_args(int argc, char **argv, t_game *game)
{
	if (argc != 2)
	{
		ft_printf("Error\nInvalid number of arguments\n");
		return (0);
	}
	if (!validate_map_name(argv[1]) || !parse_map(argv[1], game)
		|| !validate_map(game))
		return (0);
	return (1);
}
