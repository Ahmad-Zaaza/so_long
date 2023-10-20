/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validations.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaaza <azaaza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 03:00:03 by azaaza            #+#    #+#             */
/*   Updated: 2023/08/26 21:46:18 by azaaza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

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
	check_exist_and_duplicates(game);
	return (1);
}

int	validate_args(int argc, char **argv, t_game *game)
{
	if (argc != 2)
	{
		ft_printf("Error\nInvalid number of arguments\n");
		return (0);
	}
	// validate map name
	if (!validate_map_name(argv[1]) || !parse_map(argv[1], game)
		|| !validate_map(game))
	{
		return (0);
	}
	return (1);
}
