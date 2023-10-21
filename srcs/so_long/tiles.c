/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiles.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmadzaaza <ahmadzaaza@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 01:14:07 by azaaza            #+#    #+#             */
/*   Updated: 2023/10/21 16:31:25 by ahmadzaaza       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	draw_wall(t_game *game, int row, int col)
{
	mlx_put_image_to_window(game->mlx, game->win, game->tiles.wall, col
		* TILE_SIZE, row * TILE_SIZE);
}

void	draw_tiles(t_game *game)
{
	int	col;
	int	row;

	row = 0;
	while (row < game->map.rows)
	{
		col = 0;
		while (col < game->map.columns)
		{
			if (game->map.map[row][col] == '1')
				draw_wall(game, row, col);
			else if (game->map.map[row][col] == 'C')
			{
				mlx_put_image_to_window(game->mlx, game->win, game->tiles.floor,
					col * TILE_SIZE, row * TILE_SIZE);
				mlx_put_image_to_window(game->mlx, game->win,
					game->tiles.collectible, col * TILE_SIZE, row * TILE_SIZE);
			}
			else if (game->map.map[row][col] == '0'
				|| game->map.map[row][col] == 'P')
			{
				mlx_put_image_to_window(game->mlx, game->win, game->tiles.floor,
					col * TILE_SIZE, row * TILE_SIZE);
			}
			col++;
		}
		row++;
	}
}

void	load_tiles(t_game *game)
{
	int	width;
	int	height;

	game->tiles.wall = mlx_xpm_file_to_image(game->mlx,
			"textures/world/rock.xpm", &width, &height);
	game->tiles.collectible = mlx_xpm_file_to_image(game->mlx,
			"textures/world/coin/coin.xpm", &width, &height);
	game->tiles.floor = mlx_xpm_file_to_image(game->mlx,
			"textures/world/floor.xpm", &width, &height);
}

void	destroy_tiles(t_game *game)
{
	mlx_destroy_image(game->mlx, game->tiles.floor);
	mlx_destroy_image(game->mlx, game->tiles.wall);
	mlx_destroy_image(game->mlx, game->tiles.collectible);
	mlx_destroy_image(game->mlx, game->player.images[0]);
	mlx_destroy_image(game->mlx, game->player.images[1]);
	mlx_destroy_image(game->mlx, game->player.images[2]);
	mlx_destroy_image(game->mlx, game->player.images[3]);
}