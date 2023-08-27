/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaaza <azaaza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 02:17:56 by azaaza            #+#    #+#             */
/*   Updated: 2023/08/27 20:31:46 by azaaza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

static void	move_player_up(t_game *game)
{
	int	p_col;
	int	new_row;

	printf("move player up\n");
	p_col = game->player.col;
	new_row = game->player.row - 1;
	if (game->map.map[new_row][p_col] != '1')
	{
		game->player.row = new_row;
		game->player.moves++;
		game->player.direction = 1;
	}
}
static void	move_player_down(t_game *game)
{
	int	p_col;
	int	new_row;

	printf("move player down\n");
	p_col = game->player.col;
	new_row = game->player.row + 1;
	if (game->map.map[new_row][p_col] == '0'
		|| game->map.map[new_row][p_col] != 'C'
		|| game->map.map[new_row][p_col] != 'E')
	{
		if (game->map.map[new_row][p_col] == 'C')
			handle_collactable(game, new_row, p_col);
		if (game->map.map[new_row][p_col] == 'E')
			handle_exit(game, new_row, p_col);
		game->player.row = new_row;
		game->player.moves++;
	}
	game->player.direction = 3;
}
static void	move_player_right(t_game *game)
{
	int	p_row;
	int	new_col;

	printf("move player right\n");
	p_row = game->player.row;
	new_col = game->player.col + 1;
	if (game->map.map[p_row][new_col] != '1')
	{
		game->player.col = new_col;
		game->player.moves++;
		game->player.direction = 2;
	}
}
static void	move_player_left(t_game *game)
{
	int	p_row;
	int	new_col;

	printf("move player left\n");
	p_row = game->player.row;
	new_col = game->player.col - 1;
	if (game->map.map[p_row][new_col] != '1')
	{
		game->player.col = new_col;
		game->player.moves++;
		game->player.direction = 0;
	}
}

void	handle_move_player(int key, t_game *game)
{
	if (key == 13)
		move_player_up(game);
	else if (key == 0)
		move_player_left(game);
	else if (key == 1)
		move_player_down(game);
	else if (key == 2)
		move_player_right(game);
}
