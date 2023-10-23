/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiles.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmadzaaza <ahmadzaaza@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 01:14:07 by azaaza            #+#    #+#             */
/*   Updated: 2023/10/24 01:54:22 by ahmadzaaza       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"
#include <stdio.h>
#include <time.h>

void	draw_wall(t_game *game, int row, int col)
{
	mlx_put_image_to_window(game->mlx, game->win, game->tiles.wall, col
		* TILE_SIZE, (row + 1) * TILE_SIZE);
}

static void	draw_coin(t_game *game, int row, int col)
{
	clock_t	c;

	c = clock();
	if (!game->frame)
		game->frame = 0;
	mlx_put_image_to_window(game->mlx, game->win, game->tiles.collectible[(c / 100000) % 11],
		col * TILE_SIZE, (row + 1) * TILE_SIZE);
}

/**
Row starting from 1 because we need to render the fonts on a black bg
*/
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
					col * TILE_SIZE, (row + 1) * TILE_SIZE);
				draw_coin(game, row, col);
			}
			else if (game->map.map[row][col] == '0'
				|| game->map.map[row][col] == 'P')
			{
				mlx_put_image_to_window(game->mlx, game->win, game->tiles.floor,
					col * TILE_SIZE, (row + 1) * TILE_SIZE);
			}
			col++;
		}
		row++;
	}
}

void	load_tiles(t_game *game)
{
	game->tiles.wall = xpm_to_image(&game, "textures/world/rock.xpm");
	game->tiles.collectible[0] = xpm_to_image(&game,
			"textures/world/coin/coin0.xpm");
	game->tiles.collectible[1] = xpm_to_image(&game,
			"textures/world/coin/coin1.xpm");
	game->tiles.collectible[2] = xpm_to_image(&game,
			"textures/world/coin/coin2.xpm");
	game->tiles.collectible[3] = xpm_to_image(&game,
			"textures/world/coin/coin3.xpm");
	game->tiles.collectible[4] = xpm_to_image(&game,
			"textures/world/coin/coin4.xpm");
	game->tiles.collectible[5] = xpm_to_image(&game,
			"textures/world/coin/coin5.xpm");
	game->tiles.collectible[6] = xpm_to_image(&game,
			"textures/world/coin/coin6.xpm");
	game->tiles.collectible[7] = xpm_to_image(&game,
			"textures/world/coin/coin7.xpm");
	game->tiles.collectible[8] = xpm_to_image(&game,
			"textures/world/coin/coin8.xpm");
	game->tiles.collectible[9] = xpm_to_image(&game,
			"textures/world/coin/coin9.xpm");
	game->tiles.collectible[10] = xpm_to_image(&game,
			"textures/world/coin/coin10.xpm");
	game->tiles.floor = xpm_to_image(&game, "textures/world/floor.xpm");
}

void	destroy_tiles(t_game *game)
{
	mlx_destroy_image(game->mlx, game->tiles.floor);
	mlx_destroy_image(game->mlx, game->tiles.wall);
	mlx_destroy_image(game->mlx, game->tiles.collectible[0]);
	mlx_destroy_image(game->mlx, game->player.images[0]);
	mlx_destroy_image(game->mlx, game->player.images[1]);
	mlx_destroy_image(game->mlx, game->player.images[2]);
	mlx_destroy_image(game->mlx, game->player.images[3]);
}