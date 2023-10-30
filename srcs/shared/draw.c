/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmadzaaza <ahmadzaaza@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 17:42:03 by ahmadzaaza        #+#    #+#             */
/*   Updated: 2023/10/31 00:29:02 by ahmadzaaza       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_mandatory.h"

static void	draw_floor(t_game *game, int row, int col)
{
	mlx_put_image_to_window(game->mlx, game->win, game->tiles.floor, col
		* TILE_SIZE, row * TILE_SIZE);
}

void	draw_wall(t_game *game, int row, int col)
{
	mlx_put_image_to_window(game->mlx, game->win, game->tiles.wall, col
		* TILE_SIZE, row * TILE_SIZE);
}

static void	draw_coin(t_game *game, int row, int col)
{
	draw_floor(game, row, col);
	mlx_put_image_to_window(game->mlx, game->win, game->tiles.collectible, col
		* TILE_SIZE, row * TILE_SIZE);
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
				draw_coin(game, row, col);
			else if (game->map.map[row][col] == '0'
				|| game->map.map[row][col] == 'P')
				draw_floor(game, row, col);
			col++;
		}
		row++;
	}
}

/**
  Render player

  We use this function inside the mlx frame loop.

  We access the images array using the current direction and pass it to mlx to render.
*/
void	draw_player(t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->win,
		game->player.images[game->player.direction], game->player.col
		* TILE_SIZE, game->player.row * TILE_SIZE);
}
