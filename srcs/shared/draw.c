/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmadzaaza <ahmadzaaza@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 17:42:03 by ahmadzaaza        #+#    #+#             */
/*   Updated: 2023/10/30 18:42:54 by ahmadzaaza       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"
#include <time.h>

static void	draw_floor(t_game *game, int row, int col)
{
	mlx_put_image_to_window(game->mlx, game->win, game->tiles.floor, col
		* TILE_SIZE, row * TILE_SIZE);
}

void	draw_wall(t_game *game, int row, int col)
{
	mlx_put_image_to_window(game->mlx, game->win, game->tiles.wall, col
		* TILE_SIZE, (row + 1) * TILE_SIZE);
}

static void	draw_coin(t_game *game, int row, int col)
{
	clock_t	c;

	c = clock();
	draw_floor(game, row + 1, col);
	mlx_put_image_to_window(game->mlx, game->win, game->tiles.collectible[(c
			/ 100000) % 11], col * TILE_SIZE, (row + 1) * TILE_SIZE);
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
				draw_floor(game, row + 1, col);
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
		* TILE_SIZE, (game->player.row + 1) * TILE_SIZE);
}

void	draw_movements(t_game *game)
{
	int	i;
	int	digit;
	int	moves;

	moves = game->player.moves;
	i = 0;
	while (i < 4)
	{
		digit = moves % 10;
		moves /= 10;
		ft_put_font(game, digit, i);
		i++;
	}
}
