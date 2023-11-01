/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmadzaaza <ahmadzaaza@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 17:42:03 by ahmadzaaza        #+#    #+#             */
/*   Updated: 2023/11/02 00:33:44 by ahmadzaaza       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

/**
  Render player

  We use this function inside the mlx frame loop.

  We access the images array using the current direction and pass it to mlx to render.
*/

void	draw_player(t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->win,
		game->player.images[game->player.direction], game->player.col
		* TILE_SIZE, (game->player.row + 1) * TILE_SIZE);
}

void	draw_floor(t_game *game, int row, int col)
{
	mlx_put_image_to_window(game->mlx, game->win, game->tiles.floor, col
		* TILE_SIZE, row * TILE_SIZE);
}

void	draw_wall(t_game *game, int row, int col)
{
	mlx_put_image_to_window(game->mlx, game->win, game->tiles.wall, col
		* TILE_SIZE, row * TILE_SIZE);
}

static void	draw_enemy(t_game *game, int row, int col)
{
	draw_floor(game, row, col);
	mlx_put_image_to_window(game->mlx, game->win, game->enemy.image, col
		* TILE_SIZE, row * TILE_SIZE);
}
void	handle_tiles_draw(t_game *game, int row, int col)
{
	if (game->map.map[row][col] == '1')
		draw_wall(game, row + 1, col);
	else if (game->map.map[row][col] == 'C')
		draw_coin(game, row + 1, col);
	else if (game->map.map[row][col] == 'M')
		draw_enemy(game, row + 1, col);
	else if (game->map.map[row][col] == '0' || game->map.map[row][col] == 'P')
		draw_floor(game, row + 1, col);
	else if (game->map.map[row][col] == 'E')
	{
		draw_floor(game, row + 1, col);
		mlx_put_image_to_window(game->mlx, game->win, game->tiles.exit, col
			* TILE_SIZE, (row + 1) * TILE_SIZE);
	}
}
