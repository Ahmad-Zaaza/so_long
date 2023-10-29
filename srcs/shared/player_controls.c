/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_controls.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmadzaaza <ahmadzaaza@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 02:17:56 by azaaza            #+#    #+#             */
/*   Updated: 2023/10/28 17:49:17 by ahmadzaaza       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

/**
  Once the player steps on a collectable tile, convert the
  tile into a normal tile.
  Increment the collectables gathered.
*/
static void	handle_collactable(t_game *game, int row, int col)
{
	game->map.map[row][col] = '0';
	game->player.collectables_gathered++;
}

static void	handle_exit(t_game *game, int row, int col)
{
	if (game->player.collectables_gathered == game->map.collectibles)
	{
		ft_printf("You win!\n");
		handle_destroy(game);
	}
	else
		ft_printf("You need to collect all collectables before exiting!\n");
}

void	move_player(t_game *game, int row, int col, int new_direction)
{
	if (game->map.map[row][col] == '1')
		return ;
	if (game->map.map[row][col] == 'C')
	{
		handle_collactable(game, row, col);
	}
	else if (game->map.map[row][col] == 'E')
	{
		handle_exit(game, row, col);
	}
	game->player.row = row;
	game->player.col = col;
	game->player.moves++;
	game->player.direction = new_direction;
	ft_printf("Player moves:%d\n", game->player.moves);
}

/**
Move player:

We call this function as a handler for the key listener of movement keys
*/
void	handle_move_player(int key, t_game *game)
{
	int	p_col;
	int	new_row;
	int	p_row;
	int	new_col;

	if (key == 13)
		move_player(game, game->player.row - 1, game->player.col, 1);
	else if (key == 0)
		move_player(game, game->player.row, game->player.col - 1, 0);
	else if (key == 1)
		move_player(game, game->player.row + 1, game->player.col, 3);
	else if (key == 2)
		move_player(game, game->player.row, game->player.col + 1, 2);
}
