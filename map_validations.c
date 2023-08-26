/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaaza <azaaza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 20:20:45 by azaaza            #+#    #+#             */
/*   Updated: 2023/08/26 21:44:31 by azaaza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "so_long.h"

static int	is_wall(char c)
{
	if (c == '1')
		return (1);
	return (0);
}

static int	is_walls(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!is_wall(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	check_if_rectangular(t_map map)
{
	int	first_row_len;
	int	row;

	first_row_len = ft_strlen(map.map[0]);
	row = 1;
	while (row < map.rows)
	{
		if (ft_strlen(map.map[row]) != first_row_len)
		{
			ft_printf("Error\nMap is not rectangular\n");
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
	row = 0;
	if (!is_walls(map.map[0]) || !is_walls(map.map[map.rows - 1]))
	{
		ft_printf("Error\nMap is not enclosed by walls\n");
		return (0);
	}
	while (row < map.rows)
	{
		if (!is_wall(map.map[row][0]) || !is_wall(map.map[row][map.columns
				- 1]))
		{
			ft_printf("Error\nMap is not enclosed by walls\n");
			return (0);
		}
		row++;
	}
	return (1);
}

int	validate_map(t_game *game)
{
	if (!check_if_rectangular(game->map) || !check_enclosed_by_walls(game->map))
	{
		return (0);
	}
	return (1);
}
