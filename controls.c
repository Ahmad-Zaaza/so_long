/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaaza <azaaza@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 02:17:56 by azaaza            #+#    #+#             */
/*   Updated: 2023/09/10 02:52:56 by azaaza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/include/ft_printf.h"
#include "so_long.h"
#include <stdio.h>

static void handle_collactable(t_game *game, int row, int col) {
  game->map.map[row][col] = '0';
  game->player.collectables_gathered++;
}
static void handle_exit(t_game *game, int row, int col) {
  if (game->player.collectables_gathered == game->map.collectibles) {
    ft_printf("You win!\n");
    handle_destroy(game);
  } else
    ft_printf("You need to collect all collectables before exiting!\n");
}

void move_player(t_game *game, int row, int col, int new_direction) {
  if (game->map.map[row][col] == '1')
    return;
  if (game->map.map[row][col] == 'C') {
    handle_collactable(game, row, col);
  } else if (game->map.map[row][col] == 'E') {
    handle_exit(game, row, col);
  }

  game->player.row = row;
  game->player.col = col;
  game->player.moves++;
  game->player.direction = new_direction;
  ft_printf("Player moves:%d\n", game->player.moves);
}
