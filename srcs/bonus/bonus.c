/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmadzaaza <ahmadzaaza@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 22:31:40 by azaaza            #+#    #+#             */
/*   Updated: 2023/11/01 00:20:47 by ahmadzaaza       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

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

int	handle_destroy(t_game *game)
{
	destroy_tiles(game);
	cleanup_map(game);
	mlx_destroy_window(game->mlx, game->win);
	exit(0);
	return (0);
}

int	handle_keydown(int key_code, t_game *game)
{
	if (key_code == 53)
		handle_destroy(game);
	else if (key_code == 13 || key_code == 0 || key_code == 1 || key_code == 2)
		handle_move_player(key_code, game);
	return (0);
}

int	render_next_frame(t_game *game)
{
	mlx_clear_window(game->mlx, game->win);
	draw(game);
	return (1);
}

int	main(int argc, char **argv)
{
	t_game	game;

	// args and map validation
	validate_args(argc, argv, &game);
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, game.map.columns * TILE_SIZE,
			(game.map.rows + 1) * TILE_SIZE, "So Long");
	load_tiles(&game);
	init_player(&game);
	mlx_hook(game.win, 2, 0, &handle_keydown, &game);
	mlx_hook(game.win, 17, 0, &handle_destroy, &game);
	mlx_loop_hook(game.mlx, render_next_frame, &game);
	mlx_loop(game.mlx);
	return (0);
}
