/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validations.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmadzaaza <ahmadzaaza@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 03:00:03 by azaaza            #+#    #+#             */
/*   Updated: 2023/11/08 23:43:15 by ahmadzaaza       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_mandatory.h"

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

static void	validate_line(char *line, t_game *game)
{
	int		i;
	int		len;
	char	*trimmed;

	i = 0;
	trimmed = ft_strtrim(line, "\n");
	len = ft_strlen(trimmed);
	while (i < len)
	{
		if (!is_valid_char(trimmed[i]))
		{
			print_error("Invalid character in map");
			free(trimmed);
			free(line);
			cleanup_queue(&game->queue);
			exit(1);
		}
		i++;
	}
	free(trimmed);
}

static void	parse_map(char *name, t_game *game)
{
	int		fd;
	char	*line;

	fd = open(name, O_RDONLY);
	if (fd < 0)
	{
		print_error(strerror(errno));
		exit(1);
	}
	line = get_next_line(fd);
	while (line)
	{
		validate_line(line, game);
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

void	validate_args(int argc, char **argv, t_game *game)
{
	if (argc != 2)
	{
		print_error("Invalid number of arguments. \
		Usage: ./so_long <path_to_map>");
		exit(1);
	}
	validate_map_name(argv[1]);
	init_map(&game->map);
	init_map_queue(&game->queue);
	parse_map(argv[1], game);
	validate_map(game);
}
