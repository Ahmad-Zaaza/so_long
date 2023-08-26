/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaaza <azaaza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 20:55:30 by azaaza            #+#    #+#             */
/*   Updated: 2023/08/26 21:44:10 by azaaza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/include/ft_printf.h"
#include "libft/libft.h"
#include "so_long.h"

static int	count_characters(t_map *map, char c)
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

void	init_map(t_map *map)
{
	map->columns = 0;
	map->rows = 0;
	map->map = NULL;
	map->map_path = NULL;
}

void	parse_map_from_queue(t_game *game)
{
	char	**map_data;
	int		len;
	int		i;

	i = 0;
	len = queue_size(&game->queue);
	map_data = (char **)malloc((len + 1) * sizeof(char *));
	if (!map_data)
	{
		ft_printf("Error:\n Cannot allocate memory for map\n");
		exit(1);
	}
	while (i < len)
	{
		map_data[i] = dequeue(&game->queue);
		game->map.columns = ft_strlen(map_data[i]);
		i++;
	}
	map_data[i] = "\0";
	game->map.rows = len;
	ft_printf("Rows: %d\n", game->map.rows);
	ft_printf("Columns %d\n", game->map.columns);
	game->map.map = map_data;
}

void	extract_exit_and_player_from_map(t_game *game)
{
	int	row;
	int	column;

	row = 0;
	while (row < game->map.rows)
	{
		column = 0;
		while (game->map.map[row][column])
		{
			if (game->map.map[row][column] == 'E')
			{
				game->map.map_exit.row = row;
				game->map.map_exit.col = column;
			}
			else if (game->map.map[row][column] == 'P')
			{
				game->player.row = row;
				game->player.col = column;
			}
			column++;
		}
		row++;
	}
}

int	check_exist_and_duplicates(t_game *game)
{
	int	exit_count;
	int	player_count;
	int	collectible_count;

	exit_count = count_characters(&game->map, 'E');
	player_count = count_characters(&game->map, 'P');
	collectible_count = count_characters(&game->map, 'C');
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

// void count_collectibles(t_game *game)
// {
// 	int		row;
// 	int		column;
// 	char	**map;

// 	row = 0;
// 	while (game->map.map[row])
// 	{
// 		column = 0;
// 		while (map[row][column])
// 		{
// 			if (map[row][column] == 'C')
// 				game->map.collectibles++;
// 			column++;
// 		}
// 		row++;
// 	}
// }