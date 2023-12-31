/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_controls.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaaza <azaaza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 02:17:56 by azaaza            #+#    #+#             */
/*   Updated: 2023/11/05 15:26:52 by azaaza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_mandatory.h"

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

static void	handle_exit(t_game *game)
{
	if (game->player.collectables_gathered == game->map.collectibles)
	{
		game->player.moves++;
		ft_printf("Player moves:%d\n", game->player.moves);
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
		handle_collactable(game, row, col);
	else if (game->map.map[row][col] == 'E')
		handle_exit(game);
	game->player.row = row;
	game->player.col = col;
	game->player.moves++;
	game->player.direction = new_direction;
	ft_printf("Player moves:%d\n", game->player.moves);
}
