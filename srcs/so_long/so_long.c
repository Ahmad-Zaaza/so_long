/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmadzaaza <ahmadzaaza@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 22:31:40 by azaaza            #+#    #+#             */
/*   Updated: 2023/11/02 00:20:59 by ahmadzaaza       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_mandatory.h"

int	handle_destroy(t_game *game)
{
	destroy_tiles(game);
	cleanup_map(game);
	mlx_destroy_window(game->mlx, game->win);
	free(game->mlx);
	exit(0);
	return (0);
}

/**
 key codes:
 53: esc;
 123: left arrow;
 124: right arrow;
 125: down arrow;
 126: up arrow;
 13: w;
 0: a;
 1: s;
 2: d;

*/
int	handle_keydown(int key_code, t_game *game)
{
	if (key_code == 53)
		handle_destroy(game);
	else if (key_code == 13 || key_code == 0 || key_code == 1 || key_code == 2)
		handle_move_player(key_code, game);
	return (0);
}

/**
Row starting from 1 because we need to render the fonts on a black bg
*/
void	draw(t_game *game)
{
	int	col;
	int	row;

	row = 0;
	while (row < game->map.rows)
	{
		col = 0;
		while (col < game->map.columns)
		{
			handle_tiles_draw(game, row, col);
			col++;
		}
		row++;
	}
	draw_player(game);
}

int	render_next_frame(t_game *game)
{
	mlx_clear_window(game->mlx, game->win);
	draw(game);
	return (1);
}

/**
Game entry point.

the game information will be stored inside a struct called `game`.

the game takes a single argument which is the map path that we would read.

A map is a file consists of characters which represent the game elements.

At first: We validate that we have only one argument (map path),
then within the same function we read the map, parse it, then validate
that we have the correct elements.

After that: We start initializing the game information, assets, fonts,
then hook up key listeners and render the assets.

*/
int	main(int argc, char **argv)
{
	t_game	game;

	// args and map validation
	validate_args(argc, argv, &game);
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, game.map.columns * TILE_SIZE,
			game.map.rows * TILE_SIZE, "Baby");
	init_player(&game);
	load_tiles(&game);
	mlx_hook(game.win, KEY_PRESS, 0, &handle_keydown, &game);
	mlx_hook(game.win, DESTROY_NOTIFY, 0, &handle_destroy, &game);
	mlx_loop_hook(game.mlx, render_next_frame, &game);
	mlx_loop(game.mlx);
	return (0);
}
