/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaaza <azaaza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 20:55:30 by azaaza            #+#    #+#             */
/*   Updated: 2023/08/24 20:00:04 by azaaza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/include/ft_printf.h"
#include "libft/libft.h"
#include "so_long.h"

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
		game->map.columns += ft_strlen(map_data[i]);
		i++;
	}
	map_data[i] = "\0";
	game->map.rows = len;
	ft_printf("Rows: %d\n", game->map.rows);
	ft_printf("Columns %d\n", game->map.columns);
	game->map.map = map_data;
	i = 0;
}

void	extract_exit_from_map(t_game *game)
{
	int row;
	int column;
	char **map;
	int found;

	row = 0;
	column = 0;
	found = 0;
	map = game->map.map;

	while (map[column])
	{
		while (map[column][row])
		{
			if (map[column][row] == 'E')
			{
				game->map.map_exit.row = row;
				game->map.map_exit.row = column;
				found = 1;
				break ;
			}
			row++;
		}
		column++;
	}
	if (found != 1)
	{
		ft_printf("Error\nNo exit found\n");
		exit(1);
	}
}