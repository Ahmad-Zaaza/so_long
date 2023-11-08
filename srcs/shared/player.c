/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmadzaaza <ahmadzaaza@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 01:11:48 by ahmadzaaza        #+#    #+#             */
/*   Updated: 2023/11/08 23:30:23 by ahmadzaaza       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_mandatory.h"

void	init_player(t_game *game)
{
	game->player.collectables_gathered = 0;
	game->player.moves = 0;
	game->player.direction = 3;
	game->player.images[0] = xpm_to_image(&game, "textures/player/left.xpm");
	game->player.images[1] = xpm_to_image(&game, "textures/player/top.xpm");
	game->player.images[2] = xpm_to_image(&game, "textures/player/right.xpm");
	game->player.images[3] = xpm_to_image(&game, "textures/player/bottom.xpm");
}

void	handle_move_player(int key, t_game *game)
{
	if (key == 13)
		move_player(game, game->player.row - 1, game->player.col, 1);
	else if (key == 0)
		move_player(game, game->player.row, game->player.col - 1, 0);
	else if (key == 1)
		move_player(game, game->player.row + 1, game->player.col, 3);
	else if (key == 2)
		move_player(game, game->player.row, game->player.col + 1, 2);
}
