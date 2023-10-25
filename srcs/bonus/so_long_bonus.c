/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmadzaaza <ahmadzaaza@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 22:31:40 by azaaza            #+#    #+#             */
/*   Updated: 2023/10/26 01:05:14 by ahmadzaaza       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"
#include <time.h>

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
	destroy_fonts(game);
	mlx_destroy_window(game->mlx, game->win);
	exit(0);
	return (0);
}

int	handle_keydown(int key_code, t_game *game)
{
	if (key_code == 53)
		handle_destroy(game);
	else if (key_code == 13 || key_code == 0 || key_code == 1 || key_code == 2)
	{
		handle_move_player(key_code, game);
	}
	return (0);
}

int	render_next_frame(t_game *game)
{
	clock_t	start;
	clock_t	end;
	double	frame_rate;
	double	cpu_time_used;

	start = clock();
	mlx_clear_window(game->mlx, game->win);
	draw_tiles(game);
	draw_player(game);
	draw_movements(game);
	end = clock();
	cpu_time_used = (double)(end - start) / CLOCKS_PER_SEC;
	frame_rate = (double)1 / cpu_time_used;
	game->frame = frame_rate;
	return (1);
}

int	main(int argc, char **argv)
{
	t_game	game;

	// args and map validation
	validate_args(argc, argv, &game);
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, game.map.columns * TILE_SIZE,
			(game.map.rows + 1) * TILE_SIZE, "Baby");
	init_player(&game);
	load_tiles(&game);
	load_fonts(&game);
	mlx_hook(game.win, 2, 0, &handle_keydown, &game);
	mlx_hook(game.win, 17, 0, &handle_destroy, &game);
	mlx_loop_hook(game.mlx, render_next_frame, &game);
	mlx_loop(game.mlx);
	return (0);
}
